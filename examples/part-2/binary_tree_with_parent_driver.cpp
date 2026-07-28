#include "binary_tree_with_parent.hpp"
#include "binary_tree_print.hpp"
#include "binary_tree_traversal.hpp"

int main(int argc, char **argv)
{
    auto bt = make_binary_tree_with_parent(
        1.0f,
        make_binary_tree_with_parent(
            2.0f, make_binary_tree_with_parent(4.0f, {}, {}),
            make_binary_tree_with_parent(
                5.0f, {}, make_binary_tree_with_parent(8.0f, {}, {}))),
        make_binary_tree_with_parent(
            3.0f, make_binary_tree_with_parent(6.0f, {}, {}),
            make_binary_tree_with_parent(7.0f, {}, {})));

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
