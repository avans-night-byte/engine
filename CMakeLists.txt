cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)

add_definitions("-DMUSIC_WAV")

set(CMAKE_CURRENT_BINARY_DIR ./build)
set(CMAKE_CURRENT_SOURCE_DIR .)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(SDL2_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SDL)
set(SDL2_MIXER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SDL_mixer)
set(BOX2D_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/box2d)
set(SDL2IMAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SDL_image)

project(NightByte)

add_subdirectory(${SDL2_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdl)
add_subdirectory(${SDL2_MIXER_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdl_mixer)
add_subdirectory(${BOX2D_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/box2d)
add_subdirectory(${SDL2IMAGE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdlimage)

add_executable(NightByte ./Main.cpp
        ./Game/Game.cpp
        ./Engine/Engine.cpp
        ./Engine/Input/Adapter/SDLInputEngineAdapter.cpp
        ./API/Input/EngineInputAPI.cpp
        API/Audio/AudioAPI.cpp
        Engine/Audio/Adapter/SDLAudioEngineAdapter.cpp
        Engine/Audio/Adapter/SDLAudioEngineAdapter.hpp
        Engine/Audio/AudioFile.cpp Engine/Audio/AudioFile.h
        ./Engine/Rendering/Spritesheet.cpp
        ./Engine/Rendering/TextureManager.cpp
        ./Engine/Rendering/Adapter/SDLRenderingAdaper.cpp
        Game/Components/Component.hpp
        Game/Components/RenderComponent.cpp
        Game/Components/RenderComponent.hpp
        Game/Components/WorldPositionComponent.cpp
        Game/Components/WorldPositionComponent.hpp 
        API/Rendering/EngineRenderingAPI.hpp 
        API/Rendering/EngineRenderingAPI.cpp
        ./API/Audio/AudioAPI.hpp
        ./API/Audio/EngineAudioAPI.hpp API/Audio/EngineAudioAPI.cpp)

target_include_directories(NightByte PUBLIC ${SDL2_SOURCE_DIR}/include)

find_package(box2d REQUIRED)


target_include_directories(NightByte PUBLIC ${SDL2_SOURCE_DIR}/include
        ${SDL2_MIXER_SOURCE_DIR}/include
        ${BOX2D_SOURCE_DIR}/include/box2d 
        ${SDL2IMAGE_SOURCE_DIR})

target_link_libraries(NightByte PRIVATE SDL2 box2d SDL2::image SDL2_mixer)
