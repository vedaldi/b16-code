#ifndef __insertion_sort__
#define __insertion_sort__

#include <cassert> // for assert
#include <cstddef> // for std::size_t
#include <utility> // for std::swap
#include <vector>  // for std::vector

template <typename T> void insert(std::vector<T> &A, std::size_t i)
{
    assert(i < A.size());
    for (std::size_t j = i; j >= 1; --j) {
        if (A[j - 1] <= A[j]) return;
        std::swap(A[j - 1], A[j]);
    }
}

template <typename T> void insertion_sort(std::vector<T> &A)
{
    for (size_t i = 1; i < A.size(); ++i) {
        insert(A, i);
    }
}

#endif // __insertion_sort__