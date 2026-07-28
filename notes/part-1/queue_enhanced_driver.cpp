#include "queue_enhanced.hpp"
#include "utils.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    // Create a queue with space for a few elements
    auto queue = Dequeue<float>(5);

    // Keep pushing and popping elements from the dequeue for a while
    for (int repetition = 0; repetition < 3; ++repetition) {
        std::cout << "Enqueued front";
        for (int i = 0; i < 3; ++i) {
            queue.enqueue_front(i);
            std::cout << ' ' << i;
        }
        std::cout << "\nDequeued front";
        for (int i = 0; i < 3; ++i) {
            std::cout << ' ' << queue.front();
            queue.dequeue();
        }
        std::cout << "\nEnqueued back";
        for (int i = 0; i < 3; ++i) {
            queue.enqueue(i);
            std::cout << ' ' << i;
        }
        std::cout << "\nDequeued back";
        for (int i = 0; i < 3; ++i) {
            std::cout << ' ' << queue.back();
            queue.dequeue_back();
        }
        std::cout << '\n';
    }

    return 0;
}
