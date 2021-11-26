cmake_minimum_required(VERSION 3.14)

project(Hello_World)

# Find custom cmake modules
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../CMake")

# Common setup
include(CommonSetup)

# ##############################################################################
# Executable
# ##############################################################################

set(SRC_FILES hello_world.cpp)

add_executable(hello_world ${SRC_FILES} ${HDR_FILES})
