<<<<<<< HEAD
cmake_minimum_required ( VERSION 3.5 )
=======
cmake_minimum_required ( VERSION 2.8.5 )
>>>>>>> e139231 (completed exercise2 -read a sample text, clean the data, count the number of words and write to file)

###############################################################################
# Setup
###############################################################################
# Name
project ( Shapes )

<<<<<<< HEAD
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

=======
>>>>>>> e139231 (completed exercise2 -read a sample text, clean the data, count the number of words and write to file)
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
<<<<<<< HEAD
        src/ShapeSorter.cpp
        src/ShapeSorter.h
        src/Shape.h
        src/Square.cpp
        src/Square.h
        src/Triangle.cpp
        src/Triangle.h
        src/Rectangle.cpp
        src/Rectangle.h
        src/Circle.cpp
        src/Circle.h
        # add any additional header files here
)


=======
  # add any additional header files here
)

>>>>>>> e139231 (completed exercise2 -read a sample text, clean the data, count the number of words and write to file)
add_executable ( Shapes ${SRC_FILES} ${HDR_FILES} )
