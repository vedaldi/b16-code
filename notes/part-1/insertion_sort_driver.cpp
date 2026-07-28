#include "insertion_sort.hpp"
#include "utils.hpp" // for print

int main(int argc, char **argv)
{
    auto v = std::vector<float>{3, 1, 0, 18, 7};
    print(v, "Before sorting: ");
    insertion_sort(v);
    print(v, "After sorting: ");
}