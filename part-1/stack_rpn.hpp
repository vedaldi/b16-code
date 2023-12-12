#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"
#include <cassert>
#include <functional>

// WRITE YOUR CODE HERE

template <typename T, typename B>
void apply_unary(Stack<T> &stack, B unary_operation)
{
    auto arg = stack.top();
    stack.pop();
    stack.push(unary_operation(arg));
}

template <typename T, typename B>
void apply_binary(Stack<T> &stack, B binary_operation)
{
    auto lhs = stack.top();
    stack.pop();
    auto rhs = stack.top();
    stack.pop();
    stack.push(binary_operation(lhs, rhs));
}

template <typename T> void plus(Stack<T> &stack)
{
    apply_binary(stack, std::plus<T>{});
}
template <typename T> void minus(Stack<T> &stack)
{
    apply_binary(stack, std::minus<T>{});
}
template <typename T> void divides(Stack<T> &stack)
{
    apply_binary(stack, std::divides<T>{});
}
template <typename T> void multiplies(Stack<T> &stack)
{
    apply_binary(stack, std::multiplies<T>{});
}
template <typename T> void negate(Stack<T> &stack)
{
    apply_unary(stack, std::negate<T>{});
}

// Advanced interface (optional)

template <typename T>
Stack<T> &operator<<(Stack<T> &stack, const T &x)
{
    stack.push(x);
    return stack;
}

template <typename T>
Stack<T> &operator<<(Stack<T> &stack, void (*op)(Stack<T> &))
{
    op(stack);
    return stack;
}

// YOUR CODE ENDS HERE

#endif // __stack_rpn__