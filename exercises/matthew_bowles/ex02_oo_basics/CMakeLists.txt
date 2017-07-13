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
  src/Square.cpp
  src/Circle.cpp
  src/Rectangle.cpp
  src/Triangle.cpp
  src/ShapeSorter.cpp
  # add any additional source files here
)

set ( HDR_FILES
  inc/Shape.h
  inc/Square.h
  inc/Circle.h
  inc/Rectangle.h
  inc/Triangle.h
  inc/ShapeSorter.h
  # add any additional header files here
)

include_directories( inc )

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
