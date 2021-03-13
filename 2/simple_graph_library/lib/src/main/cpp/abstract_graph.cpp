#include "abstract_graph.h"
#include "vertex.h"
#include <vector>
#include <queue>
#include <optional>

auto AbstractGraph::dfs(Vertex v) -> std::vector<Vertex> {
    v.is_explored = true;
    for (auto e : this->indecent_edges(v)) {
        if (!e.is_explored) {
            auto w = this->adjacent_vertex(v, e);
            if (!w.is_explored) {
                e.is_discovered = true;
                this->dfs(w);
            } else {
                e.is_back = true;
            }
        }
    }
    return {};
}


auto AbstractGraph::bfs(Vertex v) -> std::optional<Vertex> {
    auto q = std::queue<Vertex>();
    q.push(v);
    v.is_marked = true;
    while (!q.empty()) {
        auto w = q.front();
        q.pop();
        if (w.good()) {
            return std::make_optional(w);
        }
        for (auto e : this->adjacent_edges(w)) {
            auto x = this->adjacent_vertex(w, e);
            if (!x.is_marked) {
                x.is_marked = true;
                q.push(x);
            }
        }
    }
    return {};
}