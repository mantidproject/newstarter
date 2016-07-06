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

file(GLOB shapes_SRC
    "src/*.cpp"
)


file(GLOB shapes_HDR
    "src/*.h"
)
# Probably not the correct way of completing this but better than retyping everything

add_executable ( Shapes ${shapes_SRC} ${shapes_HDR} )
