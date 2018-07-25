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
  src/main.cpp
  src/StringManip.cpp
  src/MapFunctions.cpp
  
)

set ( HDR_FILES
  src/StringManip.h
  src/MapFunctions.h
  
)

add_executable ( WordCounter ${SRC_FILES} ${HDR_FILES} )
