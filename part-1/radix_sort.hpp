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
}

#endif // __radix_sort__