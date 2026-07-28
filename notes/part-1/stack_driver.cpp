#include "stack.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    // Create a stack with space for 10 elements
    auto stack = Stack<float>(10);

    // Push some numbers on the stack
    std::cout << "Pushing";
    for (int i = 0; i < 5; ++i) {
        stack.push(i);
        std::cout << ' ' << i;
    }
    std::cout << '\n';

    // Pop the numbers from the stack
    std::cout << "Popping";
    while (!stack.empty()) {
        std::cout << ' ' << stack.top();
        stack.pop();
    }
    std::cout << '\n';

    return 0;
}
