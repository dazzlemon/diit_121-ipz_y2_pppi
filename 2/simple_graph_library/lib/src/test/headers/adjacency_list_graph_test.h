#ifndef ADJACENCY_LIST_GRAPH_TEST
#define ADJACENCY_LIST_GRAPH_TEST

#include <iostream>
#include "adjacency_list_graph.h"
#include "igraph_test.h"

void adjacency_list_graph_tests() {
    auto graph = simple_graph_library::AdjacencyListGraph();
    igraph_test(graph);
}

#endif