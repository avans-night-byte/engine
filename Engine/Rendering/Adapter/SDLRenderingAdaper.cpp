#include "RenderingEngineAdapter.hpp"

TextureManager* RenderingEngineAdapter::GetTextureManager(){
    return TextureManager::GetInstance();
}

void RenderingEngineAdapter::drawTexture(std::string textureId, int x, int y, int width, int height, double scale, double r, SDL_Renderer *renderer, SDL_RendererFlip flip){
    TextureManager* textureManager = TextureManager::GetInstance();
    return textureManager->draw(textureId, x,y, width, height, scale, r, renderer, flip);
}

Spritesheet* RenderingEngineAdapter::createSpriteSheet(char const*path, std::string spriteSheetId, int rows, int columns, int width, int height, SDL_Renderer* renderer){
    return new Spritesheet(path, spriteSheetId, rows, columns, width, height, renderer);
}





