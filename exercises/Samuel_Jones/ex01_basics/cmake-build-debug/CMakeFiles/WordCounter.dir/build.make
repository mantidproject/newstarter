# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/sam/clion-2018.1.5/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/sam/clion-2018.1.5/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sam/Repos/newstarter/exercises/Samuel_Jones/ex01_basics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sam/Repos/newstarter/exercises/Samuel_Jones/ex01_basics/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/WordCounter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/WordCounter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WordCounter.dir/flags.make

CMakeFiles/WordCounter.dir/src/main.cpp.o: CMakeFiles/WordCounter.dir/flags.make
CMakeFiles/WordCounter.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sam/Repos/newstarter/exercises/Samuel_Jones/ex01_basics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WordCounter.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WordCounter.dir/src/main.cpp.o -c /home/sam/Repos/newstarter/exercises/Samuel_Jones/ex01_basics/src/main.cpp

CMakeFiles/WordCounter.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WordCounter.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sam/Repos/newstarter/exercises/Samuel_Jones/ex01_basics/src/main.cpp > CMakeFiles/WordCounter.dir/src/main.cpp.i

CMakeFiles/WordCounter.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WordCounter.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sam/Repos/newstarter/exercises/Samuel_Jones/ex01_basics/src/main.cpp -o CMakeFiles/WordCounter.dir/src/main.cpp.s

CMakeFiles/WordCounter.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/WordCounter.dir/src/main.cpp.o.requires

CMakeFiles/WordCounter.dir/src/main.cpp.o.provides: CMakeFiles/WordCounter.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/WordCounter.dir/build.make CMakeFiles/WordCounter.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/WordCounter.dir/src/main.cpp.o.provides

CMakeFiles/WordCounter.dir/src/main.cpp.o.provides.build: CMakeFiles/WordCounter.dir/src/main.cpp.o


# Object files for target WordCounter
WordCounter_OBJECTS = \
"CMakeFiles/WordCounter.dir/src/main.cpp.o"

# External object files for target WordCounter
WordCounter_EXTERNAL_OBJECTS =

bin/WordCounter: CMakeFiles/WordCounter.dir/src/main.cpp.o
bin/WordCounter: CMakeFiles/WordCounter.dir/build.make
bin/WordCounter: CMakeFiles/WordCounter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sam/Repos/newstarter/exercises/Samuel_Jones/ex01_basics/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/WordCounter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WordCounter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WordCounter.dir/build: bin/WordCounter

.PHONY : CMakeFiles/WordCounter.dir/build

CMakeFiles/WordCounter.dir/requires: CMakeFiles/WordCounter.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/WordCounter.dir/requires

CMakeFiles/WordCounter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WordCounter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WordCounter.dir/clean

CMakeFiles/WordCounter.dir/depend:
	cd /home/sam/Repos/newstarter/exercises/Samuel_Jones/ex01_basics/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sam/Repos/newstarter/exercises/Samuel_Jones/ex01_basics /home/sam/Repos/newstarter/exercises/Samuel_Jones/ex01_basics /home/sam/Repos/newstarter/exercises/Samuel_Jones/ex01_basics/cmake-build-debug /home/sam/Repos/newstarter/exercises/Samuel_Jones/ex01_basics/cmake-build-debug /home/sam/Repos/newstarter/exercises/Samuel_Jones/ex01_basics/cmake-build-debug/CMakeFiles/WordCounter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WordCounter.dir/depend

