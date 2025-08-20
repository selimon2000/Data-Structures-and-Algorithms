# Set the minimum required CMake version
# We'll use 3.12 since it provides good modern CMake features while maintaining compatibility
cmake_minimum_required(VERSION 3.12)

# Name your project and set the languages used
# CXX refers to C++
project(Trie VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard requirements
# Using C++20 since you're working with modern features like ranges
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create the executable target
# We specify main.cpp as the entry point
add_executable(trie_program
    main.cpp
)

# Set the include directories
# This allows the compiler to find your header files
target_include_directories(trie_program PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Since we're using a template implementation file (trie.tpp),
# we don't need to list it directly in the sources.
# The header file will include it automatically.