#include <iostream>

#include "binary_search_tree_enhanced.hpp"
#include "binary_tree_print.hpp"

int main(int argc, char **argv)
{
    std::unique_ptr<BinaryTree<int>> bt;

    for (int x : {12, 5, 18, 2, 9, 15, 19, 13, 17}) {
        bt = bst_insert(std::move(bt), x);
    }

    std::cout << "Tree:";
    print_binary_tree(bt.get());
    std::cout << "\n";

    std::cout << "The smallest element is "
              << value(bst_min(bt.get())) << '\n';

    std::cout << "The largest element is " << value(bst_max(bt.get()))
              << '\n';

    return 0;
}