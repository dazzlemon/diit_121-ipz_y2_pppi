#ifndef VERTEX_H
#define VERTEX_H

#include <compare>

class Vertex {
public:
    int data;// tmp

    auto operator<=>(const Vertex& other) -> std::strong_ordering;
};
#endif