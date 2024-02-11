#ifndef __shortest_paths_sparse__
#define __shortest_paths_sparse__

#include "graph.hpp"

std::vector<hop_t> bellman_ford(const SparseGraph &graph, const int source,
                                bool &has_negative_cycle);

std::vector<hop_t> dijkstra(const SparseGraph &graph, const int source);

#endif // __shortest_paths_sparse__