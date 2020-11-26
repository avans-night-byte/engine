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
        void select_sprite(int x, int y, bool useJson = false, const std::string& spriteName = "");
        void draw_selected_sprite(int x, int y);

    private:
        SDL_Rect     m_clip;
        SDL_Surface *m_spritesheet_image;
        std::string textureId;
        SDL_Renderer* sdlRenderer;
        nlohmann::json j;
};