cmake_minimum_required(VERSION 3.10)

# Project name
project(GameCounter)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(GameCounter main.cpp)

# Specify the path for the data.txt file, assuming it's in the same directory as the main.cpp file
configure_file(${CMAKE_SOURCE_DIR}/data.txt ${CMAKE_BINARY_DIR}/data.txt COPYONLY)