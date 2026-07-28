#include "binary_tree.hpp"
#include "binary_tree_print.hpp"
#include "heap.hpp"
#include <utils.hpp>

#include <iostream>
#include <vector>

int main(int argc, const char *argv[])
{
    auto array =
        std::vector<float>{1,  19, 2,  9,  12, 18, 4, 8, 5,  6,
                           17, 10, 11, 14, 16, 15, 7, 3, 13, 20};

    std::cout << "Before building the heap: ";
    print(array);
    print_binary_tree(CompleteBT<float>{&array});

    build_heap(array);

    std::cout << "\nAfter building the heap: ";
    print(array);
    print_binary_tree(CompleteBT<float>{&array});

    heap_sort(array);
    print(array, "\nArray after heapsort: ");

    return 0;
}
