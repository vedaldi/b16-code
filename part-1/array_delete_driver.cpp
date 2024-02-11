#include "array.hpp"
#include "array_delete.hpp"
#include "utils.hpp"

int main(int argc, char **argv)
{
    auto A = std::vector<float>{0, 1, 2, 3, 4};
    print(A, "Initially A = ");
    while (!A.empty()) {
        array_delete(A, 0);
        print(A, "After deleting the element at position 0: A = ");
    }
    return 0;
}