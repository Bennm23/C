cmake_minimum_required(VERSION 3.22.0)

# set(CMAKE_C_FLAGS "-Wall -D__USE_POSIX199309")

project(main C)

add_subdirectory(src)


# Optionally, specify where to store other build artifacts
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# Set the binary directory to a separate "build" folder
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
