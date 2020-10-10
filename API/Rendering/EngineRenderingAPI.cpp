#include "EngineRenderingAPI.hpp"


TextureManager * EngineRenderingAPI::GetTextureManager() {
    return RenderingEngineAdapter::GetTextureManager();
}
Spritesheet * EngineRenderingAPI::createSpriteSheet(RenderingEngineAdapter adapter, const char *path, std::string spriteSheetId, int rows, int columns, int width, int height,
                                                    SDL_Renderer *renderer) {
    return adapter.createSpriteSheet(path, spriteSheetId, rows, columns, width, height, renderer);
}
void EngineRenderingAPI::drawTexture(RenderingEngineAdapter adapter, std::string textureId, int x, int y, int width, int height, double scale, double r,
                                     SDL_Renderer *renderer, SDL_RendererFlip flip) {
    return adapter.drawTexture(textureId, x,y, width, height, scale, r, renderer, flip);
}



