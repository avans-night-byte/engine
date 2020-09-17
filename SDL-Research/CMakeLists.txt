cmake_minimum_required(VERSION 3.17)
set(CMAKE_CURRENT_BINARY_DIR ./build)
set(CMAKE_CURRENT_SOURCE_DIR ./)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

set(SDL2_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../SDL)

project(SDL2Test)



add_subdirectory(${SDL2_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})


#find_package(SDL2 REQUIRED)
#include_directories(SDL2Test ../SDL/include)

#add_executable(SDL2Test Main.cpp)
#target_link_libraries(SDL2Test ${SDL2_LIBRARIES})
