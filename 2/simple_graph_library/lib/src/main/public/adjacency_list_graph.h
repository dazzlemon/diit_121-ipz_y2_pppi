#ifndef ADJACENCY_LIST_GRAPH_H
#define ADJACENCY_LIST_GRAPH_H

#ifdef _WIN32
#define ADJACENCY_LIST_GRAPH_EXPORT_FUNC __declspec(dllexport)
#else
#define ADJACENCY_LIST_GRAPH_EXPORT_FUNC
#endif

#include "abstract_graph.h"

namespace simple_graph_library {
class AdjacencyListGraph : AbstractGraph {

};
}// namespace simple_graph_library

#endif