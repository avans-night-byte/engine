#pragma once

#include <map>
#include <vector>
#include <tmxlite/Map.hpp>
#include "../../API/Helpers/Vector2.hpp"
#include "../XMLParser/EntityXMLParser.hpp"

class RenderingAPI;
class SpriteSheet;
class PhysicsEngineAdapter;
class EngineRenderingAPI;



namespace Components {
    class component;
}

class TMXLevel {
private:
    float scale = 4;

    tmx::Map _tmap;
    SpriteSheet *_tSpritesheet;
    std::map<int, Vector2> _tSpriteMap;
    std::vector<unsigned int> bodies{};
    PhysicsEngineAdapter& physicsEngineAdapter;
public:
    TMXLevel(const char *tmxPath,
             const char *spritesheetPath,
             const char *spritesheetId,
             const RenderingAPI &renderingApi,
             PhysicsEngineAdapter& physicsEngineAdapter);

    ~TMXLevel();

    void render(RenderingAPI &renderingApi);

    void cleanup();

    void getObjectPositions(std::vector<EntityXMLParser::ObjectData> &outEntities);

    void initStaticCollision();

    void GetGrid(int** weights) const;
};