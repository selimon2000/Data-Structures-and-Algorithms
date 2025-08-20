cmake_minimum_required(VERSION 3.10)

# Set project name
project(Linked_List_Project)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(${PROJECT_NAME}
    main.cpp
    linked_list.tpp
    linked_list.h
)