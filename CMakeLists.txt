cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)

add_definitions("-DMUSIC_WAV")

set(CMAKE_CURRENT_BINARY_DIR ./build)
set(CMAKE_CURRENT_SOURCE_DIR .)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(SDL2_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SDL)
set(BOX2D_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Box2D)
set(SDL2_MIXER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SDL_mixer)
set(SDL2IMAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SDL_image)
set(Xsd_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/XSD)

project(NightByte)

add_subdirectory(${SDL2_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdl)
add_subdirectory(${SDL2_MIXER_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdl_mixer)
add_subdirectory(${BOX2D_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/box2d)
add_subdirectory(${SDL2IMAGE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdlimage)


add_executable(NightByte ./Main.cpp
        # Game
        ./Game/Game.cpp
        ./Game/Components/Component.hpp
        ./Game/Components/RenderComponent.cpp
        ./Game/Components/RenderComponent.hpp
        ./Game/Components/WorldPositionComponent.cpp
        ./Game/Components/WorldPositionComponent.hpp
        ./Game/Scenes/Menu/MainMenu.hpp
        # Engine
        ./Engine/Engine.cpp
        ./Engine/Audio/AudioFile.cpp
        ./Engine/Audio/AudioFile.h
        ./Engine/Input/Adapter/SDLInputEngineAdapter.cpp
        ./Engine/Audio/Adapter/SDLAudioEngineAdapter.cpp
        ./Engine/Audio/Adapter/SDLAudioEngineAdapter.hpp
        ./Engine/Rendering/Spritesheet.cpp
        ./Engine/Rendering/TextureManager.cpp
        ./Engine/Rendering/Adapter/SDLRenderingAdaper.cpp
        # API
        ./API/Input/EngineInputAPI.cpp
        ./API/Audio/AudioAPI.cpp
        ./API/Rendering/EngineRenderingAPI.hpp
        ./API/Rendering/EngineRenderingAPI.cpp
        ./API/Engine/EngineWindowAPI.cpp
        ./API/Engine/WindowAPI.hpp
        Engine/Audio/AudioType.h
        # XML
        ./Engine/Resources/XML/Generated/wall.hxx
        ./Engine/Resources/XML/Generated/wall.cxx
        ./Engine/Resources/XML/Generated/common.hxx
        ./Engine/Resources/XML/Generated/common.cxx
        )
find_package(box2d REQUIRED)
find_package(XercesC REQUIRED)
find_package(Xsd REQUIRED)

target_include_directories(NightByte PUBLIC
        ${SDL2_SOURCE_DIR}/include
        ${BOX2D_SOURCE_DIR}/include/box2d
        ${SDL2_MIXER_SOURCE_DIR}/include
        ${SDL2IMAGE_SOURCE_DIR}
        ${XSD_INCLUDE_DIR})


target_link_libraries(NightByte SDL2 box2d SDL2::image XercesC::XercesC SDL2_mixer)

if (MSVC OR MSYS OR MINGW)
    target_link_libraries(NightByte winpthread)
endif ()