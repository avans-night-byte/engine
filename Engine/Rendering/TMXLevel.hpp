#pragma once



#include <map>
#include <vector>
#include <tmxlite/Map.hpp>
#include "../../API/Helpers/Vector2.hpp"

class RenderingAPI;
class SpriteSheet;
class PhysicsEngineAdapter;
class EngineRenderingAPI;

struct LoadedObjectData  {
    std::string objectName;
    Vector2 position;
};

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

    void getObjectPositions(const std::multimap<std::string, Components::component *> &outEntities);

    void initStaticCollision();
};