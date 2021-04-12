#ifndef IGRAPH_TEST_H
#define IGRAPH_TEST_H

#include "igraph.h"
#include "vertex.h"
#include <concepts>
#include <string>
#include <cassert>
#include <ranges>
#include <iostream>// temp

std::string _char_vertex_vector_to_string(
        std::vector<simple_graph_library::Vertex<char>> vec) {
    auto tr = vec | std::views::transform( [] (auto v) { return v.data; } );
    return std::string(tr.begin(), tr.end());
}


template<template<class> class G>
    requires std::derived_from<G<char>, simple_graph_library::IGraph<char>>
G<char> _search_test_case() {
    G<char> graph;
    graph.add_vertex(simple_graph_library::Vertex<char>('A'));
    graph.add_vertex(simple_graph_library::Vertex<char>('B'));
    graph.add_vertex(simple_graph_library::Vertex<char>('C'));
    graph.add_vertex(simple_graph_library::Vertex<char>('D'));
    graph.add_vertex(simple_graph_library::Vertex<char>('E'));
    graph.add_vertex(simple_graph_library::Vertex<char>('F'));

    graph.add_edge(
        simple_graph_library::Vertex<char>('A'),
        simple_graph_library::Vertex<char>('B')
    );
    graph.add_edge(
        simple_graph_library::Vertex<char>('A'),
        simple_graph_library::Vertex<char>('C')
    );
    graph.add_edge(
        simple_graph_library::Vertex<char>('A'),
        simple_graph_library::Vertex<char>('D')
    );
    graph.add_edge(
        simple_graph_library::Vertex<char>('B'),
        simple_graph_library::Vertex<char>('E')
    );
    graph.add_edge(
        simple_graph_library::Vertex<char>('B'),
        simple_graph_library::Vertex<char>('F')
    );
    graph.add_edge(
        simple_graph_library::Vertex<char>('C'),
        simple_graph_library::Vertex<char>('F')
    );
    return graph;
}


template<template<class> class G>
    requires std::derived_from<G<char>, simple_graph_library::IGraph<char>>
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
    auto bfs_vec = graph.bfs(simple_graph_library::Vertex<char>('A'));
    auto str = _char_vertex_vector_to_string(bfs_vec);
    assert(str == "ABCDEF");
}


template<template<class> class G>
    requires std::derived_from<G<char>, simple_graph_library::IGraph<char>>
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
    auto dfs_vec = graph.dfs(simple_graph_library::Vertex<char>('A'));
    auto str = _char_vertex_vector_to_string(dfs_vec);
    std::cout << str << std::endl;
    assert(str == "ABEFCD");
}


template<template<class> class G>
    requires std::derived_from<G<char>, simple_graph_library::IGraph<char>>
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
    G<char> graph;
    graph.add_vertex(simple_graph_library::Vertex<char>('A'));
    graph.add_vertex(simple_graph_library::Vertex<char>('B'));
    graph.add_vertex(simple_graph_library::Vertex<char>('C'));
    graph.add_vertex(simple_graph_library::Vertex<char>('D'));

    graph.add_edge(
        simple_graph_library::Vertex<char>('A'),
        simple_graph_library::Vertex<char>('B')
    );
    graph.add_edge(
        simple_graph_library::Vertex<char>('A'),
        simple_graph_library::Vertex<char>('C')
    );
    graph.add_edge(
        simple_graph_library::Vertex<char>('B'),
        simple_graph_library::Vertex<char>('C')
    );
    graph.add_edge(
        simple_graph_library::Vertex<char>('D'),
        simple_graph_library::Vertex<char>('B')
    );
    graph.add_edge(
        simple_graph_library::Vertex<char>('D'),
        simple_graph_library::Vertex<char>('C')
    );

    auto euler_vec = graph.euler_tour();
    auto str = _char_vertex_vector_to_string(euler_vec);
    std::cout << "str " << str << std::endl;
    assert(
        str == "CABD" ||
        str == "CDBA" ||
        str == "BDCA" ||
        str == "BACD"
    );
}


template<template<class> class G>
    requires std::derived_from<G<char>, simple_graph_library::IGraph<char>>
void igraph_test() {
    bfs_test<G>();
    //dfs_test<G>();
    euler_test<G>();
}

#endif