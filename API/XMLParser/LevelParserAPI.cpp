#include "LevelParserAPI.hpp"

#include "../../Engine/Rendering/TMXLevel.hpp"
#include "../../Game/Game.hpp"
#include "../Physics/PhysicsAPI.hpp"
#include "../Rendering/EngineRenderingAPI.hpp"


void LevelParserAPI::LoadLevel(const TMXLevelData &levelData, const std::string &resourcePath) {
    RenderingAPI *renderingApi = Game::getInstance()->getRenderingApi();

    PhysicsAPI *physicsApi = Game::getInstance()->getPhysicsAPI();
    levelLoader = std::unique_ptr<TMXLevel>(
            renderingApi->loadLevel(levelData, *physicsApi->getPhysicsEngineAdapter()));

    auto loadedObjects = std::vector<LoadedObjectData>();
    levelLoader->initObjects(loadedObjects);

    levelXMLParser = std::make_unique<LevelXMLParser>();
    levelXMLParser->LoadLevel(loadedObjects, resourcePath);
}
