#include "stack.hpp"
#include "stack_enhanced.hpp" // Put your code in this file
#include <iostream>

int main(int argc, char **argv)
{
    auto stack = StackEnhanced<int>(100);

    stack << 1 << 2 << 3;
    stack.clear();
    stack << 4 << 5 << 6;

    // Dump the stack content
    std::cout << "Stack content:";
    while (!stack.empty()) {
        std::cout << ' ' << stack.top();
        stack.pop();
    }
    std::cout << '\n';

    return 0;
}
