cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CURRENT_BINARY_DIR ./build)
set(CMAKE_CURRENT_SOURCE_DIR ./)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(SDL2_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../SDL)
set(BOX2D_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../box2d)


set(${BOX2D_BUILD_TESTBED} OFF)
set(${BOX2D_BUILD_EXAMPLES} OFF)


project(SDL2Test)


add_subdirectory(${SDL2_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdl)
#add_subdirectory(${BOX2D_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/box2d)

find_package(box2d REQUIRED)

add_executable(SDL2Test Main.cpp)


target_include_directories(SDL2Test PUBLIC ${SDL2_SOURCE_DIR}/include ${BOX2D_SOURCE_DIR}/include/box2d)
target_link_libraries(SDL2Test PRIVATE SDL2)


target_link_libraries(SDL2Test PRIVATE box2d::box2d)