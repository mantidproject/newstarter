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
)

set ( HDR_FILES
        src/ShapeSorter.cpp
        src/ShapeSorter.h
        src/Shape.h
        src/Square.cpp
        src/Square.h
        src/Triangle.cpp
        src/Triangle.h
        # add any additional header files here
)


add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
