add_executable(array_driver
  array_driver.cpp
  array.hpp
  utils.hpp)

add_executable(list_driver
  list_driver.cpp
  list.hpp
  utils.hpp)

if(BUILD_EXERCISES)
  add_executable(array_delete_driver
    array_delete_driver.cpp
    array.hpp
    array_delete.hpp
    utils.hpp)

  add_executable(list_delete_after_driver
    list_delete_after_driver.cpp
    list_delete_after.hpp
    list.hpp
    utils.hpp)
endif()