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
  src/stringManip.cpp
  src/mapFunctions.cpp
  
)

set ( HDR_FILES
  src/stringManip.h
  src/mapFunctions.h
  
)

add_executable ( WordCounter ${SRC_FILES} ${HDR_FILES} )
