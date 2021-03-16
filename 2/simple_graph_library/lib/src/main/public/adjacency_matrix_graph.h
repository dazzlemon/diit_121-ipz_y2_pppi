#ifndef ADJACENCY_MATRIX_GRAPH_H
#define ADJACENCY_MATRIX_GRAPH_H

#ifdef _WIN32
#define ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC __declspec(dllexport)
#else
#define ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC
#endif

#include <iostream>// tmp
#include "abstract_graph.h"
#include "vertex.h"

namespace simple_graph_library {

template<class T>
class AdjacencyMatrixGraph : public AbstractGraph<T> {
    std::vector<Vertex<T>> ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC
            neighbours(Vertex<T> v) final {
        std::cout << "AdjacencyMatrixGraph::neighbours" << std::endl;
        return {};
    }


    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC add_vertex(Vertex<T> v) final {
        std::cout << "AdjacencyMatrixGraph::add_vertex" << std::endl;
    }


    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC
            add_edge(Vertex<T> a, Vertex<T> b) final {
        std::cout << "AdjacencyMatrixGraph::add_edge" << std::endl;
    }


    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC remove_vertex(Vertex<T> v) final {
        std::cout << "AdjacencyMatrixGraph::remove_vertex" << std::endl;
    }


    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC
            remove_edge(Vertex<T> a, Vertex<T> b) final {
        std::cout << "AdjacencyMatrixGraph::remove_edge" << std::endl;
    }
};
}// namespace simple_graph_library

#endif