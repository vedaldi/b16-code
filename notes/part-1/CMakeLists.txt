include_directories(../../examples/part-1)

add_executable(insertion_sort_driver
  insertion_sort_driver.cpp
  insertion_sort.hpp)

add_executable(stack_driver
  stack_driver.cpp
  stack.hpp)

add_executable(radix_sort_driver
  radix_sort_driver.cpp
  radix_sort.hpp)

add_executable(stack_enhanced_driver
  stack_enhanced_driver.cpp
  stack.hpp
  stack_enhanced.hpp)

add_executable(stack_rpn_driver
  stack_rpn_driver.cpp
  stack.hpp
  stack_rpn.hpp)

add_executable(stack_move_driver
  stack_move_driver.cpp)
  
add_executable(counting_sort_driver
  counting_sort_driver.cpp)

add_executable(merge_sort_driver
  merge_sort_driver.cpp
  merge_sort.hpp)

add_executable(queue_driver
  queue_driver.cpp
  queue.hpp)

add_executable(queue_enhanced_driver
  queue_enhanced_driver.cpp
  queue_enhanced.hpp
  queue.hpp)