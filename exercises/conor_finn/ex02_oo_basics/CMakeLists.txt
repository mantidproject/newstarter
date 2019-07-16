cmake_minimum_required ( VERSION 2.8.5 )

###############################################################################
# Setup
###############################################################################
# Name
project ( Shapes )

# Find custom cmake modules
set ( CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../CMake")

# Common setup
include ( CommonSetup )

###############################################################################
# Executable
###############################################################################

set ( SRC_FILES
  src/main.cpp
	src/circle.cpp
	src/rectangle.cpp
	src/shape.cpp
	src/shapeSorter.cpp
	src/square.cpp
	src/triangle.cpp
  # add any additional source files here
)

set ( HDR_FILES
	src/circle.h
	src/rectangle.h
	src/shape.h
	src/shapeSorter.h
	src/square.h
	src/triangle.h
  # add any additional header files here
)

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
