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
        ../ex02_oo_basics/ShapeSorter.cpp
        ../ex02_oo_basics/ShapeSorter.h
        ../ex02_oo_basics/Shape.h
        ../ex02_oo_basics/Square.cpp
        ../ex02_oo_basics/Square.h
        ../ex02_oo_basics/Triangle.cpp
        ../ex02_oo_basics/Triangle.h
        # add any additional header files here
)


add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
