#include "LevelParserAPI.hpp"

#include "../../Engine/Rendering/TMXLevel.hpp"
#include "../../Game/Game.hpp"

#include <Generated/level-resources.hxx>


void LevelParserAPI::loadEntities(std::vector<EntityXMLParser::ObjectData> &outEntities,
                                       xsd::cxx::tree::sequence<Objects::object> &objects) {
    EntityXMLParser::createEntities(outEntities, objects);
}

TMXLevel *LevelParserAPI::loadLevel(std::vector<EntityXMLParser::ObjectData> &outEntities, const LevelData &levelData) {

    auto &renderingApi = Game::getInstance()->getRenderingAPI();
    auto &physicsApi = Game::getInstance()->getPhysicsAPI();
    auto xmlLevel = LevelResources::level_resources_(levelData.levelResourcePath);

    loadEntities(outEntities, xmlLevel->level().object());

    for (auto &resource : xmlLevel->preloadResources().resource()) {
        ResourceManager::getInstance()->loadResource(resource);
    }

    auto &audioAdapter = SDLAudioEngineAdapter::getInstance();
    std::string musicTrack = xmlLevel->level().background_music().c_str();

    if (audioAdapter.getCurrentPlayingMusic() != musicTrack) {
        audioAdapter.playFromMemory(musicTrack);
    }

    auto tmxLevel = renderingApi.loadTMX(levelData, physicsApi.getPhysicsEngineAdapter());
    tmxLevel->getObjectPositions(outEntities);

    return tmxLevel;
}
