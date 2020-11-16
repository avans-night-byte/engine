#pragma once

#include <SDL_render.h>
#include <SDL_image.h>
#include <string>

class Spritesheet{
    public:
        Spritesheet(const char* path, std::string spriteSheetid, int row, int column, int width, int height, SDL_Renderer* renderer);
        ~Spritesheet();
        void select_sprite(int x, int y);
        void draw_selected_sprite(int x, int y);

    private:
        SDL_Rect     m_clip;
        SDL_Surface *m_spritesheet_image;
        std::string textureId;
        SDL_Renderer* sdlRenderer;
};