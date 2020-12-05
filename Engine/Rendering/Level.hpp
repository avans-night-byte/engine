#pragma once


#include "../Physics/PhysicsEngineAdapter.hpp"

#include <map>
#include <vector>
#include <tmxlite/Map.hpp>

class Spritesheet;
class Vector2;
class PhysicsEngineAdapter;
class EngineRenderingAPI;

class Level {
private:
    float scale = 4;

    tmx::Map _tmap;
    Spritesheet *_tSpritesheet;
    std::map<int, Vector2> _tSpriteMap;
    std::vector<unsigned int> bodies{};
    PhysicsEngineAdapter& physicsEngineAdapter;

public:
    Level(const char *tmxPath,
          const char *spritesheetPath,
          const char *spritesheetId,
          const EngineRenderingAPI &engineRenderingAPI,
          PhysicsEngineAdapter& physicsEngineAdapter);

    ~Level() {
        for (unsigned int bodyId: bodies)
        {
            physicsEngineAdapter.destroyBody(bodyId);
        }
    }

    void initialize();

    void render(EngineRenderingAPI &engineRenderingAPI);

    void cleanup();

    void initCollision();
};