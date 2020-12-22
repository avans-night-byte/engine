cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)

add_definitions("-DMUSIC_WAV")

set(CMAKE_CURRENT_BINARY_DIR ./build)
set(CMAKE_CURRENT_SOURCE_DIR .)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(TMXLITE_STATIC_LIB TRUE)

set(SDL2_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SDL)
set(SDL2TTF_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SDL_ttf)
set(BOX2D_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Box2D)
set(SDL2_MIXER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SDL_mixer)
set(SDL2IMAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/SDL_image)
set(TMXLITE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/tmxlite/tmxlite)
set(Xsd_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

project(NightByte)

add_subdirectory(${SDL2_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdl)
add_subdirectory(${SDL2_MIXER_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdl_mixer)
add_subdirectory(${SDL2TTF_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdlttf)
add_subdirectory(${BOX2D_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/box2d)
add_subdirectory(${SDL2IMAGE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdlimage)
add_subdirectory(${TMXLITE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/tmxlite)

add_executable(NightByte ./Main.cpp
        # Game
        ./Game/Game.cpp
        ./Game/Components/ComponentFactory.cpp
        ./Game/Components/ComponentFactory.hpp
        ./Game/Components/Component.hpp
        Game/Components/Rendering/RenderComponent.cpp
        Game/Components/Rendering/RenderComponent.hpp
        ./Game/Components/TransformComponent.hpp
        ./Game/Components/PhysicsComponent.cpp
        ./Game/Components/PhysicsComponent.hpp
        ./Game/Components/CharacterComponent.cpp
        ./Game/Components/CharacterComponent.hpp
        ./Game/Components/TransformComponent.cpp
        ./Game/Components/NextLevelComponent.cpp
        ./Game/Components/NextLevelComponent.hpp
        ./Game/Components/EntityObject.cpp
        ./Game/Components/EntityObject.hpp
        ./Game/Scenes/LevelBase.cpp
        ./Game/UI/FrameCounter.cpp
        ./Game/UI/FrameCounter.h
        ./Game/Helpers/GameTime.cpp
        ./Game/Helpers/GameTime.h
        ./Game/Components/WeaponComponent.cpp
        ./Game/Components/WeaponComponent.hpp
        ./Game/Components/BulletComponent.cpp
        ./Game/Components/BulletComponent.hpp
        ./Game/Object/Pool.hpp
        ./Game/Object/GlobalObjects.cpp
        ./Game/Object/GlobalObjects.hpp
        ./Game/Components/Inventory/InventoryComponent.cpp
        ./Game/Components/Inventory/InventoryComponent.hpp
        ./Game/Components/Inventory/InventoryItem.cpp
        ./Game/Components/Inventory/InventoryItem.hpp
        ./Game/Components/Build/BuildComponent.cpp
        ./Game/Components/Build/BuildComponent.hpp
        ./Game/Object/ObjectLoader.cpp
        ./Game/Object/ObjectLoader.hpp
        ./Game/Object/Pool.cpp
        ./Game/Scenes/PoolLevel.cpp
        ./Game/Scenes/PoolLevel.hpp
        ./Game/Components/Wallet/WalletComponent.cpp
        ./Game/Components/Wallet/WalletComponent.hpp

        # Engine
        ./Engine/Engine.cpp
        ./Engine/Physics/b2_user_settings.h
        ./Engine/Input/Adapter/SDLInputEngineAdapter.cpp
        ./Engine/Audio/Adapter/SDLAudioEngineAdapter.cpp
        ./Engine/Audio/Adapter/SDLAudioEngineAdapter.hpp
        ./Engine/Rendering/SpriteSheet.cpp
        ./Engine/Rendering/TextureManager.cpp
        ./Engine/Rendering/Adapter/SDLRenderingAdaper.cpp
        ./Engine/Audio/AudioType.h
        ./Engine/Physics/PhysicsEngineAdapter.hpp
        ./Engine/Physics/Box2DPhysicsEngineAdapter.hpp

        ./Engine/Physics/BodyType.hpp
        ./Engine/Physics/Box2dPhysicsEngineAdapter.cpp
        ./Engine/Physics/PhysicsDebug/Box2dDrawDebug.hpp
        ./Engine/Rendering/TMXLevel.cpp
        ./Engine/Rendering/TMXLevel.hpp
        ./Engine/Physics/ContactListener.hpp
        ./Engine/Physics/ContactHandler.hpp
        ./Engine/XMLParser/EntityXMLParser.hpp
        ./Engine/XMLParser/EntityXMLParser.cpp
        ./Engine/XMLParser/MenuParser.cpp
        ./Engine/XMLParser/MenuParser.hpp
        ./Engine/Managers/ResourceManager.cpp
        ./Engine/Managers/ResourceManager.hpp
        ./Engine/Rendering/TextWrapper.cpp
        ./Engine/Rendering/TextWrapper.hpp
        ./Engine/Physics/BodyHandler.cpp
        ./Engine/Physics/BodyHandler.hpp
        ./Engine/Rendering/Adapter/EngineRenderingAdapter.hpp


        # API
        ./API/Input/EngineInputAPI.cpp
        ./API/Audio/EngineAudioAPI.cpp
        ./API/Rendering/EngineRenderingAPI.hpp
        ./API/Rendering/EngineRenderingAPI.cpp
        ./API/Engine/EngineWindowAPI.cpp
        ./API/Engine/WindowAPI.hpp
        ./API/Audio/AudioAPI.h
        ./API/Physics/EnginePhysicsAPI.hpp
        ./API/Physics/PhysicsAPI.hpp
        ./API/RTransform.hpp
        ./API/XMLParser/MenuParserAPI.cpp
        ./API/XMLParser/MenuParserAPI.hpp
        ./API/XMLParser/LevelParserAPI.cpp
        ./API/Physics/BodyHandlerAPI.hpp
        ./API/Helpers/Vector2.hpp
        Game/Components/Rendering/Animation.cpp Game/Components/Rendering/Animation.hpp Game/Object/CollisionHandler.hpp)

find_package(box2d REQUIRED)
find_package(XercesC REQUIRED)
find_package(Xsd REQUIRED)

target_include_directories(NightByte PUBLIC
        ${SDL2_SOURCE_DIR}/include
        ${BOX2D_SOURCE_DIR}/include/box2d
        ${SDL2_MIXER_SOURCE_DIR}/include
        ${SDL2IMAGE_SOURCE_DIR}
        ${TMXLITE_SOURCE_DIR}
        ${SDL2TTF_SOURCE_DIR}
        ./Engine/Physics
        )

add_library(XMLResources SHARED
        ./Resources/XML/Generated/wall.hxx
        ./Resources/XML/Generated/wall.cxx
        ./Resources/XML/Generated/common.cxx
        ./Resources/XML/Generated/common.hxx
        ./Resources/XML/Generated/menu.cxx
        ./Resources/XML/Generated/menu.hxx
        ./Resources/XML/Generated/resources.cxx
        ./Resources/XML/Generated/resources.hxx
        ./Resources/XML/Generated/level-resources.hxx
        ./Resources/XML/Generated/level-resources.cxx
        ./Resources/XML/Generated/components.hxx
        ./Resources/XML/Generated/components.cxx
        ./Resources/XML/Generated/objects.hxx
        ./Resources/XML/Generated/objects.cxx)

target_link_libraries(XMLResources PUBLIC XercesC::XercesC )
target_include_directories(XMLResources PUBLIC ${XSD_INCLUDE_DIR} ./Resources/XML/)

target_link_libraries(NightByte SDL2 box2d  SDL2::image SDL2_mixer tmxlite SDL2_ttf XMLResources)

if (MSVC OR MSYS OR MINGW)
    target_link_libraries(NightByte winpthread)

    set(dep "${CMAKE_CXX_COMPILER}/../libwinpthread-1.dll"
            "${CMAKE_CXX_COMPILER}/../libgcc_s_seh-1.dll"
            "${CMAKE_CXX_COMPILER}/../libstdc++-6.dll"
            "${CMAKE_CXX_COMPILER}/../zlib1.dll"
            "${CMAKE_CXX_COMPILER}/../libssh2-1.dll"
            "${CMAKE_CXX_COMPILER}/../libcurl-4.dll"
            "${CMAKE_CXX_COMPILER}/../libxerces-c-3-2.dll"
            "${CMAKE_CXX_COMPILER}/../libicuuc67.dll"
            "${CMAKE_CXX_COMPILER}/../libbrotlidec.dll"
            "${CMAKE_CXX_COMPILER}/../libcrypto-1_1-x64.dll"
            "${CMAKE_CXX_COMPILER}/../libidn2-0.dll"
            "${CMAKE_CXX_COMPILER}/../libnghttp2-14.dll"
            "${CMAKE_CXX_COMPILER}/../libpsl-5.dll"
            "${CMAKE_CXX_COMPILER}/../libssl-1_1-x64.dll"
            "${CMAKE_CXX_COMPILER}/../libicudt67.dll"
            "${CMAKE_CXX_COMPILER}/../libzstd.dll"
            "${CMAKE_CXX_COMPILER}/../libbrotlicommon.dll"
            "${CMAKE_CXX_COMPILER}/../libiconv-2.dll"
            "${CMAKE_CXX_COMPILER}/../libunistring-2.dll"
            "${CMAKE_CXX_COMPILER}/../libintl-8.dll"
            "${CMAKE_CXX_COMPILER}/../libfreetype-6.dll"
            "${CMAKE_CXX_COMPILER}/../libharfbuzz-0.dll"
            "${CMAKE_CXX_COMPILER}/../libbz2-1.dll"
            "${CMAKE_CXX_COMPILER}/../libpng16-16.dll"
            "${CMAKE_CXX_COMPILER}/../libglib-2.0-0.dll"
            "${CMAKE_CXX_COMPILER}/../libgraphite2.dll"
            "${CMAKE_CXX_COMPILER}/../libpcre-1.dll"
            )

    foreach (file_i ${dep})
        add_custom_command(TARGET NightByte POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${file_i}
                $<TARGET_FILE_DIR:NightByte>)
    endforeach ()
endif ()