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
class IGraph {
public:
    virtual auto dfs(Vertex v) -> std::vector<Vertex> IGRAPH_EXPORT_FUNC = 0;
    virtual auto bfs(Vertex v) -> std::vector<Vertex> IGRAPH_EXPORT_FUNC = 0;
    virtual auto euler_tour() -> std::vector<Vertex> IGRAPH_EXPORT_FUNC = 0;

    virtual auto neighbours(Vertex v) -> std::vector<Vertex> IGRAPH_EXPORT_FUNC = 0;

    virtual void IGRAPH_EXPORT_FUNC add_vertex(Vertex v) = 0;
    virtual void IGRAPH_EXPORT_FUNC add_edge(Vertex a, Vertex b) = 0;
    virtual void IGRAPH_EXPORT_FUNC remove_vertex(Vertex v) = 0;
    virtual void IGRAPH_EXPORT_FUNC remove_edge(Vertex a, Vertex b) = 0;
};
}// namespace simple_graph_library
#endif