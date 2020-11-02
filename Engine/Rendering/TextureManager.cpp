#include "TextureManager.hpp"
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

bool TextureManager::load(const char *path, std::string textureId, SDL_Renderer *renderer) {
    SDL_Surface* tmpSurface = IMG_Load(path);
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

    // Copy the srcrect to the distrect.
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;

    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;

    destRect.h = destRect.h *scale;
    destRect.w = destRect.w *scale;

    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(renderer, TextureMap[textureId], &srcRect, &destRect,0,0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect; //source rectangle
    SDL_Rect destRect; //destination rectangle

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, TextureMap[id], &srcRect, &destRect, 0, 0, flip); //Load current frame on the buffer game.
}


void TextureManager::drawFrame(std::string id, SDL_Rect* srcRect, int x, int y, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect destRect; //destination rectangle

    destRect.x = x;
    destRect.y = y;
    destRect.w = srcRect->w;
    destRect.h = srcRect->h;
    SDL_RenderCopyEx(pRenderer, TextureMap[id], srcRect, &destRect, 0, 0, flip); //Load current frame on the buffer game.
}


void TextureManager::clearFromTextureMap(std::string id)
{
    TextureMap.erase(id);
}


