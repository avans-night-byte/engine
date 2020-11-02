
#pragma once

#include <map>
#include <SDL_render.h>
#include "SDL_image.h"
#include "../TextureManager.hpp"
#include <iostream>
#include "../Spritesheet.hpp"

class RenderingEngineAdapter {
private:
public:
    void drawTexture(std::string textureId, int x, int y, int width, int height, double scale, double r,
                     SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    Spritesheet *
    createSpriteSheet(char const *path, std::string spriteSheetId, int rows, int columns, int width, int height,
                      SDL_Renderer *renderer);

    static TextureManager *GetTextureManager();
};