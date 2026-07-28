#include "shortest_paths_fw.hpp"
#include <iostream>
#include <utils.hpp>

int main(int argc, const char *argv[])
{
    Graph graph = test_graph;
    print_graph(graph);

    std::cout << "Floyd-Warshall all pairs" << std::endl;
    auto paths = floyd_warshall(graph);
    for (const auto &row : paths) { print(row); }
    std::cout << std::endl;

    return 0;
}