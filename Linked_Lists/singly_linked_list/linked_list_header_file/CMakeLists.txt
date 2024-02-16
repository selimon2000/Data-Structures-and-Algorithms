# The minimum version of CMake Required
cmake_minimum_required (VERSION 3.1)

# Any project name will suffice, this has connotations when using advanced CMake Features
project (simple_linked_list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Add the include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# To add executables provide the executable name followed by a list of source files
# There must be exactly one function called main in each executable
add_executable(simple_linked_list main.cpp Node.cpp)