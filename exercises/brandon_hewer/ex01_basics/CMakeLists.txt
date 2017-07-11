cmake_minimum_required ( VERSION 2.8.5 )

###############################################################################
# Setup
###############################################################################
# Name
project ( WordCounter )

# Find custom cmake modules
set ( CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../CMake")

# Common setup
include ( CommonSetup )
include_directories ( inc )

###############################################################################
# Executable
###############################################################################

set ( SRC_FILES
  src/main.cpp
  # add any additional source files here
)

set ( HDR_FILES
  inc/main.h
  # add any additional header files here
)

add_executable ( WordCounter ${SRC_FILES} ${HDR_FILES} )
