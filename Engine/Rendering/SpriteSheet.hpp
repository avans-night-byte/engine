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

    void draw_selected_sprite(float x, float y, float scale = 1, float rotation = 0);

    void select_sprite(int x, int y);

    void select_sprite(const std::string &spriteName);

private:
    SDL_Rect m_clip{};
    std::string textureId;
    SDL_Renderer &_sdlRenderer;
    nlohmann::json j;


};