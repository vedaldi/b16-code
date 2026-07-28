#ifndef __binary_tree_traversal__
#define __binary_tree_traversal__

#include <queue>

// Compute the height of a tree
template <typename T> int height(const T &tree)
{
    if (empty(tree)) return -1;
    return 1 + std::max(height(left(tree)), height(right(tree)));
}

// Depth first traversal (in order)
template <class T, typename F>
void df_traversal(const T &tree, F action)
{
    if (!tree) return;
    df_traversal(left(tree), action);
    action(tree);
    df_traversal(right(tree), action);
}

// Breadth first traversal
template <class T, typename F>
void bf_traversal(const T &tree, F action)
{
    auto queue = std::queue<T>{};
    queue.push(tree);
    while (!queue.empty()) {
        auto &current = queue.front();
        if (current) {
            action(current);
            queue.push(left(current));  // enqueue
            queue.push(right(current)); // enqueue
        }
        queue.pop(); // dequeue
    }
}

#endif // __binary_tree_traversal__