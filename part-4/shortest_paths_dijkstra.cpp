#include "shortest_paths_dijkstra.hpp"
#include "shortest_paths_relax.hpp"
#include <priority_queue.hpp>

#include <cmath>

std::vector<hop_t> dijkstra(const Graph &graph, const int source)
{
    const int V = static_cast<int>(graph.size());
    assert(0 <= source && source < V);

    auto DP = std::vector<hop_t>(V, {inf, -1});
    DP[source].weight = 0;

    std::vector<bool> is_open(V, true);

    while (true) {
        float D_star = inf;
        int v_star = -1;
        for (int v = 0; v < V; ++v) {
            if (is_open[v] && DP[v].weight < D_star) {
                D_star = DP[v].weight;
                v_star = v;
            }
        }

        if (v_star < 0) {
            break; // all closed, stop
        }

        is_open[v_star] = false;

        for (int v = 0; v < V; ++v) {
            if (is_open[v] && std::isfinite(graph[v_star][v])) {
                relax(graph, DP, v_star, v);
            }
        }
    }

    return DP;
}
