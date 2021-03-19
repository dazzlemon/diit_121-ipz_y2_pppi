#ifndef ADJACENCY_MATRIX_GRAPH_H
#define ADJACENCY_MATRIX_GRAPH_H

#ifdef _WIN32
#define ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC __declspec(dllexport)
#else
#define ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC
#endif

#include "abstract_graph.h"
#include "vertex.h"

namespace simple_graph_library {

template<class T>
class AdjacencyMatrixGraph : public AbstractGraph<T> {
public:
    std::vector<Vertex<T>> ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC
            neighbours(Vertex<T> v) final {
        return {};// TODO
    }


    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC add_vertex(Vertex<T> v) final {
        // TODO
    }


    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC
            add_edge(Vertex<T> a, Vertex<T> b) final {
        // TODO
    }


    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC remove_vertex(Vertex<T> v) final {
        // TODO
    }


    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC
            remove_edge(Vertex<T> a, Vertex<T> b) final {
        // TODO
    }

protected:
    Vertex<T> _even_degree_node() final {
        return Vertex<T>();// TODO
    }


    Vertex<T> _odd_degree_node() final {
        return Vertex<T>();// TODO
    }


    size_t _n_odd_degree() final {
        return 0;// TODO
    }
};
}// namespace simple_graph_library

#endif