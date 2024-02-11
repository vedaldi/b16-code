#include "binary_search_tree.hpp"
#include "binary_tree_print.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    std::unique_ptr<BinaryTree<int>> bt;

    for (int x : {12, 5, 18, 2, 9, 15, 19, 13, 17}) {
        bt = bst_insert(std::move(bt), x);
        std::cout << "Tree after inserting " << x << ":\n";
        print_binary_tree(bt.get());
        std::cout << "\n";
    }

    for (int x : {0, 5, 6, 18, 19, 20}) {
        BinaryTree<int> *result = bst_search(bt.get(), x);
        std::cout << "The largest element not exceeding " << x
                  << " is ";
        std::cout << (result ? std::to_string(value(result))
                             : "none");
        std::cout << "\n";
    }

    return 0;
}
