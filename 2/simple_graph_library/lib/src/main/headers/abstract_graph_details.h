#ifndef ABSTRACT_GRAPH_DETAILS_H
#define ABSTRACT_GRAPH_DETAILS_H

#include <stack>
#include <queue>

namespace details {

template<class T>
class IPushPopCollection {
public:
    virtual void push(const T& t) = 0;
    virtual auto pop() -> T = 0;
    virtual bool empty() = 0;
};


template<class T>
class StackWrapper : public IPushPopCollection<T> {
    std::stack<T> s;
public:
    void push(const T& t) final {
        s.push(t);
    }

    T pop() final {
        auto t = s.top();
        s.pop();
        return t;
    }

    bool empty() final {
        return s.empty();
    }
};


template<class T>
class QueueWrapper : public IPushPopCollection<T> {
    std::queue<T> q;
public:
    void push(const T& t) final {
        q.push(t);
    }

    T pop() final {
        auto t = q.front();
        q.pop();
        return t;
    }

    bool empty() final {
        return q.empty();
    }
};
}// namespace details
#endif