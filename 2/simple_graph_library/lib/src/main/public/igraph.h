#ifndef IGRAPH_H
#define IGRAPH_H

#ifdef _WIN32
#define IGRAPH_EXPORT_FUNC __declspec(dllexport)
#else
#define IGRAPH_EXPORT_FUNC
#endif

#include <vector>
#include "vertex.h"

namespace simple_graph_library {

template<class T>
class IGraph {
public:
    virtual auto dfs(Vertex<T> v)
        -> std::vector<Vertex<T>> IGRAPH_EXPORT_FUNC = 0;
    
    virtual auto bfs(Vertex<T> v)
        -> std::vector<Vertex<T>> IGRAPH_EXPORT_FUNC = 0;
    
    virtual auto euler_tour()
        -> std::vector<Vertex<T>> IGRAPH_EXPORT_FUNC = 0;


    /**
     * @brief Returns vector of vertices that have common edge with <v>.
     * @param[in] v vertex to get neighbours from
     * @return vector of neighbouring vertices to <v>
     */
    virtual auto neighbours(Vertex<T> v)
        -> std::vector<Vertex<T>> IGRAPH_EXPORT_FUNC = 0;


    /**
     * @brief Adds vertex <v> to this graph.
     * @param[in] v vertex to add
     * @details
     * Vertex doesnt have any edges after adding,
     * they have to be declared separately by function add_edge.
     */
    virtual void IGRAPH_EXPORT_FUNC add_vertex(Vertex<T> v) = 0;


    /**
     * @brief Adds edge between two vertices <a> and <b>.
     * @param[in] a first vertex for new common edge
     * @param[in] b second vertex for new common edge
     * @details
     * if either <a> or <b> is not in the graph edge is not added.
     */
    virtual void IGRAPH_EXPORT_FUNC add_edge(Vertex<T> a, Vertex<T> b) = 0;


    /**
     * @brief Removes vertex <v> from this graph.
     * @param[in] v vertex to remove
     * @details 
     * if <v> is not in the graph its not removed(obviously).
     */
    virtual void IGRAPH_EXPORT_FUNC remove_vertex(Vertex<T> v) = 0;


    /**
     * @brief Removes edge between two vertices.
     * @param[in] a first vertex to remove common edge from
     * @param[in] b second vertex to remove common edge from
     * @details
     * if either <a> or <b> is not in the graph
     * or they dont common edge its not removed(obviously).
     */
    virtual void IGRAPH_EXPORT_FUNC remove_edge(Vertex<T> a, Vertex<T> b) = 0;
};
}// namespace simple_graph_library
#endif