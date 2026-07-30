#ifndef __array_insert_movable__
#define __array_insert_movable__

#include <vector>
#include <utility>
#include <type_traits>
#include <cstddef>

template <typename T, typename E = std::remove_reference_t<T>>
void array_insert_movable(std::vector<E>& A, std::size_t index, T&& x)
{
    assert(index <= A.size());
    if (index == A.size()) {
        A.push_back(std::forward<T>(x));
    } else {
        auto i = A.size();
        A.push_back(std::move(A[i - 1]));
        for (--i; i > index; --i) {
            A[i] = std::move(A[i - 1]);
        }
        A[index] = std::forward<T>(x);
    }
}

#endif  // __array_insert_movable__