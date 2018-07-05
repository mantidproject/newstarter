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
  src/Rectangle.cpp
  src/Shapes.cpp
  src/square.cpp
  src/Triangle.cpp
  # add any additional source files here
)

set ( HDR_FILES
  src/Rectangle.h
  src/Shapes.h
  src/Triangle.h
  src/Square.h
  # add any additional header files here
)

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
