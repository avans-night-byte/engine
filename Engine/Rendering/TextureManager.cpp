#include "TextureManager.hpp"
#include "../Engine.hpp"
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

    TextureMap[textureId] = surfaceTexture;
    return true;
}

bool TextureManager::load(const char *path, const std::string& textureId) {
    SDL_Surface* tmpSurface = IMG_Load(path);
    std::cout << IMG_GetError() << std::endl;
    
    if(tmpSurface == nullptr){
        // Failed loading image.
        return false;
    }
    
    SDL_Texture* surfaceTexture = SDL_CreateTextureFromSurface(Engine::getInstance()->getRenderer(), tmpSurface);

    if(surfaceTexture == nullptr){
        return false;
    }
    TextureMap[textureId] = surfaceTexture;
    SDL_FreeSurface(tmpSurface);
    return true;
}

void TextureManager::draw(std::string textureId, int x, int y, int width, int height, double scale, double r, SDL_Renderer *renderer,
                     SDL_RendererFlip flip) {
    // Copy the srcrect to the distrect.
    auto texture = TextureMap[textureId];

    if(width == 0 && height == 0){
        SDL_QueryTexture(texture, NULL,NULL, &width, &height);
    }
    SDL_Rect destRect = { x, y , width, height };

    SDL_RenderCopyEx(renderer, texture, NULL, &destRect,0, NULL,  flip);
}

void
TextureManager::drawFrame(std::string id, float x, float y, int width, int height, int currentRow, int currentFrame,
                          SDL_Renderer *pRenderer, SDL_RendererFlip flip, float rotation)
{
    SDL_Rect srcRect; //source rectangle
    SDL_FRect destRect; //destination rectangle

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    destRect.w = srcRect.w = width;
    destRect.h = srcRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyExF(pRenderer, TextureMap[id], &srcRect, &destRect, rotation, 0, flip); //Load current frame on the buffer game.
}


void TextureManager::drawFrame(std::string id, SDL_Rect *srcRect, float x, float y, SDL_Renderer *pRenderer,
                               SDL_RendererFlip flip,
                               float scale, float rotation)
{
    SDL_FRect destRect; //destination rectangle

    destRect.x = x;
    destRect.y = y;
    destRect.w = srcRect->w * scale;
    destRect.h = srcRect->h * scale;
    SDL_RenderCopyExF(pRenderer, TextureMap[id], srcRect, &destRect, rotation, nullptr, flip); //Load current frame on the buffer game.
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

Vector2 TextureManager::getDimensions(std::string id) {
    auto texture = TextureMap[id];

    int width;
    int height;
    SDL_QueryTexture(texture, NULL,NULL, &width, &height);

    return Vector2((float)width, (float)height);
}


