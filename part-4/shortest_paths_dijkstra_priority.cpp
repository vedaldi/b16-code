#include "shortest_paths_dijkstra.hpp"
#include "shortest_paths_relax.hpp"
#include <priority_queue.hpp>

#include <cmath>

std::vector<hop_t> dijkstra_priority(const Graph &graph, const int source)
{
    const int V = static_cast<int>(graph.size());
    assert(0 <= source && source < V);

    auto DP = std::vector<hop_t>(V, {inf, -1});
    DP[source].weight = 0;

    auto queue = std::vector<hop_t>{};
    auto comparison = std::less<hop_t>{}; // for a min-priority queue
    priority_enqueue(queue, {0, source}, comparison);

    while (!queue.empty()) {
        auto v_star = queue[0].vertex;
        priority_dequeue(queue, comparison);

        for (int v = 0; v < V; ++v) {
            if (std::isfinite(graph[v_star][v])) {
                if (relax(graph, DP, v_star, v)) {
                    priority_enqueue(queue, {DP[v].weight, v}, comparison);
                }
            }
        }
    }

    return DP;
}