#ifndef __shortest_paths_bf_sparse__
#define __shortest_paths_bf_sparse__

#include "graph.hpp"

std::vector<hop_t> bellman_ford(const SparseGraph &graph, const int source,
                                bool &has_negative_cycle);

#endif // __shortest_paths_bf_sparse__