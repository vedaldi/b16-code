#include "binary_tree.hpp"
#include "binary_tree_traversal.hpp"
#include "binary_tree_print.hpp"

int main(int argc, char** argv)
{
    auto bt = make_binary_tree(1.0f,
      make_binary_tree(2.0f,
        make_binary_tree(4.0f, {}, {}),
        make_binary_tree(5.0f, {},
          make_binary_tree(8.0f, {}, {})
        )
      ),
      make_binary_tree(3.0f,
        make_binary_tree(6.0f, {}, {}),
        make_binary_tree(7.0f, {}, {})
      ));

    std::cout << "Tree:\n";
    print_binary_tree(bt.get());

    auto action = [](const auto& tree) {
        std::cout << "Visited subtree: " << value(tree) << '\n';
    };

    std::cout << "\nDepth-first traversal (DFT)\n";
    df_traversal(bt.get(), action);

    std::cout << "\nBreadth-first traversal (BFT)\n";
    bf_traversal(bt.get(), action);

    return 0;
}
