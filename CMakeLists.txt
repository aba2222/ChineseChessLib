cmake_minimum_required(VERSION 3.4...3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(chinese_chess_lib)

add_subdirectory(pybind11-3.0.0)

include_directories(${CMAKE_SOURCE_DIR}/include)

pybind11_add_module(chinese_chess_lib py_interface.cpp src/move.cpp src/rule.cpp)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
# target_compile_definitions(chinese_chess_lib
#                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})