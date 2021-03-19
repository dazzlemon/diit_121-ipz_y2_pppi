#ifndef ADJACENCY_LIST_GRAPH_H
#define ADJACENCY_LIST_GRAPH_H

#ifdef _WIN32
#define ADJACENCY_LIST_GRAPH_EXPORT_FUNC __declspec(dllexport)
#else
#define ADJACENCY_LIST_GRAPH_EXPORT_FUNC
#endif

#include <iostream>// tmp
#include "abstract_graph.h"
#include "vertex.h"

namespace simple_graph_library {

template<class T>
class AdjacencyListGraph : public AbstractGraph<T> {
public:
    std::vector<Vertex<T>> ADJACENCY_LIST_GRAPH_EXPORT_FUNC
            neighbours(Vertex<T> v) final {
        std::cout << "AdjacencyListGraph::neighbours" << std::endl;
        return {};
    }


    void ADJACENCY_LIST_GRAPH_EXPORT_FUNC add_vertex(Vertex<T> v) final {
        std::cout << "AdjacencyListGraph::add_vertex" << std::endl;
    }


    void ADJACENCY_LIST_GRAPH_EXPORT_FUNC
            add_edge(Vertex<T> a, Vertex<T> b) final {
        std::cout << "AdjacencyListGraph::add_edge" << std::endl;
    }


    void ADJACENCY_LIST_GRAPH_EXPORT_FUNC remove_vertex(Vertex<T> v) final {
        std::cout << "AdjacencyListGraph::remove_vertex" << std::endl;
    }


    void ADJACENCY_LIST_GRAPH_EXPORT_FUNC
            remove_edge(Vertex<T> a, Vertex<T> b) final {
        std::cout << "AdjacencyListGraph::remove_edge" << std::endl;
    }

protected:
    Vertex<T> _even_degree_node() final {
        return Vertex<T>();
    }


    Vertex<T> _odd_degree_node() final {
        return Vertex<T>();
    }


    size_t _n_odd_degree() final {
        return 0;// TODO
    }
};
}// namespace simple_graph_library

#endif