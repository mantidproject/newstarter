cmake_minimum_required ( VERSION 2.8.5 )

###############################################################################
# Setup
###############################################################################
# Name
project ( WordCounter )

# Find custom cmake modules
set ( CMAKE_MODULE_PATH "../../../CMake")

# Common setup


###############################################################################
# Executable
###############################################################################

set ( SRC_FILES
        src/main.cpp
  # add any additional source files here
)

set ( HDR_FILES
        ../ex02_oo_basics/src/Rectangle.cpp
        ../ex02_oo_basics/src/Rectangle.h
        ../ex02_oo_basics/src/Circle.cpp
        ../ex02_oo_basics/src/Circle.h

        # add any additional header files here
)

add_executable ( WordCounter ${SRC_FILES} ${HDR_FILES})
