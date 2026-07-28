include_directories("../part-1")
include_directories("../part-2")

if(BUILD_EXERCISES)
  add_executable(shortest_paths_fw_decode_driver
    shortest_paths_fw_decode_driver.cpp
    shortest_paths_decode.hpp
    shortest_paths_fw.cpp
    shortest_paths_fw.hpp
    graph.cpp
    graph.hpp)

  add_executable(shortest_paths_bf_sparse_driver
    shortest_paths_bf_sparse_driver.cpp
    shortest_paths_bf_sparse.cpp
    shortest_paths_bf_sparse.hpp
    graph.cpp
    graph.hpp)
endif()
