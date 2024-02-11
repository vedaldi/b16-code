#include "binary_tree_complete.hpp"
#include "binary_tree_print.hpp"
#include "binary_tree_traversal.hpp"
#include <utils.hpp>

#include <vector>

int main(int argc, char **argv)
{
    auto array = std::vector<float>{1, 2, 3, 4, 5, 6, 7, 8};
    auto bt = CompleteBT<float>{&array};

    std::cout << "Tree:\n";
    print_binary_tree(bt);

    auto action = [](const auto &tree) {
        std::cout << "Visited subtree: " << value(tree) << '\n';
    };

    std::cout << "\nDepth-first traversal (DFT)\n";
    df_traversal(bt, action);

    std::cout << "\nBreadth-first traversal (BFT)\n";
    bf_traversal(bt, action);

    return 0;
}