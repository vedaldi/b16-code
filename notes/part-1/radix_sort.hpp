#ifndef __radix_sort__
#define __radix_sort__

#include <algorithm>
#include <limits>

template <typename I>
static constexpr int num_digits_v =
    std::numeric_limits<typename I::value_type>::digits;

template <typename I>
void radix_sort(const I &begin, const I &end,
                int digit = num_digits_v<I>)
{
    // WRITE YOUR CODE HERE
    if (begin >= end) return;
    using T = typename I::value_type;
    const T mask = static_cast<T>(1) << digit;
    auto i = begin;
    auto j = end - 1;
    while (true) {
        while (i != end && (*i & mask) == 0) i++;
        while (j != begin - 1 && (*j & mask) != 0) j--;
        if (i >= j) break;
        std::swap(*i, *j);
    }
    if (digit == 0) return;
    radix_sort(begin, i, digit - 1);
    radix_sort(j + 1, end, digit - 1); // or (i, end, digit-1)
    // YOUR CODE ENDS HERE
}

#endif // __radix_sort__