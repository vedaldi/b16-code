#ifndef __shortest_paths_dijkstra_sparse__
#define __shortest_paths_dijkstra_sparse__

#include "graph.hpp"

std::vector<hop_t> dijkstra(const SparseGraph &graph, const int source);

#endif // __shortest_paths_dijkstra_sparse__
