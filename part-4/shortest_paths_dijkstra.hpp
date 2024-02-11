#ifndef __shortest_paths_dijkstra__
#define __shortest_paths_dijkstra__

#include "graph.hpp"

std::vector<hop_t> dijkstra(const Graph &graph, const int source);
std::vector<hop_t> dijkstra_priority(const Graph &graph, const int source);

#endif // __shortest_paths_dijkstra__