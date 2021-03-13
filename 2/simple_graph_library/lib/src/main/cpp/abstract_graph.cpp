#include "abstract_graph.h"
#include "vertex.h"
#include <stack>
#include <queue>
#include <algorithm>

class _StackWrapper {
    std::stack<Vertex> s;
public:
    void push(const Vertex& v) {
        s.push(v);
    }

    Vertex pop() {
        auto v = s.top();
        s.pop();
        return v;
    }

    bool empty() {
        return s.empty();
    }
};


class _QueueWrapper {
    std::queue<Vertex> q;
public:
    void push(const Vertex& v) {
        q.push(v);
    }

    Vertex pop() {
        auto v = q.front();
        q.pop();
        return v;
    }

    bool empty() {
        return q.empty();
    }
};


auto AbstractGraph::dfs(Vertex v) -> std::vector<Vertex> {
    return this->_search<_StackWrapper>(v);
}


auto AbstractGraph::bfs(Vertex v) -> std::vector<Vertex> {
    return this->_search<_QueueWrapper>(v);
}


template<class T>
auto AbstractGraph::_search(Vertex v) -> std::vector<Vertex> {
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