cmake_minimum_required(VERSION 3.5)

project(tree_shell LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ../../basic_shell
)
add_library(basicshell ${BASIC_SHELL})
target_include_directories(${BASIC_SHELL} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}../../basic_shell)

add_executable(tree_shell main.cpp
tree/coordinator/coordinator.hpp
tree/coordinator/node.hpp
tree/tree_shell.hpp

tree/coordinator/coordinator.cpp
tree/coordinator/find_child.cpp
tree/coordinator/find_node.cpp
tree/coordinator/load_node.cpp
tree/coordinator/node.cpp
tree/coordinator/process_tests.cpp
tree/coordinator/split_string.cpp
tree/tree_shell.cpp
tree/about.cpp
tree/find.cpp
tree/list.cpp
tree/load.cpp
tree/register_defaults.cpp
tree/run.cpp
)
