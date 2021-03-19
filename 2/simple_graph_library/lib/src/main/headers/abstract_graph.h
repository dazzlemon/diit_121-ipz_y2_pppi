#ifndef ABSTRACT_GRAPH_H
#define ABSTRACT_GRAPH_H

#include "igraph.h"
#include "vertex.h"
#include "abstract_graph_details.h"
#include <vector>
#include <concepts>

namespace simple_graph_library {

template<class T>
class AbstractGraph : public IGraph<T> {
    template<template<class> class C>
        requires std::derived_from<
            C<Vertex<T>>,
            details::IPushPopCollection<Vertex<T>>
        >
    auto _search(Vertex<T> v) -> std::vector<Vertex<T>> {
        /**
         * 1st iterative algorithm from wiki
         * https://en.wikipedia.org/wiki/Depth-first_search
         * =====================================================================
         * procedure DFS_iterative(G, v) is
         *      let S be a stack
         *      S.push(v)
         *      while S is not empty do
         *          v = S.pop()
         *          if v is not labeled as discovered then
         *              label v as discovered
         *              for all edges from v to w in G.adjacentEdges(v) do 
         *                  S.push(w)
         * =====================================================================
         * if stack is replaced with queue we'll get bfs
         */
        C<Vertex<T>> collection;
        collection.push(v);
        std::vector<Vertex<T>> discovered;
        while (!collection.empty()) {
            v = collection.pop();
            if (std::none_of(discovered.begin(), discovered.end(),
                    [&] (Vertex<T> i) { return i <=> v == 0; })) {
                    // idk why i == v didnt work
                discovered.push_back(v);
                for (auto w : this->neighbours(v)) {
                    collection.push(w);
                }
            }
        }
        return discovered;
    }

protected:
    // both needed for euler_tour to work
    virtual auto _even_degree_node() -> Vertex<T> = 0;
    virtual auto _odd_degree_node() -> Vertex<T> = 0;
    virtual auto _n_odd_degree() -> size_t = 0;

public:
    // cant use trailing return type for virtual functions
    auto dfs(Vertex<T> v) -> std::vector<Vertex<T>> final {
        return this->_search<details::StackWrapper>(v);
    }


    auto bfs(Vertex<T> v) -> std::vector<Vertex<T>> final {
        return this->_search<details::QueueWrapper>(v);
    }


    auto euler_tour() -> std::vector<Vertex<T>> final {
        /**
         * http://www.graph-magics.com/articles/euler.php
         * =====================================================================
         * 1. Start with an empty stack and an empty circuit (eulerian path).
         *      - If all vertices have even degree - choose any of them.
         *      - If there are exactly 2 vertices having an odd degree
         *      -       choose one of them.
         *      - Otherwise no euler circuit or path exists.
         * 2.
         * If current vertex has no neighbors
         *      add it to circuit,
         *      remove the last vertex from the stack
         *      and set it as the current one.
         * Otherwise (in case it has neighbors)
         *      add the vertex to the stack,
         *      take any of its neighbors, remove the edge between
         *      selected neighbor and that vertex,
         *      and set that neighbor as the current vertex.
         * 3. Repeat step 2 until the current vertex has no more neighbors
         *    and the stack is empty.
         * 
         * Note that obtained
         * circuit will be in reverse order - from end vertex to start vertex.
         * =====================================================================
         */

        std::stack<Vertex<T>> s;
        std::vector<Vertex<T>> circuit;
        
        
        auto n_odd_degree = this->_n_odd_degree();
        if (n_odd_degree != 0 && n_odd_degree != 2) {
            return {};// no euler path exists
        }
        // current vertex
        Vertex<T> v = n_odd_degree == 0 ? this->_even_degree_node()
                                        : this->_odd_degree_node();// == 2

        do {
            if (this->neighbours(v).empty()) {
                circuit.push_back(v);
                if (!s.empty()) {
                    v = s.top(); s.pop();// one action actually
                } else {
                    s.push(v);
                    // take any of v's neighbours, remove the edge between them,
                    // set v as chosen neighbour
                }
            }
        } while (!this->neighbours(v).empty() || !s.empty());
        return circuit;
    }
};
}// namespace simple_graph_library

#endif