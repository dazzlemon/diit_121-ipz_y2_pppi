#ifndef ABSTRACT_GRAPH_DETAILS_H
#define ABSTRACT_GRAPH_DETAILS_H

#include "vertex.h"
#include <stack>
#include <queue>

namespace details {

template<class T>
class StackWrapper {
    std::stack<simple_graph_library::Vertex<T>> s;
public:
    void push(const simple_graph_library::Vertex<T>& v) {
        s.push(v);
    }

    simple_graph_library::Vertex<T> pop() {
        auto v = s.top();
        s.pop();
        return v;
    }

    bool empty() {
        return s.empty();
    }
};


template<class T>
class QueueWrapper {
    std::queue<simple_graph_library::Vertex<T>> q;
public:
    void push(const simple_graph_library::Vertex<T>& v) {
        q.push(v);
    }

    simple_graph_library::Vertex<T> pop() {
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