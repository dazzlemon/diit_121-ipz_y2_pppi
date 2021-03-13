#include "vertex.h"
#include <compare>

auto Vertex::operator<=>(const Vertex& other) -> std::strong_ordering {
    return this->data <=> other.data;
}