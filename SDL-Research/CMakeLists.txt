cmake_minimum_required(VERSION 3.7)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#SET(SDL2_DIR ./lib)

project(SDL2Test)

#find_package(SDL2 REQUIRED)
#include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})

add_executable(SDL2Test Main.cpp)
#target_link_libraries(SDL2Test ${SDL2_LIBRARIES})