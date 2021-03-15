#ifndef ADJACENCY_LIST_GRAPH_H
#define ADJACENCY_LIST_GRAPH_H

#ifdef _WIN32
#define ADJACENCY_LIST_GRAPH_EXPORT_FUNC __declspec(dllexport)
#else
#define ADJACENCY_LIST_GRAPH_EXPORT_FUNC
#endif

#include <iostream>// tmp
#include "abstract_graph.h"

namespace simple_graph_library {
class AdjacencyListGraph : public AbstractGraph {
    std::vector<Vertex> ADJACENCY_LIST_GRAPH_EXPORT_FUNC neighbours(Vertex v) final;
    void ADJACENCY_LIST_GRAPH_EXPORT_FUNC add_vertex(Vertex v) final;
    void ADJACENCY_LIST_GRAPH_EXPORT_FUNC add_edge(Vertex a, Vertex b) final;
    void ADJACENCY_LIST_GRAPH_EXPORT_FUNC remove_vertex(Vertex v) final;
    void ADJACENCY_LIST_GRAPH_EXPORT_FUNC remove_edge(Vertex a, Vertex b) final;
};


std::vector<Vertex> ADJACENCY_LIST_GRAPH_EXPORT_FUNC AdjacencyListGraph::neighbours(Vertex v) {
    std::cout << "AdjacencyListGraph::neighbours" << std::endl;
    return {};
}


void ADJACENCY_LIST_GRAPH_EXPORT_FUNC AdjacencyListGraph::add_vertex(Vertex v) {
    std::cout << "AdjacencyListGraph::add_vertex" << std::endl;
}


void ADJACENCY_LIST_GRAPH_EXPORT_FUNC AdjacencyListGraph::add_edge(Vertex a, Vertex b) {
    std::cout << "AdjacencyListGraph::add_edge" << std::endl;
}


void ADJACENCY_LIST_GRAPH_EXPORT_FUNC AdjacencyListGraph::remove_vertex(Vertex v) {
    std::cout << "AdjacencyListGraph::remove_vertex" << std::endl;
}


void ADJACENCY_LIST_GRAPH_EXPORT_FUNC AdjacencyListGraph::remove_edge(Vertex a, Vertex b) {
    std::cout << "AdjacencyListGraph::remove_edge" << std::endl;
}
}// namespace simple_graph_library

#endif