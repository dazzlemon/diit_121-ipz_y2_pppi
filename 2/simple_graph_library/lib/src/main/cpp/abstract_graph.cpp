#include "abstract_graph.h"
#include "vertex.h"
#include <stack>
#include <queue>
#include <algorithm>

auto AbstractGraph::dfs(Vertex v) -> std::vector<Vertex> {
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
     */
    std::stack<Vertex> s;
    s.push(v);
    std::vector<Vertex> discovered;
    while (!s.empty()) {
        v = s.top(); s.pop();// single action actually
        if (std::none_of(discovered.begin(), discovered.end(),
                [&] (Vertex i) { return i <=> v == 0; })) {// idk why i == v didnt work
            discovered.push_back(v);
            for (auto w : this->neighbours(v)) {
                s.push(w);
            }
        }
    }
    return discovered;
}


auto AbstractGraph::bfs(Vertex v) -> std::vector<Vertex> {
    /**
     * same algo as dfs
     * but with queue
     * can't factor out because stack and queue have different interfaces
     */
    std::queue<Vertex> q;/////////////////////////////////////////////////////////////// different from dfs
    q.push(v);
    std::vector<Vertex> discovered;
    while (!q.empty()) {
        v = q.front(); q.pop();// single action actually//////////////////////////////// different from dfs
        if (std::none_of(discovered.begin(), discovered.end(),
                [&] (Vertex i) { return i <=> v == 0; })) {// idk why i == v didnt work
            discovered.push_back(v);
            for (auto w : this->neighbours(v)) {
                q.push(w);
            }
        }
    }
    return discovered;
}