cmake_minimum_required( VERSION 3.0 )

project( romannumeralconverter )

enable_testing()

set( HEADERS
	include/RomanNumeralConverter.hpp
)

set( SOURCES 
	src/RomanNumeralConverter.cpp
)

set( SOURCES_TEST 
	test/RomanNumeralConverter_test.cpp
)

# build the actual application
add_executable( ${PROJECT_NAME} ${HEADERS} ${SOURCES} main.cpp )
target_include_directories( ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include )

# build the test application
set( TEST_APP ${PROJECT_NAME}_test )
add_executable( ${TEST_APP} ${HEADERS} ${SOURCES} ${SOURCES_TEST} )
target_include_directories( ${TEST_APP} PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_link_libraries( ${TEST_APP} gtest_main )