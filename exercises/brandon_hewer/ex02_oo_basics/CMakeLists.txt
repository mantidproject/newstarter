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
  src/Circle.cpp
  src/Square.cpp
  src/Rectangle.cpp
  src/Triangle.cpp
  src/ShapeSorter.cpp
)

set ( HDR_FILES
  src/Circle.h
  src/Square.h
  src/Rectangle.h
  src/Triangle.h
  src/ShapeSorter.h
)

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
