#ifndef ABSTRACT_GRAPH_H
#define ABSTRACT_GRAPH_H

#include "vertex.h"
#include "edge.h"
#include <vector>
#include <optional>

class AbstractGraph {
public:
    auto dfs(Vertex v) -> std::vector<Vertex>;
    auto bfs(Vertex v) -> std::optional<Vertex>;

    virtual auto indecent_edges(Vertex v) -> std::vector<Edge> = 0;
    virtual auto adjacent_vertex(Vertex v, Edge e) -> Vertex = 0;
    virtual auto adjacent_edges(Vertex v) -> std::vector<Edge> = 0;
};

#endif