#include "shortest_paths_dijkstra_sparse.hpp"
#include <priority_queue.hpp>

#include <cassert>
#include <cmath>

struct triplet_t {
    float d;
    int r;
    int v;
};

std::vector<hop_t> dijkstra(const SparseGraph &graph, const int source)
{
    assert(source >= 0);
    assert(source < (signed)graph.size());

    auto DP = std::vector<hop_t>(graph.size(), {inf, -1});

    // WRITE YOUR CODE HERE
    auto compare = [](const triplet_t &lhs, const triplet_t &rhs) {
        return lhs.d < rhs.d;
    };

    auto queue = std::vector<triplet_t>{};
    priority_enqueue(queue, {0, source, source}, compare);

    while (!queue.empty()) {
        auto triplet = queue[0];
        priority_dequeue(queue, compare);

        if (DP[triplet.v].weight <= triplet.d) {
            continue;
        }

        DP[triplet.v] = {triplet.d, triplet.r};

        for (const auto &edge : graph[triplet.v]) {
            auto d = triplet.d + edge.weight;
            if (!std::isfinite(d)) {
                continue;
            }
            priority_enqueue(queue, {d, triplet.v, edge.vertex}, compare);
        }
    }
    // YOUR CODE ENDS HERE

    return DP;
}
