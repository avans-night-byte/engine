#pragma once

#include <SDL_render.h>
#include <SDL_image.h>
#include <string>
#include "../../Libraries/json.hpp"

class SpriteSheet {
public:
    SpriteSheet(const std::string &path, std::string &spriteSheetId, int width, int height,
                SDL_Renderer &renderer);

    SpriteSheet(const std::string &path, const std::string &jsonPath, std::string &spriteSheetId, SDL_Renderer &renderer);

    ~SpriteSheet();

    void drawSelectedSprite(float x, float y, float scale = 1, float rotation = 0);

    void selectSprite(int x, int y);

    void selectSprite(const std::string &spriteName);

    inline const std::string& getTextureId() {
        return textureId;
    }

private:
    SDL_Rect m_clip{};
    std::string textureId;
    SDL_Renderer &_sdlRenderer;
};