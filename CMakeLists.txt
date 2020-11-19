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
        ./Game/Scenes/Example/ExampleScene.cpp
        ./Game/Scenes/Example/ExampleScene.hpp
        ./Game/Components/PhysicsComponent.cpp
        ./Game/Components/PhysicsComponent.h
        # Engine
        ./Engine/Engine.cpp
        ./Engine/Input/Adapter/SDLInputEngineAdapter.cpp
        ./Engine/Audio/Adapter/SDLAudioEngineAdapter.cpp
        ./Engine/Audio/Adapter/SDLAudioEngineAdapter.hpp
        ./Engine/Rendering/Spritesheet.cpp
        ./Engine/Rendering/TextureManager.cpp
        ./Engine/Rendering/Adapter/SDLRenderingAdaper.cpp
        ./Engine/Audio/AudioType.h
        ./Engine/Physics/PhysicsEngineAdapter.hpp
        ./Engine/Physics/Box2DPhysicsEngineAdapter.hpp
        ./Engine/Vector2.hpp
        ./Engine/Physics/BodyType.hpp
        ./Engine/Physics/Box2dPhysicsEngineAdapter.cpp
        Engine/Physics/PhysicsDebug/Box2dDrawDebug.hpp
        # API
        ./API/Input/EngineInputAPI.cpp
        ./API/Audio/AudioAPI.cpp
        ./API/Rendering/EngineRenderingAPI.hpp
        ./API/Rendering/EngineRenderingAPI.cpp
        ./API/Engine/EngineWindowAPI.cpp
        ./API/Engine/WindowAPI.hpp
        ./API/Physics/EnginePhysicsAPI.hpp
        ./API/Physics/PhysicsAPI.hpp
        ./API/RPosition.hpp)

find_package(box2d REQUIRED)

target_include_directories(NightByte PUBLIC
        ${SDL2_SOURCE_DIR}/include
        ${SDL2_MIXER_SOURCE_DIR}/include
        ${BOX2D_SOURCE_DIR}/include/box2d
        ${SDL2IMAGE_SOURCE_DIR})

if (MSVC OR MSYS OR MINGW)
    target_link_libraries(NightByte SDL2 box2d SDL2::image winpthread SDL2_mixer)

    set(dep "${CMAKE_CXX_COMPILER}/../libwinpthread-1.dll"
            "${CMAKE_CXX_COMPILER}/../libgcc_s_seh-1.dll"
            "${CMAKE_CXX_COMPILER}/../libstdc++-6.dll"
            "${CMAKE_CXX_COMPILER}/../zlib1.dll")

    foreach (file_i ${dep})
        add_custom_command(TARGET NightByte POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${file_i}
                $<TARGET_FILE_DIR:NightByte>)
    endforeach ()
endif ()


if (UNIX AND NOT APPLE)
    target_link_libraries(NightByte SDL2 box2d SDL2::image SDL2_mixer)
endif ()