#include "binary_tree_enhanced.hpp"
#include "binary_tree_print.hpp"
#include "binary_tree_traversal.hpp"

int main(int argc, char **argv)
{
    auto bt = make_binary_tree_enhanced(
        1.0f,
        make_binary_tree_enhanced(
            2.0f, make_binary_tree_enhanced(4.0f, {}, {}),
            make_binary_tree_enhanced(
                5.0f, {}, make_binary_tree_enhanced(8.0f, {}, {}))),
        make_binary_tree_enhanced(
            3.0f, make_binary_tree_enhanced(6.0f, {}, {}),
            make_binary_tree_enhanced(7.0f, {}, {})));

    std::cout << "Tree:\n";
    print_binary_tree(bt.get());

    auto action = [](const auto &tree) {
        auto p = parent(tree);
        if (p) {
            std::cout << "The parent of " << value(tree) << " is "
                      << value(p) << '\n';
        } else {
            std::cout << "Node " << value(tree) << " has no parent\n";
        }
    };

    df_traversal(bt.get(), action);

    return 0;
}
