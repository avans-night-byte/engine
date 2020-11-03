cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CURRENT_BINARY_DIR ./build)
set(CMAKE_CURRENT_SOURCE_DIR .)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(SDL2_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SDL)
set(BOX2D_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Box2D)
set(SDL2IMAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SDL_image)
set(XERCES_C_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/XercesC)
set(LIBXSD_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/xsd)

project(NightByte)

add_subdirectory(${SDL2_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdl)
add_subdirectory(${BOX2D_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/box2d)
add_subdirectory(${SDL2IMAGE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdlimage)
add_subdirectory(${XERCES_C_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/xercesc)
add_subdirectory(${LIBXSD_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/libxsd)


add_executable(NightByte ./Main.cpp
                         # Game
                         ./Game/Game.cpp
                         ./Game/Components/Component.hpp
                         ./Game/Components/RenderComponent.cpp
                         ./Game/Components/RenderComponent.hpp
                         ./Game/Components/WorldPositionComponent.cpp
                         ./Game/Components/WorldPositionComponent.hpp
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
)

find_package(box2d REQUIRED)

target_include_directories(NightByte PUBLIC
                                ${SDL2_SOURCE_DIR}/include
                                ${BOX2D_SOURCE_DIR}/include/box2d
                                ${SDL2IMAGE_SOURCE_DIR})

if(MSVC OR MSYS OR MINGW)
  target_link_libraries(NightByte SDL2 box2d SDL2::image winpthread)
endif()

if(UNIX AND NOT APPLE)
  target_link_libraries(NightByte SDL2 box2d SDL2::image)
endif()