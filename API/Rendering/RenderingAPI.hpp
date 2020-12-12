#pragma once

class SDL_Color;

class Spritesheet;

class PhysicsEngineAdapter;

class RenderingEngineAdapter;

class Vector2;

class TMXLevel;

#include <string>

struct LevelData {
public:
    LevelData(const std::string _tmxPath,
              const std::string spriteSheetPath,
              const std::string &spriteId,
              const std::string &levelResourcePath)
            : tmxPath(_tmxPath), spritesheetPath(spriteSheetPath), spriteId(spriteId),
              levelResourcePath(levelResourcePath) {

    }

    const std::string tmxPath;
    const std::string spritesheetPath;
    const std::string spriteId;
    const std::string levelResourcePath;
};

class RenderingAPI {
public:
    virtual void drawTexture(const std::string &textureId, float x, float y, float width, float height, double scale, double r) const = 0;

    virtual Spritesheet *createSpriteSheet(std::string path, std::string spriteSheetId, int width, int height) const = 0;

    virtual bool loadTexture(const std::string &path, std::string &textureId) = 0;

    virtual void drawRectangle(Vector2 &position, float width, float height, std::string &color, float opacity = 1) const = 0;

    //TODO: SDL_Color in de API weghalen
    virtual void createText(const std::string &fontPath, const std::string &text, const int fontSize, const std::string &hex,
                            const std::string &textureId) const = 0;

    virtual void drawBackground(std::string &hex, float alpha) const = 0;

    virtual TMXLevel *loadLevel(const LevelData &levelData, PhysicsEngineAdapter &physicsEngineAdapter) = 0;

    virtual void drawLine(Vector2 &a, Vector2 &b) const = 0;


public:
    [[nodiscard]] virtual const RenderingEngineAdapter &GetRendererAdapter() const = 0;
};