#include "abstract_graph.h"
#include "vertex.h"
#include <stack>
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
     * the only algorithm on wiki
     * https://en.wikipedia.org/wiki/Breadth-first_search
     * ========================================================
     * procedure BFS(G, root) is
     *      let Q be a queue
     *      label root as discovered
     *      Q.enqueue(root)
     *      while Q is not empty do
     *      v := Q.dequeue()
     *      if v is the goal then
     *          return v
     *      for all edges from v to w in G.adjacentEdges(v) do
     *          if w is not labeled as discovered then
     *              label w as discovered
     *              Q.enqueue(w)
     * ========================================================
     */
    return {};
}