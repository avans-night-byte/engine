#pragma once
#include "RenderingAPI.hpp"

class EngineRenderingAPI : RenderingAPI {
public:
    void drawTexture(RenderingEngineAdapter adapter, std::string textureId, int x, int y, int width, int height, double scale, double r, SDL_Renderer *renderer, SDL_RendererFlip flip) override;
    Spritesheet*  createSpriteSheet(RenderingEngineAdapter adapter, char const*path, std::string spriteSheetId, int rows, int columns, int width, int height, SDL_Renderer* renderer) override;
    static TextureManager* GetTextureManager();
};