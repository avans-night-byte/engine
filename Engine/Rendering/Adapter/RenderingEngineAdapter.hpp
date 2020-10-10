#pragma once
#include <map>
class RenderingEngineAdapter{
    private:
    public:
        void drawTexture(unsigned long textureId, int x, int y, int w, int h, double scale, double r, SDL_Renderer* renderer, SDL_RendererFlip = SDL_FLIP_NONE);
};