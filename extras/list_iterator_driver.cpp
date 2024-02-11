#include <iostream>

#include "list.hpp"
#include "list_iterator.hpp"
#include "utils.hpp"

int main(int argc, char** argv)
{
    auto list = Node<float>{};

    // Insert some numbers in the list
    for (int i = 0; i < 10; ++i) {
        list_insert_after(&list, static_cast<float>(i));
    }

    // Traverse the list using a const iterator
    for (auto iter = cbegin(list); iter != cend(list); ++iter) {
        std::cout << *iter << ' ';
    }
    std::cout << std::endl;

    // Traverse the list using a range for loop
    for (const auto& x : list) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    // Traverse the list using our own `print` helper function from
    // `utils.hpp`
    print(list, "List content: ");

    return 0;
}
