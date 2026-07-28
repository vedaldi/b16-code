#include "shortest_paths_dijkstra_sparse.hpp"
#include <utils.hpp>

int main(int argc, const char *argv[])
{
    auto graph = sparse_test_graph;
    print_graph(graph);

    int source = 2;
    std::cout << "Dijkstra from source " << source << std::endl;
    auto DP = dijkstra(graph, source);
    print(DP);
    std::cout << std::endl;

    return 0;
}
