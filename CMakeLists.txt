cmake_minimum_required(VERSION 3.17)

add_definitions("-DMUSIC_WAV")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CURRENT_BINARY_DIR ./build)
set(CMAKE_CURRENT_SOURCE_DIR .)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(SDL2_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SDL)
set(SDL2_MIXER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SDL_mixer)

project(NightByte)

add_subdirectory(${SDL2_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdl)
add_subdirectory(${SDL2_MIXER_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdl_mixer)

add_executable(NightByte ./Main.cpp
        ./Game/Game.cpp
        ./Engine/Engine.cpp
        ./Engine/Input/Adapter/SDLInputEngineAdapter.cpp
        ./API/Input/EngineInputAPI.cpp
        ./API/Audio/AudioAPI.hpp)

target_include_directories(NightByte PUBLIC
        ${SDL2_SOURCE_DIR}/include
        ${SDL2_MIXER_SOURCE_DIR}/include)


target_link_libraries(NightByte SDL2 SDL2_mixer)
