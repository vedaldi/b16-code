add_executable(array_driver
  array_driver.cpp
  array.hpp
  utils.hpp)

add_executable(counting_sort_driver
  counting_sort_driver.cpp
  utils.hpp)

add_executable(insertion_sort_driver
  insertion_sort_driver.cpp
  insertion_sort.hpp
  utils.hpp)

add_executable(list_driver
  list_driver.cpp
  list.hpp
  utils.hpp)

add_executable(merge_sort_driver
  merge_sort_driver.cpp
  merge_sort.hpp
  utils.hpp)

add_executable(queue_driver
  queue_driver.cpp
  queue.hpp
  utils.hpp)

add_executable(stack_driver
  stack_driver.cpp
  stack.hpp)

if(BUILD_EXERCISES)
  add_executable(array_delete_driver
    array_delete_driver.cpp
    array.hpp
    array_delete.hpp
    utils.hpp)

  add_executable(list_enhanced_driver
    list_enhanced_driver.cpp
    list_enhanced.hpp
    list.hpp
    utils.hpp)

  add_executable(queue_enhanced_driver
    queue_enhanced_driver.cpp
    queue_enhanced.hpp
    queue.hpp
    utils.hpp)

  add_executable(radix_sort_driver
    radix_sort_driver.cpp
    radix_sort.hpp
    utils.hpp)

  add_executable(stack_enhanced_driver
    stack_enhanced_driver.cpp
    stack.hpp
    stack_enhanced.hpp)

  add_executable(stack_rpn_driver
    stack_rpn_driver.cpp
    stack.hpp
    stack_rpn.hpp)
endif()