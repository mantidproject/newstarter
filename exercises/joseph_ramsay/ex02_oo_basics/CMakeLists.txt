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
  src/Circle.cpp
  src/Rectangle.cpp
  src/Shape.cpp
  src/ShapeSorter.cpp
  src/Square.cpp
  src/Triangle.cpp
  src/main.cpp
)

set ( INC_FILES
  inc/Circle.h
  inc/Rectangle.h
  inc/Shape.h
  inc/ShapeSorter.h
  inc/Square.h
  inc/Triangle.h
  )

include_directories( inc )

add_executable ( Shapes ${SRC_FILES} ${INC_FILES} )
