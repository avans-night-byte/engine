//
// Created by sascha on 11/27/20.
//

#ifndef NIGHTBYTE_LEVEL_HPP
#define NIGHTBYTE_LEVEL_HPP


#include <include/tmxlite/Map.hpp>
#include "Spritesheet.hpp"
#include "../Vector2.hpp"
#include "../../API/Rendering/EngineRenderingAPI.hpp"
#include "../Physics/PhysicsEngineAdapter.hpp"

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
          EngineRenderingAPI &engineRenderingAPI,
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


#endif //NIGHTBYTE_LEVEL_HPP
