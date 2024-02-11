include_directories("../part-1")

add_executable(binary_search_tree_driver
  binary_search_tree_driver.cpp
  binary_search_tree.hpp
  binary_tree.hpp
  binary_tree_print.hpp)

add_executable(binary_tree_complete_driver
  binary_tree_complete_driver.cpp
  binary_tree_complete.hpp
  binary_tree_print.hpp
  binary_tree_traversal.hpp)

add_executable(binary_tree_traversal_driver
  binary_tree_traversal_driver.cpp
  binary_tree.hpp
  binary_tree_traversal.hpp
  binary_tree_print.hpp)

add_executable(heap_driver
  heap_driver.cpp
  heap.hpp
  binary_tree_complete.hpp
  binary_tree.hpp
  binary_tree_print.hpp)

add_executable(priority_queue_driver
  priority_queue_driver.cpp
  priority_queue.hpp
  heap.hpp
  binary_tree_complete.hpp)

if(BUILD_EXERCISES)
  add_executable(binary_search_tree_enhanced_driver
    binary_search_tree_enhanced_driver.cpp
    binary_search_tree_enhanced.hpp
    binary_search_tree.hpp
    binary_tree.hpp
    binary_tree_print.hpp)

  add_executable(binary_tree_enhanced_driver
    binary_tree_enhanced_driver.cpp
    binary_tree_enhanced.hpp
    binary_tree.hpp
    binary_tree_traversal.hpp
    binary_tree_print.hpp)
endif()
