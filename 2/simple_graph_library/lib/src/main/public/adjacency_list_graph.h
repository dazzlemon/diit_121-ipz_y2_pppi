#ifndef ADJACENCY_LIST_GRAPH_H
#define ADJACENCY_LIST_GRAPH_H

#ifdef _WIN32
#define ADJACENCY_LIST_GRAPH_EXPORT_FUNC __declspec(dllexport)
#else
#define ADJACENCY_LIST_GRAPH_EXPORT_FUNC
#endif

#include "abstract_graph.h"
#include "vertex.h"
#include <map>
#include <list>
#include <set>
#include <vector>

namespace simple_graph_library {

/**
 * Representation of Graph with Adjacency List.
 */
template<class T>
class AdjacencyListGraph : public AbstractGraph<T> {
public:
    /**
     * @brief IGraph<T> override, check the description in that class.
     */
    std::vector<Vertex<T>> ADJACENCY_LIST_GRAPH_EXPORT_FUNC
            neighbours(Vertex<T> v) final {
        auto [first, last] = adjacency_list.equal_range(v);
        std::vector<Vertex<T>> vec;
        for (; first != last; first++) {
            vec.push_back(first->second);
        }
        return vec;
    }


    /**
     * @brief IGraph<T> override, check the description in that class.
     */
    void ADJACENCY_LIST_GRAPH_EXPORT_FUNC add_vertex(Vertex<T> v) final {
        vertices.insert(v);
    }


    /**
     * @brief IGraph<T> override, check the description in that class.
     */
    void ADJACENCY_LIST_GRAPH_EXPORT_FUNC
            add_edge(Vertex<T> a, Vertex<T> b) final {
        if (vertices.count(a) && vertices.count(b)) {
            adjacency_list.insert({a, b});
            adjacency_list.insert({b, a});
        }
    }


    /**
     * @brief IGraph<T> override, check the description in that class.
     */
    void ADJACENCY_LIST_GRAPH_EXPORT_FUNC remove_vertex(Vertex<T> v) final {
        if (vertices.count(v)) {
            vertices.erase(v);
            adjacency_list.erase(v);
            for (auto i = adjacency_list.begin(); i != adjacency_list.end();) {
                if (i->second <=> v == 0) {// ?
                    i = adjacency_list.erase(i);
                } else {
                    i++;
                }
            }
        }
    }


    /**
     * @brief IGraph<T> override, check the description in that class.
     */
    void ADJACENCY_LIST_GRAPH_EXPORT_FUNC
            remove_edge(Vertex<T> a, Vertex<T> b) final {
        if (vertices.count(a) && vertices.count(b)) {
            auto [first_a, last_a] = adjacency_list.equal_range(a);
            for (; first_a != last_a; first_a++) {
                if (first_a->second <=> b == 0) {// ?
                    adjacency_list.erase(first_a);
                    break;
                }
            }


            auto [first_b, last_b] = adjacency_list.equal_range(b);
            for (; first_b != last_b; first_b++) {
                if (first_b->second <=> a == 0) {// ?
                    adjacency_list.erase(first_b);
                    break;
                }
            }
        }
    }

private:
    std::multimap<Vertex<T>, Vertex<T>> adjacency_list;
    std::set<Vertex<T>> vertices;


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