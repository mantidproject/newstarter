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
  src/Shape.cpp
  src/Circle.cpp
  src/Rectangle.cpp
  src/Square.cpp
  src/Triangle.cpp
  src/ShapeSorter.cpp
  # add any additional source files here
)

set ( HDR_FILES
  # add any additional header files here
  src/Shape.h
  src/Circle.h
  src/Rectangle.h
  src/Square.h
  src/Triangle.h
  src/ShapeSorter.h
)

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
