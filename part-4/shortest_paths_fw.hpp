#ifndef __shortest_paths_fw__
#define __shortest_paths_fw__

#include "graph.hpp"

std::vector<std::vector<hop_t>> floyd_warshall(const Graph &graph);

#endif // __shortest_paths_fw__