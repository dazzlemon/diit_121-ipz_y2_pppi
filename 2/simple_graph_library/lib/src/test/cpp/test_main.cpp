#include "adjacency_list_graph_test.h"

#include <iostream>

auto main() -> int {
    adjacency_list_graph_tests();
    auto sgl_ascii = R"(
   _____  ______ __ 
  / ___/ / ____// /  
  \__ \ / / __ / /  
 ___/ // /_/ // /___
/____/ \____//_____/

= BUILD SUCCESSFUL! =

)";// tabs are preserved in raw strings
    std::cout << sgl_ascii;
}