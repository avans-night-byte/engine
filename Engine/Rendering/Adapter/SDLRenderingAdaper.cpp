#include "RenderingEngineAdapter.hpp"
#include <SDL_render.h>
#include "SDL_image.h"

SDL_Surface* RenderingEngineAdapter::CreateSurface(char const* path){
    SDL_Surface* surface = IMG_Load(path);
    return surface;
}


