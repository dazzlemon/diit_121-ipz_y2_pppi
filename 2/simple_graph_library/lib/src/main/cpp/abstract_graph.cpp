#include "abstract_graph.h"
#include "abstract_graph_details.h"

namespace simple_graph_library {

auto AbstractGraph::dfs(Vertex v) -> std::vector<Vertex> {
    return this->_search<details::StackWrapper>(v);
}


auto AbstractGraph::bfs(Vertex v) -> std::vector<Vertex> {
    return this->_search<details::QueueWrapper>(v);
}


auto AbstractGraph::is_eulerian() -> bool {
    return true;
}


auto AbstractGraph::euler_tour() -> std::vector<Vertex> {
    return {};
}
}// namespace simple_graph_library
