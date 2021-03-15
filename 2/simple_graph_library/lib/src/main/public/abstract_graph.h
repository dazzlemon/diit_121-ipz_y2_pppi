#ifndef ABSTRACT_GRAPH_H
#define ABSTRACT_GRAPH_H

#ifdef _WIN32
#define ABSTRACT_GRAPH_EXPORT_FUNC __declspec(dllexport)
#else
#define ABSTRACT_GRAPH_EXPORT_FUNC
#endif

#include "igraph.h"
#include "vertex.h"
#include <vector>
#include <stack>
#include <queue>

namespace simple_graph_library {

class AbstractGraph : IGraph {
    template<class T>
    auto _search(Vertex v) -> std::vector<Vertex>;
public:
    // cant use trailing return type for virtual functions
    std::vector<Vertex> ABSTRACT_GRAPH_EXPORT_FUNC dfs(Vertex v) final;
    std::vector<Vertex> ABSTRACT_GRAPH_EXPORT_FUNC bfs(Vertex v) final;
    std::vector<Vertex> ABSTRACT_GRAPH_EXPORT_FUNC euler_tour() final;
};
}// namespace simple_graph_library


template<class T>
auto simple_graph_library::AbstractGraph::_search(Vertex v) -> std::vector<Vertex> {
    /**
     * 1st iterative algorithm from wiki
     * https://en.wikipedia.org/wiki/Depth-first_search
     * ====================================================================
     * procedure DFS_iterative(G, v) is
     *      let S be a stack
     *      S.push(v)
     *      while S is not empty do
     *          v = S.pop()
     *          if v is not labeled as discovered then
     *              label v as discovered
     *              for all edges from v to w in G.adjacentEdges(v) do 
     *                  S.push(w)
     * ====================================================================
     * if stack is replaced with queue we'll get bfs
     */
    T collection;
    collection.push(v);
    std::vector<Vertex> discovered;
    while (!collection.empty()) {
        v = collection.pop();
        if (std::none_of(discovered.begin(), discovered.end(),
                [&] (Vertex i) { return i <=> v == 0; })) {// idk why i == v didnt work
            discovered.push_back(v);
            for (auto w : this->neighbours(v)) {
                collection.push(w);
            }
        }
    }
    return discovered;
}

#endif