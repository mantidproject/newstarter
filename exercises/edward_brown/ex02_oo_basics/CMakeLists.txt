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
  src/Circle.cpp
  src/Rectangle.cpp
  src/Square.cpp
  src/Triangle.cpp
  src/ShapeSorter.cpp
  src/ShapeType.cpp
  # add any additional source files here
)

set ( HDR_FILES
  include/ShapeType.h
  include/Circle.h
  include/Rectangle.h
  include/Shape.h
  include/ShapeSorter.h
  include/Square.h
  include/StdMakeUnique.h
  include/Triangle.h
  # add any additional header files here
)

add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
target_include_directories(Shapes PUBLIC include)
