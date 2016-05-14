# CMake required version
cmake_minimum_required (VERSION 3.4)

# Project name
set (PROJECT msvhd)

# Find all sources
aux_source_directory("./" SRC)

# Binary dir is two level upper that build directory
set (BINARY_DIR ../../)
set (EXECUTABLE_OUTPUT_PATH ${BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -g")

# Build executable
add_executable (${PROJECT} ${SRC})
