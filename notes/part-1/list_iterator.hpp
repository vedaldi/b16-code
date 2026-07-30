#ifndef __list_iterator__
#define __list_iterator__

#include "list.hpp"
#include <type_traits>

// A template for const and non-const iterators.s
template <typename T, bool is_const>
struct NodeIteratorBase {
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = std::conditional_t<is_const, const T*, T*>;
    using reference = std::conditional_t<is_const, const T&, T&>;
    using self_type = NodeIteratorBase<T, is_const>;
    using node_pointer = std::conditional_t<is_const, const Node<T>*, Node<T>*>;

    NodeIteratorBase(node_pointer node) : node{node} { ++(*this); }

    reference operator*() const { return node->value; }
    pointer operator->() { return &node->value; }
    self_type& operator++()
    {
        if (node) {
            node = node->next.get();
        }
        return *this;
    }
    self_type operator++(int)
    {
        auto tmp = *this;
        ++(*this);
        return tmp;
    }
    friend bool operator==(const self_type& a, const self_type& b) { return a.node == b.node; };
    friend bool operator!=(const self_type& a, const self_type& b) { return a.node != b.node; };

    private:
    node_pointer node;
};

template <typename T> using NodeIterator = NodeIteratorBase<T, false>;
template <typename T> using NodeConstIterator = NodeIteratorBase<T, true>;

template <typename T> NodeIterator<T> begin(Node<T>& list) { return &list; }
template <typename T> NodeIterator<T> end(Node<T>& list) { return nullptr; }
template <typename T> NodeConstIterator<T> begin(const Node<T>& list) { return &list; }
template <typename T> NodeConstIterator<T> end(const Node<T>& list) { return nullptr; }
template <typename T> NodeConstIterator<T> cbegin(const Node<T>& list) { return &list; }
template <typename T> NodeConstIterator<T> cend(const Node<T>& list) { return nullptr; }

#endif