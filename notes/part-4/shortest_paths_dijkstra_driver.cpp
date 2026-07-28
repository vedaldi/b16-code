#include "shortest_paths_dijkstra.hpp"
#include <utils.hpp>

int main(int argc, const char *argv[])
{
    auto graph = test_graph;
    print_graph(graph);

    {
        int source = 2;
        std::cout << "Dijkstra from source " << source << std::endl;
        auto parents = dijkstra(graph, source);
        print(parents);
        std::cout << std::endl;
    }

    {
        int source = 2;
        std::cout << "Dijkstra priority from source " << source << std::endl;
        auto parents = dijkstra_priority(graph, source);
        print(parents);
        std::cout << std::endl;
    }

    return 0;
}