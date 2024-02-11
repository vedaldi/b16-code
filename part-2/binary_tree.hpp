#ifndef __binary_tree__
#define __binary_tree__

#include <memory>
#include <utility>

// A class representing a binary tree
template <typename V> struct BinaryTree {
    V _value;
    std::unique_ptr<BinaryTree<V>> _left;
    std::unique_ptr<BinaryTree<V>> _right;

    // These are global functions because of `friend`
    friend V &value(BinaryTree *t) { return t->_value; }
    friend const V &value(const BinaryTree *t) { return t->_value; }
    friend BinaryTree *left(BinaryTree *t) { return t->_left.get(); }
    friend BinaryTree *right(BinaryTree *t)
    {
        return t->_right.get();
    }
};

// A helper function to build a binary tree
template <typename V>
std::unique_ptr<BinaryTree<V>>
make_binary_tree(const V &value, std::unique_ptr<BinaryTree<V>> left,
                 std::unique_ptr<BinaryTree<V>> right)
{
    return std::unique_ptr<BinaryTree<V>>{
        new BinaryTree<V>{value, std::move(left), std::move(right)}};
}

#endif // __binary_tree__