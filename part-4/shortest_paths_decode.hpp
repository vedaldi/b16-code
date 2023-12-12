#ifndef __shortest_paths_decode__
#define __shortest_paths_decode__

#include "graph.hpp"
#include <algorithm>
#include <vector>

inline std::vector<int> decode(const std::vector<hop_t> &DP, int v)
{
    // WRITE YOUR CODE HERE
    if (DP[v].vertex < 0) { return {}; }
    std::vector<int> path{v};
    while (true) {
        auto next = DP[v].vertex;
        if (next == v || next < 0) { break; }
        v = next;
        path.push_back(v);
    }
    std::reverse(begin(path), end(path));
    return path;
    // YOUR CODE ENDS HERE
}

#endif // __shortest_paths_decode__
