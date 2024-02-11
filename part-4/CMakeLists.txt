include_directories("../part-1")
include_directories("../part-2")

add_executable(shortest_paths_bf_driver
  shortest_paths_bf_driver.cpp
  shortest_paths_bf.cpp
  shortest_paths_bf.hpp
  graph.cpp
  graph.hpp)

add_executable(shortest_paths_dijkstra_driver
  shortest_paths_dijkstra_driver.cpp
  shortest_paths_dijkstra.cpp
  shortest_paths_dijkstra_priority.cpp
  shortest_paths_dijkstra.hpp
  graph.cpp
  graph.hpp)

add_executable(shortest_paths_fw_driver
  shortest_paths_fw_driver.cpp
  shortest_paths_fw.cpp
  shortest_paths_fw.hpp
  graph.cpp
  graph.hpp)

if(BUILD_EXERCISES)
  add_executable(shortest_paths_fw_decode_driver
    shortest_paths_fw_decode_driver.cpp
    shortest_paths_decode.hpp
    shortest_paths_fw.cpp
    shortest_paths_fw.hpp
    graph.cpp
    graph.hpp)

  add_executable(shortest_paths_sparse_driver
    shortest_paths_sparse_driver.cpp
    shortest_paths_sparse.cpp
    shortest_paths_sparse.hpp
    graph.cpp
    graph.hpp)
endif()
