#pragma once
#include "../../../../../../../Desktop/Rendering/Rendering/Spritesheet.hpp"
#include <map>
class RenderingEngineAdapter{
    private:

    public:
        Spritesheet* CreateSpriteSheet(char const* path, int rows, int columns);
        SDL_Surface* CreateSurface(char const* path);
        void draw(unsigned long textureId, int x, int y, int w, int h, double scale, double r, SDL_Renderer* renderer, SDL_RendererFlip = SDL_FLIP_NONE);
};