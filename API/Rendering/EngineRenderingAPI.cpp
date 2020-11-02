#include "EngineRenderingAPI.hpp"
#include "../../Engine/Engine.hpp"

TextureManager *EngineRenderingAPI::GetTextureManager() {
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
                                      int height) {
    return _adapter.createSpriteSheet(path, spriteSheetId, rows, columns, width, height, _renderer);
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
EngineRenderingAPI::drawTexture(std::string textureId, int x, int y, int width, int height, double scale, double r) {
    return _adapter.drawTexture(textureId, x, y, width, height, scale, r, _renderer, SDL_FLIP_NONE);
}


/**
 * @param path
 * @param textureId
 * @return success
 */
bool EngineRenderingAPI::loadTexture(const char *path, std::string textureId) {
    return RenderingEngineAdapter::GetTextureManager()->load(path, textureId, _renderer);
}