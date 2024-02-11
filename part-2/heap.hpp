#ifndef __heap__
#define __heap__

#include <cassert>
#include <cstdint>
#include <functional>
#include <utility>
#include <vector>

#include "binary_tree_complete.hpp"

template <typename V> using default_comparison_t = std::greater<V>;

template <typename T, typename C> void heap_sift_up(T &&tree, C compare)
{
    auto p = parent(tree);
    if (!p) return;
    if (compare(value(tree), value(p))) std::swap(value(tree), value(p));
    heap_sift_up(p, compare);
}

template <typename T, typename C> void heap_sift_down(T &&tree, C compare)
{
    auto child = left(tree);
    auto other = right(tree);
    if (!child || (other && compare(value(other), value(child)))) {
        child = other;
    }
    if (!child) return;
    if (compare(value(child), value(tree))) {
        std::swap(value(child), value(tree));
    }
    heap_sift_down(child, compare);
}

template <typename V, typename C = default_comparison_t<V>>
void build_heap(std::vector<V> &storage, C compare = C{})
{
    for (std::intmax_t i = (signed)storage.size() / 2 - 1; i >= 0; --i) {
        heap_sift_down(CompleteBT<V>{&storage, (size_t)i, storage.size()},
                       compare);
    }
}

template <typename V, typename C = default_comparison_t<V>>
void heap_sort(std::vector<V> &storage, C compare = C{})
{
    build_heap(storage, compare);
    for (size_t back = storage.size() - 1; back >= 1; --back) {
        std::swap(storage[0], storage[back]);
        heap_sift_down(CompleteBT<V>{&storage, 0, back}, compare);
    }
}

#endif /* __heap__ */
