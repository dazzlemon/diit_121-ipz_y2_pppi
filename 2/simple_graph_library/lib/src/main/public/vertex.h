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
    T data;// tmp, need to replace with actual data type

    auto operator<=>(const Vertex& other) -> std::strong_ordering {
        return this->data <=> other.data;
    }
};
}// namespace simple_graph_library
#endif