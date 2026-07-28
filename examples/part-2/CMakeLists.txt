include_directories("../part-1")

if(BUILD_EXERCISES)
  add_executable(binary_search_tree_min_max_driver
    binary_search_tree_min_max_driver.cpp
    binary_search_tree_min_max.hpp
    binary_search_tree.hpp
    binary_tree.hpp
    binary_tree_print.hpp)

  add_executable(binary_tree_with_parent_driver
    binary_tree_with_parent_driver.cpp
    binary_tree_with_parent.hpp
    binary_tree.hpp
    binary_tree_traversal.hpp
    binary_tree_print.hpp)
endif()
