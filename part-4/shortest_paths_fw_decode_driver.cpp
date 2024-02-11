
#include <algorithm>
#include <iostream>
#include <vector>

#include "shortest_paths_decode.hpp"
#include "shortest_paths_fw.hpp"
#include <utils.hpp>

int main(int argc, const char *argv[])
{
    Graph graph = test_graph;
    print_graph(graph);

    std::cout << "Floyd-Warshall ASPS" << std::endl;
    auto DP = floyd_warshall(graph);
    for (const auto &row : DP) {
        print(row);
    }
    std::cout << std::endl;

    for (int u = 0; u < (signed)graph.size(); ++u) {
        for (int v = 0; v < (signed)graph.size(); ++v) {
            auto path = decode(DP[u], v);
            if (path.size()) {
                std::cout << "Shortest path " << u << " ~~> " << v
                          << " (weight " << DP[u][v].weight << "): ";
                print(path);
            }
        }
    };

    return 0;
}
