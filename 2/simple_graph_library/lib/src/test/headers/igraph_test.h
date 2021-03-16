#ifndef IGRAPH_TEST_H
#define IGRAPH_TEST_H

#include "igraph.h"
#include "vertex.h"

void igraph_test(simple_graph_library::IGraph<int>& graph) {
    /**
     * test case for dfs, bfs
     * expected output:
     *      dfs: A B E F C D
     *      bfs: A B C D E F
     * 
     * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  AA  @@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@***@@    @@***@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@@@@@@@*********@@@@**@@@@@***@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@********@@@@@@@@@@@@**@@@@@@@***@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@***@@@@@@@@@@@@@@@@@@**@@@@@@@@@***@@@@@@@@@
     * @@@@@@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@***@    @@
     * @@@@@@@@@@@@@  BB  @@@@@@@@@@@@@@@@@@  CC  @@@@@@@@@@@@  DD  @
     * @@@@@@@@@@***@    @***@@@@@@@@@@@@@@@@    @@@@@@@@@@@@@@    @@
     * @@@@@@@@@***@@@@@@@@***@@@@@@@@@@@@***@@@@@@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@***@@@@@@@@@@***@@@@@@@@@***@@@@@@@@@@@@@@@@@@@@@@@@@@
     * @@    @***@@@@@@@@@@@@@**@    @***@@@@@@@@@@@@@@@@@@@@@@@@@@@@
     * @  EE  @@@@@@@@@@@@@@@@@@  FF  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
     * @@    @@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
     */


    graph.add_edge(
        simple_graph_library::Vertex<int>(),
        simple_graph_library::Vertex<int>()
    );
    graph.add_vertex(simple_graph_library::Vertex<int>());
    graph.bfs(simple_graph_library::Vertex<int>());
    graph.dfs(simple_graph_library::Vertex<int>());
    graph.euler_tour();
    graph.neighbours(simple_graph_library::Vertex<int>());
    graph.remove_edge(
        simple_graph_library::Vertex<int>(),
        simple_graph_library::Vertex<int>()
    );
    graph.remove_vertex(simple_graph_library::Vertex<int>());
}

#endif