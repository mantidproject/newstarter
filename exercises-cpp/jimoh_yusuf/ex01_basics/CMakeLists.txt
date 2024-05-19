<<<<<<< HEAD
cmake_minimum_required ( VERSION 3.5)
=======
cmake_minimum_required ( VERSION 2.8.5 )
>>>>>>> e139231 (completed exercise2 -read a sample text, clean the data, count the number of words and write to file)

###############################################################################
# Setup
###############################################################################
# Name
project ( WordCounter )

# Find custom cmake modules
<<<<<<< HEAD
set ( CMAKE_MODULE_PATH "../../../CMake")

# Common setup

=======
set ( CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../CMake")

# Common setup
include ( CommonSetup )
>>>>>>> e139231 (completed exercise2 -read a sample text, clean the data, count the number of words and write to file)

###############################################################################
# Executable
###############################################################################

set ( SRC_FILES
<<<<<<< HEAD
        src/main.cpp
=======
  src/main.cpp
>>>>>>> e139231 (completed exercise2 -read a sample text, clean the data, count the number of words and write to file)
  # add any additional source files here
)

set ( HDR_FILES
<<<<<<< HEAD


        # add any additional header files here
)

add_executable ( WordCounter ${SRC_FILES} ${HDR_FILES})
=======
  # add any additional header files here
)

add_executable ( WordCounter ${SRC_FILES} ${HDR_FILES} )
>>>>>>> e139231 (completed exercise2 -read a sample text, clean the data, count the number of words and write to file)
