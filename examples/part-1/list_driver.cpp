#include "list.hpp"
#include "utils.hpp"

int main(int argc, char **argv)
{
    auto list = Node<float>{};

    // Insert some numbers in the list
    for (int i = 0; i < 10; ++i) {
        list_insert_after(&list, static_cast<float>(i));
    }

    // Print the list
    print(list_to_vector(list));

    return 0;
}
