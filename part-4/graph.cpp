#include "graph.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

const Graph test_graph =
    Graph{{inf , 4  , inf, inf , inf, inf , inf, 8  , inf}  ,
          {inf , inf, inf, inf , inf, inf , inf, 11 , inf}  ,
          {inf , inf, inf, inf , inf, 4   , inf, inf, 2}    ,
          {inf , inf, inf, inf , 9  , 14  , inf, inf, inf}  ,
          {inf , inf, inf, inf , inf, 10  , inf, inf, inf}  ,
          {inf , inf, inf, inf , inf, inf , 2  , inf, inf}  ,
          {inf , inf, inf, 3   , inf, inf , inf, 1  , 6}    ,
          {inf , inf, inf, inf , inf, inf , inf, inf, 7}    ,
          {inf , inf, inf, inf , inf, inf , inf, inf, inf}};

const SparseGraph sparse_test_graph =
    SparseGraph{
         {{4,1}, {8,7},},
         {{11,7},},
         {{4,5}, {2,8},},
         {{9,4}, {14,5},},
         {{10,5},},
         {{2,6},},
         {{3,3}, {1,7}, {6,8},},
         {{7,8},},
         {}};

static SparseGraph _graph_to_sparse(const Graph &graph)
{
    SparseGraph sp;
    for (const auto &row : graph) {
        std::vector<hop_t> outgoing;
        for (size_t v = 0; v < row.size(); ++v) {
            if (std::isfinite(row[v])) { outgoing.push_back({row[v], (int)v}); }
        }
        sp.push_back(outgoing);
    }
    return sp;
}

static std::string _graph_to_dot(const SparseGraph &sp)
{
    std::ostringstream oss;
    oss << "digraph G {" << std::endl;
    for (int v = 0; v < (int)sp.size(); ++v) {
        for (auto const &hop : sp[v]) {
            oss << "    " << v << " -> " << hop.vertex
                << " [label= " << hop.weight << "];" << std::endl;
        }
    }
    oss << "}" << std::endl;
    return oss.str();
}

void print_graph(const SparseGraph &graph, bool as_url)
{
    std::string str = _graph_to_dot(graph);
    if (as_url) {
        std::ostream os{std::cout.rdbuf()}; // to save the iomanip state
        os << "https://dreampuf.github.io/GraphvizOnline/#";
        std::string str = _graph_to_dot(graph);
        for (const auto &c : str) {
            os << '%' << std::hex << std::setfill('0') << std::setw(2)
               << static_cast<int>(c);
        }
        os << std::endl;
    } else {
        std::cout << str << std::endl;
    }
}

void print_graph(const Graph &graph, bool as_url)
{
    print_graph(_graph_to_sparse(graph), as_url);
}
