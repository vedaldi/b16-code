#ifndef __shortest_paths_relax__
#define __shortest_paths_relax__

#include "graph.hpp"
#include <vector>

inline bool relax(const Graph &graph, std::vector<hop_t> &DP, int r, int v)
{
    auto Duv = DP[v].weight;
    auto Duv_via_r = DP[r].weight + graph[r][v];
    if (Duv_via_r < Duv) {
        DP[v] = {Duv_via_r, r};
        return true;
    }
    return false;
}

#endif // __shortest_paths_relax__
