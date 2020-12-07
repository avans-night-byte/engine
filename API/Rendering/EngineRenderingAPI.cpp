#include "EngineRenderingAPI.hpp"

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

void EngineRenderingAPI::createText(std::string fontName, const char* text, const int fontSize, SDL_Color color, std::string textureId){
    return _adapter->createText(fontName, text, fontSize, color, textureId, _renderer);
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
void EngineRenderingAPI::drawTexture(std::string textureId, int x, int y, int width, int height, double scale, double r)
{
    return _adapter->drawTexture(textureId, x, y, width, height, scale, r, _renderer, SDL_FLIP_NONE);
}

/**
 * @param path
 * @param textureId
 * @return success
 */
bool EngineRenderingAPI::loadTexture(const char *path, std::string textureId)
{
    return RenderingEngineAdapter::GetTextureManager()->load(path, textureId, _renderer);
}

const RenderingEngineAdapter &EngineRenderingAPI::GetRendererAdapter() const {
    return *_adapter;
}

void EngineRenderingAPI::drawLine(Vector2 a, Vector2 b) const {
    SDL_RenderDrawLine(_renderer, a.x, a.y, b.x, b.y);

}
