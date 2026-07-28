#ifndef __shortest_paths_relax__
#define __shortest_paths_relax__

#include "graph.hpp"

#include <cmath>
#include <vector>

inline bool relax(const Graph &graph, std::vector<hop_t> &DP, int r, int v)
{
    auto Dv = DP[v].weight;
    auto Dr = DP[r].weight;
    auto wrv = graph[r][v];
    auto alt = Dr + wrv;
    if (std::isfinite(alt) && alt < Dv) {
        DP[v] = {alt, r};
        return true;
    }
    return false;
}

#endif // __shortest_paths_relax__
