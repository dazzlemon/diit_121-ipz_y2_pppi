#include <stack>
#include "abstract_graph.h"
#include "abstract_graph_details.h"

namespace simple_graph_library {

auto AbstractGraph::dfs(Vertex v) -> std::vector<Vertex> {
    return this->_search<details::StackWrapper>(v);
}


auto AbstractGraph::bfs(Vertex v) -> std::vector<Vertex> {
    return this->_search<details::QueueWrapper>(v);
}


auto AbstractGraph::euler_tour() -> std::vector<Vertex> {
    /**
     * http://www.graph-magics.com/articles/euler.php
     * ===========================================================================================
     * 1. Start with an empty stack and an empty circuit (eulerian path).
     *      - If all vertices have even degree - choose any of them.
     *      - If there are exactly 2 vertices having an odd degree - choose one of them.
     *      - Otherwise no euler circuit or path exists.
     * 2.
     * If current vertex has no neighbors
     *      add it to circuit,
     *      remove the last vertex from the stack and set it as the current one.
     * Otherwise (in case it has neighbors)
     *      add the vertex to the stack,
     *      take any of its neighbors, remove the edge between selected neighbor and that vertex,
     *      and set that neighbor as the current vertex.
     * 3. Repeat step 2 until the current vertex has no more neighbors and the stack is empty.
     * 
     * Note that obtained circuit will be in reverse order - from end vertex to start vertex.
     * ===========================================================================================
     */

    std::stack<Vertex> s;
    std::vector<Vertex> circuit;
    
    size_t n_odd_degree = 0;// count odd degree vertices
    if (n_odd_degree == 0) {
        // choose any even degree node
    } else if (n_odd_degree == 2) {
        // choose one of odd degree nodes
    } else {
        // no euler path exists
    }

    Vertex v;// current vertex

    do {
        if (this->neighbours(v).empty()) {
            circuit.push_back(v);
            if (!s.empty()) {
                v = s.top(); s.pop();// one action actually
            } else {
                s.push(v);
                // take any of v's neighbours, remove the edge between them, set v as chosen neighbour
            }
        }
    } while (!this->neighbours(v).empty() || !s.empty());

    return {};
}
}// namespace simple_graph_library
