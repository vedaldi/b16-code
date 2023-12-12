#ifndef __array_delete__
#define __array_delete__

#include <cstddef>
#include <utility>
#include <vector>

template <typename T>
void array_delete(std::vector<T> &A, std::size_t index)
{
    // WRITE YOUR CODE HERE
    assert(index < A.size());
    for (std::size_t j = index; j < A.size() - 1; ++j) {
        A[j] = A[j + 1];
    }
    A.resize(A.size() - 1);
    // YOUR CODE ENDS HERE
}

#endif // __array_delete__