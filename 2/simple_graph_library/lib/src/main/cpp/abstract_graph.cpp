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
    /**
     * https://algorithmist.com/wiki/Euler_tour
     * ================================================
     * find_tour(u):
     *      for each edge e=(u,v) in E:
     *          remove e from E
     *          find_tour(v)
     *      prepend u to tour
     * 
     * //where u is any vertex with a non-zero degree.
     * ================================================
     */
    return true;
}


auto AbstractGraph::euler_tour() -> std::vector<Vertex> {
    return {};
}
}// namespace simple_graph_library
