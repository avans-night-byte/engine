#include "TextureManager.hpp"
#include <iostream>

TextureManager* TextureManager::instance = nullptr;

TextureManager* TextureManager::GetInstance() {
    if(instance == nullptr){
        instance = new TextureManager();
    }
    return instance;
}

SDL_Texture *TextureManager::GetTexture(std::string textureId) {
    SDL_Texture* tmpTexture = TextureMap[textureId];
    return tmpTexture;
}

bool TextureManager::CreateTexture(SDL_Surface *surface, std::string textureId, SDL_Renderer* renderer) {

    SDL_Texture* surfaceTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if(surfaceTexture == nullptr){
        return false;
    }

    SDL_FreeSurface(surface);
    TextureMap[textureId] = surfaceTexture;
    return true;
}

bool TextureManager::load(const char *path, std::string textureId, SDL_Renderer *renderer) {
    SDL_Surface* tmpSurface = IMG_Load(path);
    std::cout << IMG_GetError() << std::endl;
    
    if(tmpSurface == nullptr){
        // Failed loading image.
        return false;
    }
    
    SDL_Texture* surfaceTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    if(surfaceTexture == nullptr){
        return false;
    }

    TextureMap[textureId] = surfaceTexture;
    return true;
}

void TextureManager::draw(std::string textureId, int x, int y, int width, int height, double scale, double r, SDL_Renderer *renderer,
                     SDL_RendererFlip flip) {


    auto texture = TextureMap[textureId];
    // Copy the srcrect to the distrect.
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;

    if(width == 0 && height == 0){
        SDL_QueryTexture(texture, NULL,NULL, &width, &height);
    }


    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;

    destRect.h = destRect.h *scale;
    destRect.w = destRect.w *scale;

    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect,0,0, flip);
}

void TextureManager::drawFrame(std::string id, float x, float y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect; //source rectangle
    SDL_FRect destRect; //destination rectangle

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    destRect.w = srcRect.w = width;
    destRect.h = srcRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyExF(pRenderer, TextureMap[id], &srcRect, &destRect, 0, 0, flip); //Load current frame on the buffer game.
}


void TextureManager::drawFrame(std::string id, SDL_Rect* srcRect, float x, float y, SDL_Renderer *pRenderer, SDL_RendererFlip flip, float scale)
{
    SDL_FRect destRect; //destination rectangle

    destRect.x = x;
    destRect.y = y;
    destRect.w = srcRect->w * scale;
    destRect.h = srcRect->h * scale;
    SDL_RenderCopyExF(pRenderer, TextureMap[id], srcRect, &destRect, 0, 0, flip); //Load current frame on the buffer game.
}


void TextureManager::clearFromTextureMap(std::string id)
{
    SDL_DestroyTexture(TextureMap[id]);
    TextureMap.erase(id);
}

TextureManager::~TextureManager() {
    std::map<std::string, SDL_Texture*>::iterator it;
    for ( it = TextureMap.begin(); it != TextureMap.end(); it++ )
    {
        this->clearFromTextureMap(it->first);
    }
}


