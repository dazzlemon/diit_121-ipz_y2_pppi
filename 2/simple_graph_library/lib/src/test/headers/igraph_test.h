#ifndef IGRAPH_TEST_H
#define IGRAPH_TEST_H

#include "igraph.h"
#include "vertex.h"
#include <concepts>

template<template<class> class G>
    requires std::derived_from<G<int>, simple_graph_library::IGraph<int>>
void igraph_test() {
    
    G<int> graph;


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


template<template<class> class G>
    requires std::derived_from<G<int>, simple_graph_library::IGraph<int>>
G<int> _search_test_case() {
    G<int> graph;
    graph.add_vertex(simple_graph_library::Vertex<int>(/*A*/));
    graph.add_vertex(simple_graph_library::Vertex<int>(/*B*/));
    graph.add_vertex(simple_graph_library::Vertex<int>(/*C*/));
    graph.add_vertex(simple_graph_library::Vertex<int>(/*D*/));
    graph.add_vertex(simple_graph_library::Vertex<int>(/*E*/));
    graph.add_vertex(simple_graph_library::Vertex<int>(/*F*/));

    graph.add_edge(
        simple_graph_library::Vertex<int>(/*A*/),
        simple_graph_library::Vertex<int>(/*B*/)
    );
    graph.add_edge(
        simple_graph_library::Vertex<int>(/*A*/),
        simple_graph_library::Vertex<int>(/*C*/)
    );
    graph.add_edge(
        simple_graph_library::Vertex<int>(/*A*/),
        simple_graph_library::Vertex<int>(/*D*/)
    );
    graph.add_edge(
        simple_graph_library::Vertex<int>(/*B*/),
        simple_graph_library::Vertex<int>(/*E*/)
    );
    graph.add_edge(
        simple_graph_library::Vertex<int>(/*B*/),
        simple_graph_library::Vertex<int>(/*F*/)
    );
    graph.add_edge(
        simple_graph_library::Vertex<int>(/*C*/),
        simple_graph_library::Vertex<int>(/*F*/)
    );
    return graph;
}


template<template<class> class G>
    requires std::derived_from<G<int>, simple_graph_library::IGraph<int>>
void bfs_test() {
    /**
     * test case for bfs
     * expected output: A B C D E F
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

    auto graph = _search_test_case<G>();
    graph.bfs(simple_graph_library::Vertex<char>(/*A*/));
    // TODO: assert result + TODO vertex
}


template<template<class> class G>
    requires std::derived_from<G<int>, simple_graph_library::IGraph<int>>
void dfs_test() {
    /**
     * test case for dfs
     * expected output: A B E F C D
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

    auto graph = _search_test_case<G>();
    graph.dfs(simple_graph_library::Vertex<char>(/*A*/));
    // TODO: assert result + TODO vertex
}


template<template<class> class G>
    requires std::derived_from<G<int>, simple_graph_library::IGraph<int>>
void euler_test() {
    /**
     * test case for euler path
     * expected output:
     *      C A B D
     *      C D B A
     *      B D C A
     *      B A C D
     * ...
     * 
     * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@@@@@@@   AA   @@@@@@@@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@@@@@@@   AA   @@@@@@@@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@@@@@@@**@@@@**@@@@@@@@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@@@@@@**@@@@@@**@@@@@@@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@@@@@**@@@@@@@@**@@@@@@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@@@@**@@@@@@@@@@**@@@@@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@@@**@@@@@@@@@@@@**@@@@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@@**@@@@@@@@@@@@@@**@@@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@@**@@@@@@@@@@@@@@@@**@@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@@**@@@@@@@@@@@@@@@@@@**@@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@@**@@@@@@@@@@@@@@@@@@@@**@@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@@**@@@@@@@@@@@@@@@@@@@@@@**@@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@@**@@@@@@@@@@@@@@@@@@@@@@@@**@@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@@**@@@@@@@@@@@@@@@@@@@@@@@@@@**@@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@@**@@@@@@@@@@@@@@@@@@@@@@@@@@@@**@@@@@@@@@@@@@@
     * @@@@@@@@@@@@@**@@@@@@@@@@@@      @@@@@@@@@@@@**@@@@@@@@@@@@@
     * @@@@@@@@@@@@**@@@@@@@@@@@@   DD   @@@@@@@@@@@@**@@@@@@@@@@@@
     * @@@@@@@@@@@**@@@@@@@@@@@@@   DD   @@@@@@@@@@@@@**@@@@@@@@@@@
     * @@@@@@@@@@**@@@@@@@@@@@@@**      **@@@@@@@@@@@@@**@@@@@@@@@@
     * @@@@@@@@@**@@@@@@@@@@@****@@@@@@@@****@@@@@@@@@@@**@@@@@@@@@
     * @@@@@@@@**@@@@@@@@@****@@@@@@@@@@@@@@****@@@@@@@@@**@@@@@@@@
     * @@@@@@@**@@@@@@@****@@@@@@@@@@@@@@@@@@@@****@@@@@@@**@@@@@@@
     * @@@@@@**@@@@@****@@@@@@@@@@@@@@@@@@@@@@@@@@****@@@@@**@@@@@@
     * @@@@@**@@@****@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@****@@@**@@@@@
     * @@      @**@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@**@      @@
     * @   BB   ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,   CC   @
     * @   BB   ''''''''''''''''''''''''''''''''''''''''''   CC   @
     * @@      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@
     * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
     * 
     */
}

#endif