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
  src/WordCharPredicates.cpp
  src/Punctuation.cpp
  src/ToLowerCase.cpp
  src/FileHelpers.cpp
  src/WordFrequencyTable.cpp
  # add any additional source files here
)

set ( HDR_FILES
  DiscardWhile.h
  FileHelpers.h
  ForEachWord.h
  MakeWordFrequencyMap.h
  Punctuation.h
  TakeWhile.h
  ToLowerCase.h
  WordCharPredicates.h
  WordFrequencyTable.h
  # add any additional header files here
)

add_executable ( WordCounter ${SRC_FILES} ${HDR_FILES} )
target_include_directories( WordCounter PUBLIC include )
