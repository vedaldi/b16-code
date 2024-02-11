#ifndef __merge_sort__
#define __merge_sort__

#include <iterator>
#include <vector>

template <typename I>
std::vector<typename std::iterator_traits<I>::value_type>
merge(const I &begin, const I &middle, const I &end)
{
    using T = typename std::iterator_traits<I>::value_type;
    auto merged = std::vector<T>{};
    merged.reserve(end - begin);
    auto i = begin;
    auto j = middle;
    while (i != middle && j != end) {
        if (*i <= *j) {
            merged.push_back(*i++);
        } else {
            merged.push_back(*j++);
        }
    }
    while (i != middle) merged.push_back(*i++);
    while (j != end) merged.push_back(*j++);
    return merged;
}

template <typename I> void merge_sort(const I &begin, const I &end)
{
    if (end - begin <= 1) { return; }
    auto middle = std::distance(begin, end) / 2 + begin;
    merge_sort(begin, middle);
    merge_sort(middle, end);
    auto sorted = merge(begin, middle, end);
    std::move(sorted.begin(), sorted.end(), begin);
}

#endif // __merge_sort__