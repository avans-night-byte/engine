#include "RenderingEngineAdapter.hpp"
#include <SDL_render.h>
#include "SDL_image.h"
#include "../TextureManager.hpp"
#include <iostream>
#include "../Spritesheet.hpp"



TextureManager* GetTextureManager(){
    return textureManager
}
void drawTexture(std::string textureId, int x, int y, int width, int height, double scale, double r, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE){
    TextureManager* textureManager = TextureManager::GetInstance();
    return textureManager->draw(textureId, x,y, width, height, scale, r, renderer, flip);
}

Spritesheet* createSpriteSheet(char const*path, std::string spriteSheetId, int rows, int columns, SDL_Renderer* renderer){
    return new Spritesheet(path, spriteSheetId, rows, columns , renderer);
}





