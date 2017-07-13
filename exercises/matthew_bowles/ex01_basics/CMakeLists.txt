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

###############################################################################
# Executable
###############################################################################

set ( SRC_FILES
  src/Io.cpp
  src/WordManipulation.cpp
  # add any additional source files here
)

set ( HDR_FILES
  inc/Io.h
  inc/WordManipulation.h
  # add any additional header files here
)

include_directories( inc )

add_executable ( WordCounter ${SRC_FILES} ${HDR_FILES} )
