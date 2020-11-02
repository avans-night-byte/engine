//
// Created by sasch on 04/10/2020.
//

#ifndef SDL2TEST_TEXTUREMANAGER_HPP
#define SDL2TEST_TEXTUREMANAGER_HPP
#include <SDL_render.h>
#include <SDL_image.h>
#include <map>

class TextureManager {
private:
    std::map<std::string, SDL_Texture*> TextureMap;
    static TextureManager* instance;
public:
    SDL_Texture* GetTexture(std::string textureId);
    bool CreateTexture(SDL_Surface * surface, std::string textureId, SDL_Renderer* renderer);
    bool load(char const *path, std::string textureId, SDL_Renderer *renderer);
    void draw(std::string textureId, int x, int y, int w, int h, double scale, double r, SDL_Renderer* renderer, SDL_RendererFlip = SDL_FLIP_NONE);

    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip);
    void drawFrame(std::string id, SDL_Rect* srcRect, int x, int y, SDL_Renderer *pRenderer, SDL_RendererFlip flip);
    void clearFromTextureMap(std::string id);

    static TextureManager* GetInstance();
};


#endif //SDL2TEST_TEXTUREMANAGER_HPP
