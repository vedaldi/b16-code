#include "array.hpp"
#include "utils.hpp"

int main(int argc, char **argv)
{
    auto A = std::vector<float>{};
    print(A, "Array before inserting any elment = ");
    for (size_t i = 0; i < 5; ++i) {
        array_insert(A, 0, static_cast<float>(i));
        print(A, "Array after inserting " + std::to_string(i) +
                     " at position 0 = ");
    }
    return 0;
}
