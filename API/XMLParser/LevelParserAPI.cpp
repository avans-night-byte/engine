#include "LevelParserAPI.hpp"

#include "../../Engine/Rendering/TMXLevel.hpp"
#include "../../Game/Game.hpp"
#include "../Physics/PhysicsAPI.hpp"
#include "../Rendering/EngineRenderingAPI.hpp"
#include "Generated/components.hxx"


TMXLevel* LevelParserAPI::loadLevel(std::multimap<std::string, const Components::component *> &outEntities,
                               const TMXLevelData &levelData,
                               const std::string &resourcePath) {
    auto *renderingApi = Game::getInstance()->getRenderingApi();

    auto *physicsApi = Game::getInstance()->getPhysicsAPI();

    auto tmxLevel = renderingApi->loadLevel(levelData, *physicsApi->getPhysicsEngineAdapter());

    auto loadedObjects = std::map<std::string, LoadedObjectData>();
    tmxLevel->initObjects(loadedObjects);

    auto levelXMLParser = std::make_unique<LevelXMLParser>();
    levelXMLParser->LoadLevel(outEntities,
                              loadedObjects,
                              resourcePath);

    return tmxLevel;
}
