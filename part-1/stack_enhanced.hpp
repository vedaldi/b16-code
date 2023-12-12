#ifndef __stack_enhanced___
#define __stack_enhanced___

#include "stack.hpp"

template <typename T> class StackEnhanced : public Stack<T>
{
  public:
    // Inherit the Stack<T> constructors as they are
    // https://en.cppreference.com/w/cpp/language/using_declaration
    using Stack<T>::Stack;

    void clear()
    {
        // WRITE YOUR CODE HERE
        // Since _head is a member variable of Stack<T>,
        // this->_head looks like redundant notation. It is required
        // here because the base class Stack<T> is a template:
        // https://isocpp.org/wiki/faq/templates#nondependent-name-lookup-members
        this->_head = 0;
        // YOUR CODE ENDS HERE
    }
};

template <typename T>
StackEnhanced<T> &operator<<(StackEnhanced<T> &stack, const T &value)
{
    // WRITE YOUR CODE HERE
    stack.push(value);
    return stack;
    // YOUR CODE ENDS HERE
}

#endif // __stack_enhanced___