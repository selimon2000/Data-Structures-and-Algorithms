# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/selimon/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/selimon/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/build

# Include any dependencies generated for this target.
include CMakeFiles/simple_linked_list.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/simple_linked_list.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/simple_linked_list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simple_linked_list.dir/flags.make

CMakeFiles/simple_linked_list.dir/main.cpp.o: CMakeFiles/simple_linked_list.dir/flags.make
CMakeFiles/simple_linked_list.dir/main.cpp.o: /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/main.cpp
CMakeFiles/simple_linked_list.dir/main.cpp.o: CMakeFiles/simple_linked_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simple_linked_list.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/simple_linked_list.dir/main.cpp.o -MF CMakeFiles/simple_linked_list.dir/main.cpp.o.d -o CMakeFiles/simple_linked_list.dir/main.cpp.o -c /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/main.cpp

CMakeFiles/simple_linked_list.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_linked_list.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/main.cpp > CMakeFiles/simple_linked_list.dir/main.cpp.i

CMakeFiles/simple_linked_list.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_linked_list.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/main.cpp -o CMakeFiles/simple_linked_list.dir/main.cpp.s

CMakeFiles/simple_linked_list.dir/Node.cpp.o: CMakeFiles/simple_linked_list.dir/flags.make
CMakeFiles/simple_linked_list.dir/Node.cpp.o: /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/Node.cpp
CMakeFiles/simple_linked_list.dir/Node.cpp.o: CMakeFiles/simple_linked_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/simple_linked_list.dir/Node.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/simple_linked_list.dir/Node.cpp.o -MF CMakeFiles/simple_linked_list.dir/Node.cpp.o.d -o CMakeFiles/simple_linked_list.dir/Node.cpp.o -c /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/Node.cpp

CMakeFiles/simple_linked_list.dir/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_linked_list.dir/Node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/Node.cpp > CMakeFiles/simple_linked_list.dir/Node.cpp.i

CMakeFiles/simple_linked_list.dir/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_linked_list.dir/Node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/Node.cpp -o CMakeFiles/simple_linked_list.dir/Node.cpp.s

# Object files for target simple_linked_list
simple_linked_list_OBJECTS = \
"CMakeFiles/simple_linked_list.dir/main.cpp.o" \
"CMakeFiles/simple_linked_list.dir/Node.cpp.o"

# External object files for target simple_linked_list
simple_linked_list_EXTERNAL_OBJECTS =

simple_linked_list: CMakeFiles/simple_linked_list.dir/main.cpp.o
simple_linked_list: CMakeFiles/simple_linked_list.dir/Node.cpp.o
simple_linked_list: CMakeFiles/simple_linked_list.dir/build.make
simple_linked_list: CMakeFiles/simple_linked_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable simple_linked_list"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_linked_list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simple_linked_list.dir/build: simple_linked_list
.PHONY : CMakeFiles/simple_linked_list.dir/build

CMakeFiles/simple_linked_list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simple_linked_list.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simple_linked_list.dir/clean

CMakeFiles/simple_linked_list.dir/depend:
	cd /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/build /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/build /home/selimon/Desktop/DSA/Linked_Lists/simple_linked_list/build/CMakeFiles/simple_linked_list.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simple_linked_list.dir/depend
