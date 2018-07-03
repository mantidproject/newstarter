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
  src/Rectangle.cpp
  src/Circle.cpp
  src/Triangle.cpp
  # add any additional source files here
)

set ( HDR_FILES
  # add any additional header files here
  src/Shape.h
  src/Square.h
  src/Rectangle.h
  src/Circle.h
  src/Triangle.h
)

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
