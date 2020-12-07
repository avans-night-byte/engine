#include "LevelParserAPI.hpp"

#include "../../Engine/Rendering/TMXLevel.hpp"
#include "../../Game/Game.hpp"
#include "../Physics/PhysicsAPI.hpp"
#include "../Rendering/EngineRenderingAPI.hpp"


void LevelParserAPI::loadLevel(std::multimap<std::string, const LevelResources::component *> &outEntities,
                               const TMXLevelData &levelData,
                               const std::string &resourcePath) {
    auto *renderingApi = Game::getInstance()->getRenderingApi();

    auto *physicsApi = Game::getInstance()->getPhysicsAPI();

    auto levelLoader = std::unique_ptr<TMXLevel>(renderingApi->loadLevel(levelData,
                                                                         *physicsApi->getPhysicsEngineAdapter()));

    auto loadedObjects = std::map<std::string, LoadedObjectData>();
    levelLoader->initObjects(loadedObjects);

    auto levelXMLParser = std::make_unique<LevelXMLParser>();
    levelXMLParser->LoadLevel(outEntities,
                              loadedObjects,
                              resourcePath);
}
