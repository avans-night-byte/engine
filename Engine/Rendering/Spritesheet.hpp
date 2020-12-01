#pragma once

#include <SDL_render.h>
#include <SDL_image.h>
#include <string>
#include "../../Libraries/json.hpp"

class Spritesheet{
    public:
        Spritesheet(const char *path, std::string spriteSheetid, int width, int height,
                    SDL_Renderer *renderer);
        Spritesheet(const char* path, const char* jsonPath, std::string spriteSheetId, SDL_Renderer* renderer);
        ~Spritesheet();
        void draw_selected_sprite(float x, float y, float scale = 1);
        void select_sprite(int x, int y);
        void select_sprite(const std::string &spriteName);
private:
        SDL_Rect     m_clip;
        std::string textureId;
        SDL_Renderer* sdlRenderer;
        nlohmann::json j;


};