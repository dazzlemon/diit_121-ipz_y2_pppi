#ifndef VERTEX_H
#define VERTEX_H

#include <compare>
#include <concepts>

namespace simple_graph_library {

/**
 * Just a wrapper for T dataclass, T includes both Key&Value
 */
template<class T>
    requires std::totally_ordered<T>
class Vertex {
public:
    Vertex() {}// tmp


    Vertex(const T& data) {
        this->data = data;
    }

    T data;

    friend auto operator<=><>(const Vertex& lhs, const Vertex<T>& rhs)
        -> std::strong_ordering;
};

template<class T>
auto operator<=>(const Vertex<T>& lhs, const Vertex<T>& rhs)
        -> std::strong_ordering {
    return lhs.data <=> rhs.data;
}
}// namespace simple_graph_library
#endif