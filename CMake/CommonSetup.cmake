###############################################################################
# CommonSetup.cmake
###############################################################################

# We want shared libraries everywhere
set ( BUILD_SHARED_LIBS On )

# Send libraries to common place
set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )
set ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )

# This allows us to group targets logically in Visual Studio
set_property ( GLOBAL PROPERTY USE_FOLDERS ON )

if ( CMAKE_COMPILER_IS_GNUCXX )
  # Use c++0x flag for gcc (same as mantid for the time being)
  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x" )
endif ()
