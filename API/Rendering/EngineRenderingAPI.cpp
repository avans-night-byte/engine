#include "EngineRenderingAPI.hpp"

#include "../../Engine/Rendering/TMXLevel.hpp"
#include <utility>

TextureManager *EngineRenderingAPI::GetTextureManager()
{
    return RenderingEngineAdapter::GetTextureManager();
}

/**
 * @param path
 * @param spriteSheetId
 * @param rows
 * @param columns
 * @param width
 * @param height
 * @return Spritesheet
 */
Spritesheet *
EngineRenderingAPI::createSpriteSheet(const char *path, std::string spriteSheetId, int rows, int columns, int width,
                                      int height) const
{
    return _adapter->createSpriteSheet(path, spriteSheetId, rows, columns, width, height, _renderer);
}

Spritesheet *
EngineRenderingAPI::createSpriteSheet(const char *path, const char *jsonPath, std::string spriteSheetId)
{
    return _adapter->createSpriteSheet(path, jsonPath, std::move(spriteSheetId), _renderer);
}

void EngineRenderingAPI::createText(std::string fontName, const char *text, const int fontSize, SDL_Color color,
                                    std::string textureId) const {
    _adapter->createText(fontName, text, fontSize, color, textureId, _renderer);
}


/**
 * @param textureId
 * @param x
 * @param y
 * @param width
 * @param height
 * @param scale
 * @param r
 */
void EngineRenderingAPI::drawTexture(std::string textureId, int x, int y, int width, int height, double scale, double r) const
{
    return _adapter->drawTexture(textureId, x, y, width, height, scale, r, _renderer, SDL_FLIP_NONE);
}

/**
 * @param path
 * @param textureId
 * @return success
 */
bool EngineRenderingAPI::loadTexture(const char *path, std::string textureId) const
{
    return RenderingEngineAdapter::GetTextureManager()->load(path, textureId, _renderer);
}

RenderingEngineAdapter &EngineRenderingAPI::GetRendererAdapter() const {
    return *_adapter;
}

void EngineRenderingAPI::drawRectangle(Vector2 &position, float width, float height, std::string& color, float opacity) const {
    _adapter->drawRectangle(position, width, height, color, opacity, _renderer);

}

TMXLevel *EngineRenderingAPI::loadLevel(const TMXLevelData &levelData, PhysicsEngineAdapter &physicsEngineAdapter) {
    return new TMXLevel(levelData.tmxPath.c_str(),
                        levelData.spritesheetPath.c_str(),
                        levelData.spriteId.c_str(),
                        *this,
                        physicsEngineAdapter);
}