#include <hash.hpp>
#include <utils.hpp>

#include <array>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <type_traits>
#include <vector>

constexpr size_t data_dim = 3;
constexpr size_t dataset_size = 10'000;
constexpr size_t queryset_size = 1'000;

using data_t = std::array<double, data_dim>; // keys and queries
using code_t = uint32_t; // codes for the keys, output by the LSH functions

constexpr auto inf =
    std::numeric_limits<data_t::value_type>::infinity(); // shorthand
constexpr auto random_seed = 0;                          // for reproducibility

// Sample a vector on the unit hypersphere.
data_t sample_unit_vector()
{
    static std::mt19937 gen{random_seed};
    static std::normal_distribution<> normal{0, 1};
    data_t vec{};
    data_t::value_type norm2 = 0;
    for (auto &x : vec) {
        x = normal(gen);
        norm2 += x * x;
    }
    data_t::value_type norm = sqrt(norm2);
    for (auto &x : vec) {
        x /= norm;
    }
    return vec;
}

// Sample a collection of unit vectors.
std::vector<data_t> sample_dataset(size_t num_data)
{
    std::vector<data_t> dataset;
    dataset.reserve(num_data);
    while (num_data--) {
        dataset.emplace_back(sample_unit_vector());
    }
    return dataset;
}

// Cosine distance function between vectors (must be non-zero).
data_t::value_type cosine_distance(const data_t &vec1, const data_t &vec2)
{
    data_t::value_type xnorm2 = 0;
    data_t::value_type ynorm2 = 0;
    data_t::value_type dot = 0;
    auto xi = std::begin(vec1);
    auto yi = std::begin(vec2);
    while (xi != std::end(vec1)) {
        auto x = *xi++;
        auto y = *yi++;
        xnorm2 += x * x;
        ynorm2 += y * y;
        dot += x * y;
    }
    auto den = sqrt(xnorm2 * ynorm2);
    return 1 - dot / den;
}

// A LSH function maps data_t (keys) to code_t (codes)
using lsh_function_t = std::function<code_t(const data_t &)>;

// Sample a binary LSH function of the type f(x) = sign(<w, x>).
lsh_function_t sample_lsh_function()
{
    auto weights = sample_unit_vector();
    return [=](const data_t &vec) -> code_t {
        data_t::value_type dot = 0;
        auto wi = std::begin(weights);
        auto xi = std::begin(vec);
        while (wi != std::end(weights)) {
            dot += (*wi++) * (*xi++);
        }
        return dot >= 0 ? 1 : 0;
    };
}

// Sample a LSH function of the type F(x) = [f1(x), f2(x), ...,
// fr(x)]. The pattern must fit in an integer of type `code_t`.
lsh_function_t sample_amplified_lsh_function(size_t r)
{
    assert(1 <= r && r <= std::numeric_limits<code_t>::digits);
    std::vector<lsh_function_t> functions;
    while (r--) {
        functions.push_back(sample_lsh_function());
    }

    return [=](const data_t &vec) -> code_t {
        code_t code = 0;
        for (const auto &function : functions) {
            code = (code << 1) | function(vec);
        }
        return code;
    };
}

// A class representinig a LSH family.
struct lsh_family_t {
    size_t amplification;

    // Return a function sampled from the LSH faimly.
    lsh_function_t operator()() const
    {
        return sample_amplified_lsh_function(amplification);
    }
};

// A policy specifynig a hash function mappnig codes to slots.
struct hash_policy_t {
    int operator()(code_t code) const { return code; }
};

// A policy specifynig a distance function between data points.
struct distance_policy_t {
    using value_type = data_t::value_type;
    value_type operator()(const data_t &vec1, const data_t &vec2)
    {
        return cosine_distance(vec1, vec2);
    }
};

// The LSH table class.
template <class K, class D, class G, class H> class LSHTable
{
  public:
    // A retrieval result: distance, key and number of key-query comparisons
    // performed.
    struct result_t {
        typename D::value_type distance;
        const K *key;
        size_t num_comparisons;
    };

    // Create a LSH table using `num_tables` hash tables, each using
    // `num_chains` chains. Data are addedd to the hash table encooded via
    // functions sampled from the `lsh_family`.
    template <class GF>
    LSHTable(size_t num_chains, size_t num_tables, GF lsh_family)
    {
        while (num_tables--) {
            tables.push_back(H{num_chains});
            functions.push_back(lsh_family());
        }
    }

    // Add a key to the LSH table.
    void insert(const K &key)
    {
        for (size_t i = 0; i < tables.size(); ++i) {
            auto code = functions[i](key);
            auto *retrieved = tables[i].get(code);
            if (retrieved == nullptr) {
                tables[i].insert(code, {key});
            } else {
                retrieved->push_back(key);
            }
        }
    }

    // Search for a key within a distance `tau` of the `query`.
    // At most `m` key-query comparisons are performed, after which the serach
    // stops, returning the closetst match found even if the distance is still
    // larger than `tau`. If no matchnig key can be found
    // at all, the search stops with a distance equal to infinity.
    // Setting `tau` to zero can be used to find the closest key to the query
    // found in the alloted number of comparisons.
    result_t get(const K &query, int m = 1, data_t::value_type tau = 0)
    {
        auto result = result_t{inf, nullptr, 0};
        auto distance_function = D{};
        for (size_t i = 0; i < tables.size(); ++i) {
            auto code = functions[i](query);
            auto *retrieved = tables[i].get(code);
            if (retrieved == nullptr) {
                continue;
            }
            for (const auto &key : *retrieved) {
                auto distance = distance_function(key, query);
                if (distance < result.distance) {
                    result.distance = distance;
                    result.key = &key;
                }
                if (++result.num_comparisons >= (unsigned)m) {
                    goto give_up;
                }
                if (result.distance <= tau) {
                    break;
                }
            }
        }
    give_up:
        return result;
    }

  private:
    std::vector<H> tables;
    std::vector<G> functions;
};

