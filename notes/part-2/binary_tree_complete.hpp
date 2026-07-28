#ifndef __binary_tree_complete__
#define __binary_tree_complete__

#include <cstddef>
#include <limits>
#include <vector>

// Wraps a vector in a complete binary tree
template <typename V> struct CompleteBT {
    std::vector<V> *_storage;
    std::size_t _root;
    std::size_t _size;

    CompleteBT<V>(std::vector<V> *storage)
        : _storage{storage}, _root{0}, _size{storage->size()}
    {
    }

    CompleteBT<V>(std::vector<V> *storage, std::size_t root,
                  std::size_t size)
        : _storage{storage}, _root{root}, _size{size}
    {
    }

    CompleteBT<V> subtree(std::size_t root) const
    {
        return CompleteBT<V>{_storage, root, _size};
    }

    friend V &value(CompleteBT &t) { return (*t._storage)[t._root]; }
    friend const V &value(const CompleteBT &t)
    {
        return (*t._storage)[t._root];
    }
    friend CompleteBT parent(const CompleteBT &t)
    {
        if (t._root == 0)
            return t.subtree(std::numeric_limits<std::size_t>::max());
        return t.subtree((t._root - 1) / 2);
    }
    friend CompleteBT left(const CompleteBT &t)
    {
        return t.subtree(2 * t._root + 1);
    }
    friend CompleteBT right(const CompleteBT &t)
    {
        return t.subtree(2 * t._root + 2);
    }

    explicit operator bool() const
    {
        return _root < _size;
    } // not empty
};

#endif // __binary_tree_complete__