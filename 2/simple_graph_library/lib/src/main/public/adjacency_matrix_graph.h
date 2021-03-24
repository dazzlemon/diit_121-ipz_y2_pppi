#ifndef ADJACENCY_MATRIX_GRAPH_H
#define ADJACENCY_MATRIX_GRAPH_H

#ifdef _WIN32
#define ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC __declspec(dllexport)
#else
#define ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC
#endif

#include "abstract_graph.h"
#include "vertex.h"
#include <vector>
#include <map>

namespace simple_graph_library {

/**
 * Representation of Graph with Adjacency Matrix.
 */
template<class T>
class AdjacencyMatrixGraph : public AbstractGraph<T> {
public:
    /**
     * @brief IGraph<T> override, check the description in that class.
     */
    std::vector<Vertex<T>> ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC
            neighbours(Vertex<T> v) final {
        return {};// TODO
    }


    /**
     * @brief IGraph<T> override, check the description in that class.
     */
    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC add_vertex(Vertex<T> v) override {
        Vertex<T> vertex_repr = this->GetVertexRepr(v);

        size_t vertices_count = vertex_to_index_mapping_.size();
        vertex_to_index_mapping_.try_emplace(vertex_repr, vertices_count++);
        for (auto &row: matrix_) {
            row.push_back(nullptr);
        }

        matrix_.push_back(std::vector<Edge<T> *>(vertices_count, nullptr));
        // TODO CHECK KARAKULI
    }


    /**
     * @brief IGraph<T> override, check the description in that class.
     */
    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC
            add_edge(Vertex<T> a, Vertex<T> b) final {
        Vertex<T> left_vertex_repr = this->GetVertexRepr(a);
        Vertex<T> right_vertex_repr = this->GetVertexRepr(b);

        if (!vertex_to_index_mapping_.contains(left_vertex_repr) ||
            !vertex_to_index_mapping_.contains(right_vertex_repr)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        int left_vertex_index = vertex_to_index_mapping_[left_vertex_repr];
        int right_vertex_index = vertex_to_index_mapping_[right_vertex_repr];

        auto *edge = new Edge<T>(left_vertex_repr, right_vertex_repr);

        matrix_[left_vertex_index][right_vertex_index] = edge;
        matrix_[right_vertex_index][left_vertex_index] = edge;

        edges_count_++;
        // TODO CHECK
    }


    /**
     * @brief IGraph<T> override, check the description in that class.
     */
    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC remove_vertex(Vertex<T> v) final {
        Vertex<T> vertex_repr = this->GetVertexRepr(v);

        if (!vertex_to_index_mapping_.contains(vertex_repr)) {
            throw std::runtime_error("vertex doesn't exist");
        }

        int vertex_index = vertex_to_index_mapping_[vertex_repr];
        matrix_.erase(matrix_.begin() + vertex_index);

        for (auto &row: matrix_) {
            row.erase(row.begin() + vertex_index);
        }

        vertex_to_index_mapping_.erase(vertex_repr);

        std::map<Vertex<T>, int> new_vertex_to_index_mapping_;
        for (auto &[key, value]: vertex_to_index_mapping_) {
            if (value > vertex_index) {
                new_vertex_to_index_mapping_.try_emplace(key, --value);
            } else {
                new_vertex_to_index_mapping_.try_emplace(key, value);
            }
        }

        vertex_to_index_mapping_ = new_vertex_to_index_mapping_;
        // TODO CHECK
    }


    /**
     * @brief IGraph<T> override, check the description in that class.
     */
    void ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC
            remove_edge(Vertex<T> a, Vertex<T> b) final {
        Vertex<T> left_vertex_repr = this->GetVertexRepr(a);
        Vertex<T> right_vertex_repr = this->GetVertexRepr(b);

        if (!vertex_to_index_mapping_.contains(left_vertex_repr) ||
            !vertex_to_index_mapping_.contains(right_vertex_repr)) {
            throw std::runtime_error("one or more vertices doesn't exist");
        }

        int left_vertex_index = vertex_to_index_mapping_[left_vertex_repr];
        int right_vertex_index = vertex_to_index_mapping_[right_vertex_repr];

        matrix_[left_vertex_index][right_vertex_index] = nullptr;
        matrix_[right_vertex_index][left_vertex_index] = nullptr;

        edges_count_--;
        // TODO
    }

private:
    /**
     * @brief AbstractGraph<T> override, check the description in that class.
     */
    Vertex<T> _even_degree_node() final {
        return Vertex<T>();// TODO
    }


    /**
     * @brief AbstractGraph<T> override, check the description in that class.
     */
    Vertex<T> _odd_degree_node() final {
        return Vertex<T>();// TODO
    }


    /**
     * @brief AbstractGraph<T> override, check the description in that class.
     */
    size_t _n_odd_degree() final {
        return 0;// TODO
    }
};
}// namespace simple_graph_library

#endif