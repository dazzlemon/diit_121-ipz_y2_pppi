#ifndef ABSTRACT_GRAPH_DETAILS_H
#define ABSTRACT_GRAPH_DETAILS_H

#include "vertex.h"
#include <stack>
#include <queue>

namespace details {
class StackWrapper {
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


class QueueWrapper {
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
}// namespace details
#endif