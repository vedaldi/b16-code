#include "shortest_paths_bf.hpp"
#include <iostream>
#include <utils.hpp>

int main(int argc, const char *argv[])
{
    Graph graph = test_graph;
    print_graph(graph);

    int source = 2;
    std::cout << "Bellman-Ford SSSP from source " << source << std::endl;

    bool has_negative_cycle;
    auto DP = bellman_ford(graph, source, has_negative_cycle);
    if (has_negative_cycle) {
        std::cout << "The graph has a negative cycle." << std::endl;
    } else {
        print(DP);
    }
    std::cout << std::endl;
    return 0;
}