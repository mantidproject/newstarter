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
  src/rectangle.cpp 
  src/square.cpp
  src/circle.cpp 
  src/triangle.cpp
  src/shapesorter.cpp 
  src/typetester.cpp 
  src/sidestester.cpp 
)

set ( HDR_FILES
  # add any additional header files here
  src/shape.h
  src/rectangle.h 
  src/square.h
  src/circle.h 
  src/triangle.h   
  src/shapesorter.h 
  src/ShapeTester.h
  src/typetester.h 
  src/sidestester.h 
)

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
