include_directories("../../examples/part-1")
include_directories("../../examples/part-2")
include_directories("../part-2")
include_directories("../../examples/part-4")

add_executable(graph_driver
  graph_driver.cpp
  ../../examples/part-4/graph.cpp)

add_executable(shortest_paths_bf_driver
  shortest_paths_bf_driver.cpp
  shortest_paths_bf.cpp
  shortest_paths_bf.hpp
  ../../examples/part-4/graph.cpp)

add_executable(shortest_paths_dijkstra_driver
  shortest_paths_dijkstra_driver.cpp
  shortest_paths_dijkstra.cpp
  shortest_paths_dijkstra_priority.cpp
  shortest_paths_dijkstra.hpp
  ../../examples/part-4/graph.cpp
  ../../examples/part-4/graph.hpp)

add_executable(shortest_paths_fw_driver
  shortest_paths_fw_driver.cpp
  ../../examples/part-4/shortest_paths_fw.cpp
  ../../examples/part-4/shortest_paths_fw.hpp
  ../../examples/part-4/graph.cpp
  ../../examples/part-4/graph.hpp)

add_executable(shortest_paths_dijkstra_sparse_driver
  shortest_paths_dijkstra_sparse_driver.cpp
  shortest_paths_dijkstra_sparse.cpp
  shortest_paths_dijkstra_sparse.hpp
  ../../examples/part-4/graph.cpp
  ../../examples/part-4/graph.hpp)
