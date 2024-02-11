#include "shortest_paths_sparse.hpp"
#include <utils.hpp>

int main(int argc, const char *argv[])
{
    auto graph = sparse_test_graph;
    print_graph(graph);

    {
        int source = 2;
        bool has_negative_cycle;
        std::cout << "Bellman-Ford from source " << source
                  << std::endl;
        auto DP = bellman_ford(graph, source, has_negative_cycle);
        print(DP);
        std::cout << std::endl;
    }

    {
        int source = 2;
        std::cout << "Dijkstra from source " << source << std::endl;
        auto DP = dijkstra(graph, source);
        print(DP);
        std::cout << std::endl;
    }

    return 0;
}