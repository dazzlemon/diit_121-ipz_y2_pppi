#ifndef ADJACENCY_MATRIX_GRAPH_TEST
#define ADJACENCY_MATRIX_GRAPH_TEST

#include "adjacency_matrix_graph.h"
#include "igraph_test.h"

auto adjacency_matrix_graph_tests() {
    auto graph = simple_graph_library::AdjacencyMatrixGraph();
    igraph_test(graph);
}

#endif