#include <iostream>

#include "queue.hpp"
#include "utils.hpp"

int main(int argc, char **argv)
{
    // Create a queue with space for a few elements
    auto queue = Queue<float>(5);

    // Keep pushing and popping elements from the queue for a while
    // wrapping around the ring buffer
    for (int repetition = 0; repetition < 3; ++repetition) {
        std::cout << "Enqueued";
        for (int i = 0; i < 3; ++i) {
            queue.enqueue(i);
            std::cout << ' ' << i;
        }
        std::cout << '\n';

        std::cout << "Dequeued";
        for (int i = 0; i < 3; ++i) {
            std::cout << ' ' << queue.front();
            queue.dequeue();
        }
        std::cout << '\n';
    }

    return 0;
}
