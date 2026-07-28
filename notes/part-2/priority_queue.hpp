#ifndef __priority_queue__
#define __priority_queue__

#include "heap.hpp"
#include <vector>

template <typename V, typename C = default_comparison_t<V>>
void priority_dequeue(std::vector<V> &storage, C compare = C{})
{
    assert(storage.size() > 0);
    std::iter_swap(begin(storage), end(storage) - 1);
    storage.pop_back();
    heap_sift_down(CompleteBT<V>{&storage, 0, storage.size()},
                   compare);
}

template <typename V, typename C = default_comparison_t<V>>
void priority_enqueue(std::vector<V> &storage, V value,
                      C compare = C{})
{
    storage.push_back(std::move(value));
    heap_sift_up(
        CompleteBT<V>{&storage, storage.size() - 1, storage.size()},
        compare);
}

#endif /* __priority_queue__ */
