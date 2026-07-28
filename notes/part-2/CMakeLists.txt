include_directories("../../examples/part-1")
include_directories("../../examples/part-2")
include_directories("../../notes/part-2")

add_executable(binary_search_tree_driver
  binary_search_tree_driver.cpp)

add_executable(binary_tree_traversal_driver
  binary_tree_traversal_driver.cpp)

add_executable(heap_driver
  heap_driver.cpp
  heap.hpp)

add_executable(priority_queue_driver
  priority_queue_driver.cpp
  priority_queue.hpp
  heap.hpp)

add_executable(binary_tree_complete_driver
  binary_tree_complete_driver.cpp
  binary_tree_complete.hpp)