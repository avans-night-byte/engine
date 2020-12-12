#include "LevelParserAPI.hpp"

#include "../../Engine/Rendering/TMXLevel.hpp"
#include "../../Game/Game.hpp"
#include "../Physics/PhysicsAPI.hpp"
#include "../Rendering/EngineRenderingAPI.hpp"
#include "Generated/components.hxx"


TMXLevel* LevelParserAPI::loadLevel(std::multimap<std::string, Components::component *> &outEntities,
                               const LevelData &levelData) {
    auto &renderingApi = Game::getInstance()->getRenderingApi();

    auto &physicsApi = Game::getInstance()->getPhysicsAPI();

    auto tmxLevel = renderingApi.loadLevel(levelData, *physicsApi.getPhysicsEngineAdapter());

    auto loadedObjects = std::map<std::string, LoadedObjectData>();
    tmxLevel->initObjects(loadedObjects);

    auto levelXMLParser = std::make_unique<LevelXMLParser>();
    levelXMLParser->loadLevel(outEntities,
                              loadedObjects,
                              levelData.levelResourcePath);

    return tmxLevel;
}
