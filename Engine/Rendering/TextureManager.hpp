#pragma once

#include <SDL_render.h>
#include <SDL_image.h>
#include <map>
#include <string>
#include "../../API/Helpers/Vector2.hpp"

class TextureManager {
private:
    std::map<std::string, SDL_Texture*> TextureMap;
    static TextureManager* instance;
public:
    ~TextureManager();
    SDL_Texture* GetTexture(std::string textureId);
    bool CreateTexture(SDL_Surface * surface, const std::string &textureId, SDL_Renderer* renderer);
    bool load(const std::string &path, const std::string& textureId);
    void draw(std::string &textureId, int x, int y, int w, int h, double scale, double r, SDL_Renderer* renderer, SDL_RendererFlip = SDL_FLIP_NONE);

    void drawFrame(std::string &id, float x, float y, int width, int height, int currentRow, int currentFrame,
                   SDL_Renderer *pRenderer, SDL_RendererFlip flip, float rotation);

    void drawFrame(std::string &id, SDL_Rect *srcRect, float x, float y, SDL_Renderer *pRenderer, SDL_RendererFlip flip,
                   float scale = 1, float rotation = 0, SDL_FPoint *pivot = nullptr );

    void clearFromTextureMap(std::string &id);
    Vector2 getDimensions(const std::string &id);
    static TextureManager* GetInstance();
};
