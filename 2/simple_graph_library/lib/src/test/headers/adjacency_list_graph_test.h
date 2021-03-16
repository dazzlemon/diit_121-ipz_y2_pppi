#ifndef ADJACENCY_LIST_GRAPH_TEST
#define ADJACENCY_LIST_GRAPH_TEST

#include "adjacency_list_graph.h"
#include "igraph_test.h"

void adjacency_list_graph_tests() {
    auto graph = simple_graph_library::AdjacencyListGraph<int>();
    igraph_test(graph);
}

#endif