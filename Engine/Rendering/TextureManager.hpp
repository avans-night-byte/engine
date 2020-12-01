#pragma once

#include <SDL_render.h>
#include <SDL_image.h>
#include <map>
#include <string>

class TextureManager {
private:
    std::map<std::string, SDL_Texture*> TextureMap;
    static TextureManager* instance;
public:
    ~TextureManager();
    SDL_Texture* GetTexture(std::string textureId);
    bool CreateTexture(SDL_Surface * surface, std::string textureId, SDL_Renderer* renderer);
    bool load(char const *path, std::string textureId, SDL_Renderer *renderer);
    void draw(std::string textureId, int x, int y, int w, int h, double scale, double r, SDL_Renderer* renderer, SDL_RendererFlip = SDL_FLIP_NONE);

    void drawFrame(std::string id, float x, float y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip);
    void drawFrame(std::string id, SDL_Rect* srcRect, float x, float y, SDL_Renderer *pRenderer, SDL_RendererFlip flip, float scale = 1);
    void clearFromTextureMap(std::string id);

    static TextureManager* GetInstance();
};
