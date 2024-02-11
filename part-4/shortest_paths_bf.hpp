#ifndef __shortest_paths_bf__
#define __shortest_paths_bf__

#include "graph.hpp"

std::vector<hop_t> bellman_ford(const Graph &graph, const int source,
                                bool &has_negative_cycle);

#endif // __shortest_paths_bf__