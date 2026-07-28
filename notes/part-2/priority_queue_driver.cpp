#include "priority_queue.hpp"
#include <utils.hpp>

#include <iostream>

int main(int argc, char **argv)
{
    std::vector<int> queue;

    for (int x : {15, 9, 3, 23}) {
        std::cout << "Enqueued " << x << ' ';
        priority_enqueue(queue, x);
        print(queue);
    }

    std::cout << "Dequeued " << queue[0] << ' ';
    priority_dequeue(queue);
    print(queue);

    std::cout << "Dequeued " << queue[0] << ' ';
    priority_dequeue(queue);
    print(queue);

    for (int x : {2, 1}) {
        std::cout << "Enqueued " << x << ' ';
        priority_enqueue(queue, x);
        print(queue);
    }

    while (!queue.empty()) {
        std::cout << "Dequeued " << queue[0] << ' ';
        priority_dequeue(queue);
        print(queue);
    }

    return 0;
}
