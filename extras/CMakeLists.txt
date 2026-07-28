include_directories("../examples/part-1")
include_directories("../examples/part-3")
include_directories("../notes/part-1")

add_executable(array_insert_movable_driver
  array_insert_movable_driver.cpp
  array_insert_movable.hpp
  probes.hpp)



if(BUILD_EXERCISES) 
  add_executable(list_iterator_driver
    list_iterator_driver.cpp
    list_iterator.hpp)
endif()
