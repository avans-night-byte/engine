#include "Spritesheet.hpp"

Spritesheet::Spritesheet(char const *path, int row, int column)
{
    m_spritesheet_image = IMG_Load(path);



    // Define the height/width of each sprite by rows/columns.
    m_clip.w = m_spritesheet_image->w / column;
    m_clip.h = m_spritesheet_image->h / row;
}


// Free the surface in order to free memory.
Spritesheet::~Spritesheet()
{
    SDL_FreeSurface(m_spritesheet_image);
}

void Spritesheet::select_sprite(int x, int y)
{
    m_clip.x = x * m_clip.w;
    m_clip.y = y * m_clip.h;
}

void Spritesheet::draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *position)
{
    SDL_BlitSurface(m_spritesheet_image, &m_clip, window_surface, position);
}
