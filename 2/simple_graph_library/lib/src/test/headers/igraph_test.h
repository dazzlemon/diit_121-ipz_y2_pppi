#ifndef IGRAPH_TEST_H
#define IGRAPH_TEST_H

#include "igraph.h"

void igraph_test(simple_graph_library::IGraph& graph) {
    graph.add_edge(Vertex(), Vertex());
    graph.add_vertex(Vertex());
    graph.bfs(Vertex());
    graph.dfs(Vertex());
    graph.euler_tour();
    graph.neighbours(Vertex());
    graph.remove_edge(Vertex(), Vertex());
    graph.remove_vertex(Vertex());
}

#endif