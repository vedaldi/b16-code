#ifndef __binary_tree_with_parent__
#define __binary_tree_with_parent__

#include <cassert>
#include <vector>
#include <memory>

// A class representing a binary tree
template <typename V> struct BinaryTreeWithParent {
    V _value;
    std::unique_ptr<BinaryTreeWithParent<V>> _left;
    std::unique_ptr<BinaryTreeWithParent<V>> _right;

    // WRITE YOUR CODE HERE

    friend V &value(BinaryTreeWithParent *t) { return t->_value; }
    friend const V &value(const BinaryTreeWithParent *t)
    {
        return t->_value;
    }
    friend BinaryTreeWithParent *left(const BinaryTreeWithParent *t)
    {
        return t->_left.get();
    }
    friend BinaryTreeWithParent *right(const BinaryTreeWithParent *t)
    {
        return t->_right.get();
    }
    friend BinaryTreeWithParent *parent(const BinaryTreeWithParent *t)
    {
        // WRITE YOUR CODE HERE
    }
};

// A helper function to build an enhanced binary tree
template <typename V>
std::unique_ptr<BinaryTreeWithParent<V>>
make_binary_tree_with_parent(const V &value,
                          std::unique_ptr<BinaryTreeWithParent<V>> l,
                          std::unique_ptr<BinaryTreeWithParent<V>> r)
{
    // WRITE YOUR CODE HERE
}

#endif // __binary_tree_with_parent__