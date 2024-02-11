#ifndef __array__
#define __array__

#include <cassert>
#include <cstddef>
#include <vector>

template <typename T>
void array_insert(std::vector<T> &A, std::size_t index, const T &x)
{
    assert(index <= A.size());
    if (index == A.size()) {
        A.push_back(x);
    } else {
        auto i = A.size();
        A.push_back(A[i - 1]);
        for (--i; i > index; --i) { A[i] = A[i - 1]; }
        A[index] = x;
    }
}

#endif // __array__