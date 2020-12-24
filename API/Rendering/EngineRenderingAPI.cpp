#include "EngineRenderingAPI.hpp"
#include "../../Engine/Rendering/TMXLevel.hpp"

#include <utility>

TextureManager *EngineRenderingAPI::getTextureManager() {
    return SDLRenderingAdapter::GetTextureManager();
}

/**
 * @param path
 * @param spriteSheetId
 * @param rows
 * @param columns
 * @param width
 * @param height
 * @return SpriteSheet
 */
SpriteSheet *
EngineRenderingAPI::loadSpriteSheet(std::string path, std::string spriteSheetId, int width, int height, int offsetX,
                                    int offsetY) const {
    return _adapter.createSpriteSheet(path, spriteSheetId, width, height, offsetX, offsetY);
}

void EngineRenderingAPI::createText(const std::string &fontName,
                                    const std::string &text,
                                    const int fontSize,
                                    const std::string &hex,
                                    const std::string &textureId) const {
    _adapter.createText(fontName, text, fontSize, hex, textureId);
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
void
EngineRenderingAPI::drawTexture(const std::string &textureId, float x, float y, float width, float height, double scale,
                                double r) const {
    return _adapter.drawTexture(textureId, x, y, width, height, scale, r, SDL_FLIP_NONE);
}

/**
 * @param path
 * @param textureId
 * @return success
 */
bool EngineRenderingAPI::loadTexture(const std::string &path, const std::string &textureId) {
    return SDLRenderingAdapter::GetTextureManager()->load(path, textureId);
}

void EngineRenderingAPI::drawRectangle(Vector2 &position, float width, float height, std::string &color,
                                       float opacity) const {
    _adapter.drawRectangle(position, width, height, color, opacity);

}

TMXLevel *EngineRenderingAPI::loadTMX(const LevelData &levelData, PhysicsEngineAdapter &physicsEngineAdapter) {
    return new TMXLevel(levelData.tmxPath.c_str(),
                        levelData.spritesheetPath.c_str(),
                        levelData.spriteId.c_str(),
                        *this,
                        physicsEngineAdapter);
}

void EngineRenderingAPI::drawBackground(std::string &hex, float alpha) const {
    _adapter.drawBackground(hex, alpha);

}


void EngineRenderingAPI::drawLine(Vector2 &a, Vector2 &b) const {
    _adapter.drawLine(a, b);
}

void EngineRenderingAPI::render() const {
    _adapter.render();
}

void
EngineRenderingAPI::drawAnimation(std::string &spriteId, const Vector2 &position, const Vector2 &size, const int &speed,
                                  const std::vector<std::pair<int, int>> &animation) {
    _adapter.drawAnimation(spriteId, position, size, speed, animation);
}

EngineRenderingAdapter &EngineRenderingAPI::getRendererAdapter() {
    return _adapter;
}

void EngineRenderingAPI::drawBox(const Vector2 *vertices, int32 vertexCount) const{
    return _adapter.drawBox(vertices, vertexCount);
}
