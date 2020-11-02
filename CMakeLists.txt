cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CURRENT_BINARY_DIR ./build)
set(CMAKE_CURRENT_SOURCE_DIR .)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(SDL2_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SDL)

project(NightByte)

add_subdirectory(${SDL2_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
add_executable(NightByte ./Main.cpp
        ./Libraries/RapidXML/rapidxml.hpp
        ./Libraries/RapidXML/rapidxml_iterators.hpp
        ./Libraries/RapidXML/rapidxml_print.hpp
        ./Libraries/RapidXML/rapidxml_utils.hpp
        ./Game/Game.cpp
        ./Engine/Engine.cpp
        ./Engine/Input/Adapter/SDLInputEngineAdapter.cpp
        ./API/Input/EngineInputAPI.cpp)

target_include_directories(NightByte PUBLIC ${SDL2_SOURCE_DIR}/include)
target_link_libraries(NightByte SDL2)
