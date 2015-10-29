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
  # add any additional source files here
  src/shape.cpp
  src/rectangle.cpp 
  src/square.cpp
  src/circle.cpp 
  src/triangle.cpp
)

set ( HDR_FILES
  # add any additional header files here
  src/shape.h
  src/rectangle.h 
  src/square.h
  src/circle.h 
  src/triangle.h   
)

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
