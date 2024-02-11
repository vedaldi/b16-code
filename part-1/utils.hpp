#ifndef __utils__
#define __utils__

#include <iostream>
#include <vector>

// Pretty-print an array
template <typename I>
void print(const I &begin, const I &end,
           const std::string &prefix = {})
{
    auto &out = std::cout;
    if (!prefix.empty()) out << prefix;
    out << "[";
    bool first = true;
    for (auto i = begin; i != end; ++i) {
        if (!first) out << ", ";
        out << *i;
        first = false;
    }
    out << ']' << std::endl;
}

template <typename C>
void print(const C &A, const std::string &prefix = {})
{
    print(begin(A), end(A), prefix);
}

#endif // __utils__
