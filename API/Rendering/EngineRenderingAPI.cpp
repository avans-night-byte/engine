#include "EngineRenderingAPI.hpp"

#include "../../Engine/Rendering/TMXLevel.hpp"
#include <utility>

TextureManager *EngineRenderingAPI::GetTextureManager()
{
    return SDLRenderingAdapter::GetTextureManager();
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
Spritesheet *EngineRenderingAPI::createSpriteSheet(const std::string path, std::string spriteSheetId, int width, int height) const
{
    return _adapter->createSpriteSheet(path, spriteSheetId, width, height);
}

Spritesheet *EngineRenderingAPI::createSpriteSheet(const std::string &path, const std::string &jsonPath, std::string &spriteSheetId)
{
    return _adapter->createSpriteSheet(path, jsonPath, spriteSheetId, _renderer);
}

void EngineRenderingAPI::createText(const std::string &fontName, const std::string &text, const int fontSize, const std::string &hex,
                                    const std::string &textureId) const {
    _adapter->createText(fontName, text, fontSize, hex, textureId, _renderer);
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
void EngineRenderingAPI::drawTexture(const std::string &textureId, float x, float y, float width, float height, double scale, double r) const
{
    return _adapter->drawTexture(textureId, x, y, width, height, scale, r, _renderer, SDL_FLIP_NONE);
}

/**
 * @param path
 * @param textureId
 * @return success
 */
bool EngineRenderingAPI::loadTexture(const std::string &path, const std::string &textureId)
{
    return SDLRenderingAdapter::GetTextureManager()->load(path, textureId);
}

SDLRenderingAdapter &EngineRenderingAPI::GetRendererAdapter() const {
    return *_adapter;
}

void EngineRenderingAPI::drawRectangle(Vector2 &position, float width, float height, std::string& color, float opacity) const {
    _adapter->drawRectangle(position, width, height, color, opacity, _renderer);

}

TMXLevel *EngineRenderingAPI::loadTMX(const LevelData &levelData, PhysicsEngineAdapter &physicsEngineAdapter) {
    return new TMXLevel(levelData.tmxPath.c_str(),
                        levelData.spritesheetPath.c_str(),
                        levelData.spriteId.c_str(),
                        *this,
                        physicsEngineAdapter);
}

void EngineRenderingAPI::drawBackground(std::string &hex, float alpha) const {
    _adapter->drawBackground(hex, alpha, _renderer);

}


void EngineRenderingAPI::drawLine(Vector2 &a, Vector2 &b) const {
    SDL_RenderDrawLine(_renderer, a.x, a.y, b.x, b.y);

}

void EngineRenderingAPI::render() const {
    _adapter->render(_renderer);
}
