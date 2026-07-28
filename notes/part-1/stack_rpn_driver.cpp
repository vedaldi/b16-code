#include <iostream>

#include "stack.hpp"
#include "stack_rpn.hpp" // Put your code in this file

int main(int argc, char **argv)
{
    // Basic interface
    auto stack = Stack<int>(100);
    stack.push(2);
    stack.push(2);
    stack.push(3);
    plus(stack);
    multiplies(stack);
    std::cout << "2 2 3 + * = " << stack.top() << '\n';

    // Advanced interface (optional)
    stack << 2 << 2 << 3 << plus << multiplies;
    std::cout << "2 2 3 + * = " << stack.top() << '\n';

    return 0;
}
