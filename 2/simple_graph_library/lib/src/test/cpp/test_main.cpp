#include "adjacency_list_graph_test.h"
#include "adjacency_matrix_graph_test.h"

#include <iostream>

auto main() -> int {
    auto sgl_ascii = R"(
   _____  ______ __ 
  / ___/ / ____// /  
  \__ \ / / __ / /  
 ___/ // /_/ // /___
/____/ \____//_____/

)";// tabs are preserved in raw strings
    std::cout << sgl_ascii;

    adjacency_matrix_graph_tests();
    adjacency_list_graph_tests();
}