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
include_directories(inc)

###############################################################################
# Executable
###############################################################################

set ( SRC_FILES
  src/main.cpp
  src/Circle.cpp
  src/Square.cpp
  src/Rectangle.cpp
  src/Triangle.cpp
  src/ShapeSorter.cpp
)

set ( HDR_FILES
  inc/Circle.h
  inc/Square.h
  inc/Shape.h
  inc/Rectangle.h
  inc/Triangle.h
  inc/ShapeSorter.h
)

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
