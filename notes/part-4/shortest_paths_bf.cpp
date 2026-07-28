#include "shortest_paths_bf.hpp"
#include "shortest_paths_relax.hpp"

#include <cassert>

std::vector<hop_t> bellman_ford(const Graph &graph, const int source,
                                bool &has_negative_cycle)
{
    const int V = static_cast<int>(graph.size());
    assert(0 <= source && source < V);

    auto DP = std::vector<hop_t>(V, {inf, -1});
    DP[source].weight = 0;

    for (int iter = 0; iter < V - 1; ++iter) {
        has_negative_cycle = false;
        for (int r = 0; r < V; ++r) {
            for (int v = 0; v < V; ++v) {
                has_negative_cycle |= relax(graph, DP, r, v);
            }
        }
    }

    return DP;
}
