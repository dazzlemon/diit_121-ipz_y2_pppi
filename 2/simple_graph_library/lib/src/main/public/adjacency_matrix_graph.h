#ifndef ADJACENCY_MATRIX_GRAPH_H
#define ADJACENCY_MATRIX_GRAPH_H

#ifdef _WIN32
#define ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC __declspec(dllexport)
#else
#define ADJACENCY_MATRIX_GRAPH_EXPORT_FUNC
#endif

#include "abstract_graph.h"

namespace simple_graph_library {
class AdjacencyMatrixGraph : AbstractGraph {

};
}// namespace simple_graph_library

#endif