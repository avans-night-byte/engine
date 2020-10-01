#pragma once
#include "../Spritesheet.hpp"

class RenderingEngineAdapter{
    public:
        Spritesheet* CreateSpriteSheet(char const* path, int rows, int columns);
        SDL_Surface* CreateSurface();    

};