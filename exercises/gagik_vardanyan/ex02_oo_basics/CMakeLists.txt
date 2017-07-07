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
  src/ShapeSorter.cpp
  src/Circle.cpp
  src/Square.cpp
  src/Rectangle.cpp
  src/Triangle.cpp
	
  # add any additional source files here
)

set ( HDR_FILES
  src/include/Shape.h
  src/include/Triangle.h
  src/include/Square.h
  src/include/Rectangle.h
  src/include/Circle.h
  src/include/ShapeSorter.h

  # add any additional header files here
)

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )

add_definitions( -D_USE_MATH_DEFINES)
