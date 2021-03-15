#ifndef ADJACENCY_MATRIX_GRAPH_H
#define ADJACENCY_MATRIX_GRAPH_H

#ifdef _WIN32
#define ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC __declspec(dllexport)
#else
#define ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC
#endif

#include <iostream>
#include "abstract_graph.h"

namespace simple_graph_library {
class AdjacencyMatrixGraph : public AbstractGraph {
    std::vector<Vertex> ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC neighbours(Vertex v) final;
    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC add_vertex(Vertex v) final;
    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC add_edge(Vertex a, Vertex b) final;
    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC remove_vertex(Vertex v) final;
    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC remove_edge(Vertex a, Vertex b) final;
};


std::vector<Vertex> ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC AdjacencyMatrixGraph::neighbours(Vertex v) {
    std::cout << "AdjacencyMatrixGraph::neighbours" << std::endl;
    return {};
}


void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC AdjacencyMatrixGraph::add_vertex(Vertex v) {
    std::cout << "AdjacencyMatrixGraph::add_vertex" << std::endl;
}


void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC AdjacencyMatrixGraph::add_edge(Vertex a, Vertex b) {
    std::cout << "AdjacencyMatrixGraph::add_edge" << std::endl;
}


void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC AdjacencyMatrixGraph::remove_vertex(Vertex v) {
    std::cout << "AdjacencyMatrixGraph::remove_vertex" << std::endl;
}


void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC AdjacencyMatrixGraph::remove_edge(Vertex a, Vertex b) {
    std::cout << "AdjacencyMatrixGraph::remove_edge" << std::endl;
}
}// namespace simple_graph_library

#endif