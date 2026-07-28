#ifndef __binary_search_tree__
#define __binary_search_tree__

#include "binary_tree.hpp"

template <class T, typename V> T bst_search(const T &tree, const V &v)
{
    if (!tree || v == value(tree)) return tree;
    if (v < value(tree)) return bst_search(left(tree), v);
    auto other = bst_search(right(tree), v);
    return other ? other : tree;
}

template <typename V>
std::unique_ptr<BinaryTree<V>>
bst_insert(std::unique_ptr<BinaryTree<V>> tree, const V &v)
{
    if (!tree) return make_binary_tree(v, {}, {});
    if (v <= value(tree.get())) {
        tree->_left = bst_insert(std::move(tree->_left), v);
    } else {
        tree->_right = bst_insert(std::move(tree->_right), v);
    }
    return tree;
}

#endif // __binary_search_tree__
