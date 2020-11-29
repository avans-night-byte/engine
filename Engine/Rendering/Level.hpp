//
// Created by sascha on 11/27/20.
//

#ifndef NIGHTBYTE_LEVEL_HPP
#define NIGHTBYTE_LEVEL_HPP


#include <include/tmxlite/Map.hpp>
#include "Spritesheet.hpp"
#include "../Vector2.hpp"
#include "../../API/Rendering/EngineRenderingAPI.hpp"

class Level {
private:

    tmx::Map _tmap;
    Spritesheet* _tSpritesheet;
    std::map<int, Vector2> _tSpriteMap;
public:
    Level(const char *tmxPath, const char* spritesheetPath, const char* spritesheetId, EngineRenderingAPI& engineRenderingAPI);
    void initialize();
    void render(EngineRenderingAPI& engineRenderingAPI);
    void cleanup();
    void initCollision();
};


#endif //NIGHTBYTE_LEVEL_HPP
