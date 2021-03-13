#ifndef ABSTRACT_GRAPH_H
#define ABSTRACT_GRAPH_H

#include "vertex.h"
#include <vector>

class AbstractGraph {
    template<class T>
    auto _search(Vertex v) -> std::vector<Vertex>;
public:
    auto dfs(Vertex v) -> std::vector<Vertex>;
    auto bfs(Vertex v) -> std::vector<Vertex>;

    virtual auto neighbours(Vertex v) -> std::vector<Vertex> = 0;
};

#endif