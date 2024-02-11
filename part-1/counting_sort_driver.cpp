#include "utils.hpp"
#include <vector>

void counting_sort(std::vector<int> &A, size_t k)
{
    auto counts = std::vector<size_t>(k, 0);
    size_t i = 0;
    size_t j = 0;
    for (auto j : A) ++counts[j];
    while (j < k) {
        if (counts[j] == 0) {
            ++j;
            continue;
        }
        A[i++] = static_cast<int>(j);
        --counts[j];
    }
}

int main(int argc, char **argv)
{
    auto A = std::vector<int>{5, 3, 0, 1, 5, 3};
    print(A, "Before sorting: ");
    counting_sort(A, 6);
    print(A, "After sorting: ");
    return 0;
}
