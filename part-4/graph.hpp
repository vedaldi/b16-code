#ifndef __graph_hpp__
#define __graph_hpp__

#include <iostream>
#include <limits>
#include <vector>

// Weighted adjacency matrix representation
using Graph = std::vector<std::vector<float>>;

void print_graph(const Graph &graph, bool as_url = false);

// Weighted adjacency list representation
struct hop_t {
    float weight;
    int vertex;
};

inline bool operator<(const hop_t &lhs, const hop_t &rhs)
{
    return lhs.weight < rhs.weight;
};

using SparseGraph = std::vector<std::vector<hop_t>>;

void print_graph(const SparseGraph &graph, bool as_url = false);

inline std::ostream &operator<<(std::ostream &os, const hop_t &hop)
{
    return os << "(" << hop.weight << "," << hop.vertex << ')';
}

constexpr auto inf = std::numeric_limits<float>::infinity();

// Test graphs
extern const Graph test_graph;
extern const SparseGraph sparse_test_graph;

#endif //__graph_hpp__
