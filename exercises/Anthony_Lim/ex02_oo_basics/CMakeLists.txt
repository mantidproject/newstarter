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
  src/shape.cpp
  src/rectangle.cpp
  src/triangle.cpp
  src/circle.cpp
  src/shape_sorter.cpp
  # add any additional source files here
)

set ( HDR_FILES
  # add any additional header files here
  src/shape.h
  src/rectangle.h
  src/square.h
  src/circle.h
  src/triangle.h
  src/shape_sorter.h
)

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
