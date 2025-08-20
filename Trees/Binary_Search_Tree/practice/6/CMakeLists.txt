cmake_minimum_required(VERSION 3.10)

# Project name
project(BinarySearchTree)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(BinarySearchTree main.cpp)

# Include the header file directory (if necessary for binary_search_tree.h)
target_include_directories(BinarySearchTree PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})