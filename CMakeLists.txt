cmake_minimum_required( VERSION 3.0 )

project( romannumerals )

set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} )

add_subdirectory( romannumeralconverter )

# this is needed for visual studio as gtest links static by default and VS uses dynamic by default
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory( googletest )
