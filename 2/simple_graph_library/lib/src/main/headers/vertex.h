#ifndef VERTEX_H
#define VERTEX_H

#include <compare>

class Vertex {
public:
    int data;// tmp, need to replace with actual data type

    auto operator<=>(const Vertex& other) -> std::strong_ordering;
};
#endif