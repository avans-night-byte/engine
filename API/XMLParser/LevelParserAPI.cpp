#include <Generated/level-resources.hxx>
#include "LevelParserAPI.hpp"

#include "../../Engine/Rendering/TMXLevel.hpp"
#include "../../Game/Game.hpp"


void LevelParserAPI::loadEntities(std::multimap<std::string, Components::component *> &outEntities,
                                       xsd::cxx::tree::sequence<Objects::object> &objects) {
    EntityXMLParser::createEntities(outEntities, objects);
}

TMXLevel *LevelParserAPI::loadLevel(std::multimap<std::string, Components::component *> &outEntities,
                                    const LevelData &levelData) {
    auto &renderingApi = Game::getInstance()->getRenderingApi();

    auto &physicsApi = Game::getInstance()->getPhysicsAPI();

    auto xmlLevel = LevelResources::level_(levelData.levelResourcePath);
    loadEntities(outEntities, xmlLevel->object());

    auto tmxLevel = renderingApi.loadTMX(levelData, physicsApi.getPhysicsEngineAdapter());
    tmxLevel->getObjectPositions(outEntities);

    return tmxLevel;
}
