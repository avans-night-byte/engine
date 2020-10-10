#pragma once
#include "../../Engine/Rendering/Adapter/RenderingEngineAdapter.hpp"

class RenderingAPI {
    virtual void drawTexture(RenderingEngineAdapter adapter, std::string textureId, int x, int y, int width, int height, double scale, double r, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    virtual Spritesheet*  createSpriteSheet(RenderingEngineAdapter adapter, char const*path, std::string spriteSheetId, int rows, int columns, int width, int height, SDL_Renderer* renderer);
    static TextureManager* GetTextureManager();
};