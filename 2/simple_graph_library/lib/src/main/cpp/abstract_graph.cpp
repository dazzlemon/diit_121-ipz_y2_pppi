#include "abstract_graph.h"

namespace simple_graph_library {

auto AbstractGraph::dfs(Vertex v) -> std::vector<Vertex> {
    return this->_search<_StackWrapper>(v);
}


auto AbstractGraph::bfs(Vertex v) -> std::vector<Vertex> {
    return this->_search<_QueueWrapper>(v);
}
}// simple_graph_library