// Concrete instantiation of a LSH table and corresponding hash table.
using hash_table_t = HashTable<code_t, std::vector<data_t>, hash_policy_t>;

using lsh_table_t =
    LSHTable<data_t, distance_policy_t, lsh_function_t, hash_table_t>;

using result_t = lsh_table_t::result_t;

// Linear search through the dataset.
template <class D>
result_t naive_retrieve(const std::vector<data_t> &dataset, const data_t &query)
{
    auto result = result_t{inf, nullptr, 1};
    D distance_function{};
    for (const auto &key : dataset) {
        data_t::value_type distance = distance_function(key, query);
        result.num_comparisons++;
        if (distance < result.distance) {
            result.distance = distance;
            result.key = &key;
        }
    }
    return result;
}

// Benchmkar a retrieval function `get`.
template <typename F>
std::tuple<double, double, double> benchmark(const std::vector<data_t> &queries,
                                             F get)
{
    double d = 0;
    double d2 = 0;
    size_t n = 0;
    size_t nok = 0;
    for (const auto &query : queries) {
        auto distance = get(query);
        if (std::isfinite(distance)) {
            d += distance;
            d2 += distance * distance;
            nok += 1;
        }
        n += 1;
    }
    double mean = d / nok;
    double variance = d2 / nok - mean * mean;
    return {mean, variance, (double)nok / n};
}

int main(int argc, char **argv)
{
    auto dataset = sample_dataset(dataset_size);
    auto queries = sample_dataset(queryset_size);

// clang-format off
#define print_result(nt, nc, r, sp, mean, stddev, rate, rel) \
    std::cout \
    << "| "    << std::setw(7)  << std::left << nt \
    << " | "   << std::setw(7)  << std::left << nc \
    << " | "   << std::setw(7)  << std::left << r \
    << " | "   << std::setw(10) << std::setprecision(3) << std::left << std::defaultfloat << mean \
    << " "     << std::setw(10) << std::setprecision(3) << std::left << std::defaultfloat << stddev \
    << " | "   << std::setw(7)  << std::setprecision(1) << std::left << std::defaultfloat << sp \
    << " | "   << std::setw(6)  << std::setprecision(1) << std::fixed << std::right << rate \
    << " | "   << std::setw(6)  << std::setprecision(1) << std::fixed << std::right << rel \
    << "|"     << std::endl;
// clang-format oon

    print_result("#tables", "#comp.", "amplif.", "speedup", "distance", "(stddev)", "succ.", "rel d.");
    print_result("-", "-", "-", "-", "-", "", "-", "-");

    // Baseline: scan all keys.
    double best;
    {
        auto result = benchmark(queries, [&](const data_t &query) -> double {
            return naive_retrieve<distance_policy_t>(dataset, query).distance;
        });
        print_result("-", dataset_size, "-", 1, std::get<0>(result),
                     std::get<1>(result) / sqrt(queryset_size),
                     std::get<2>(result), 1);
        best = std::get<0>(result);
    }

    // LSH tables.
    for (size_t num_comparisons : {1, 10, 100, 1000}) {
        for (size_t num_tables : {1, 2, 3}) {
            for (size_t amplification : {1, 4, 8, 16, 32}) {

                // Build the LSH table.
                size_t num_chains = std::min(1UL << amplification, 256UL);
                lsh_table_t lsh_table{num_chains, num_tables,
                                      lsh_family_t{amplification}};
                for (const auto &key : dataset) {
                    lsh_table.insert(key);
                }

                // Query the LSH table.
                auto result =
                    benchmark(queries, [&](const data_t &query) -> double {
                        return lsh_table.get(query, num_comparisons, 0)
                            .distance;
                    });

                print_result(
                    num_tables, num_comparisons, amplification,
                    (double)dataset_size / num_comparisons, std::get<0>(result),
                    std::get<1>(result) / sqrt(queryset_size),
                    std::get<2>(result) * 100, std::get<0>(result) / best);
            }
        }
    }

    return 0;
}