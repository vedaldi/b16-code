#include "merge_sort.hpp"
#include "utils.hpp"

int main(int argc, const char *argv[])
{
    auto v = std::vector<float>{1,  19, 2,  9,  12, 18, 4, 8, 5,  6,
                                17, 10, 11, 14, 16, 15, 7, 3, 13, 20};
    print(v, "Before merge sort: ");
    merge_sort(v.begin(), v.end());
    print(v, "After merge sort: ");
    return 0;
}
