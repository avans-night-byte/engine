#pragma once



#include <map>
#include <vector>
#include <tmxlite/Map.hpp>
#include "../Vector2.hpp"

class RenderingAPI;
class Spritesheet;
class PhysicsEngineAdapter;
class EngineRenderingAPI;

struct LoadedObjectData  {
    std::string objectName;
    Vector2 position;
};

class TMXLevel {
private:
    float scale = 4;

    tmx::Map _tmap;
    Spritesheet *_tSpritesheet;
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


    void initObjects(std::vector<LoadedObjectData> &outLoadedObjects);

    void initStaticCollision();
};