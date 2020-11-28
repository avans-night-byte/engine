#include "Spritesheet.hpp"

#include <utility>
#include "TextureManager.hpp"

Spritesheet::Spritesheet(const char *path,
                         std::string spriteSheetid,
                         int row, int column, int width, int height,
                         SDL_Renderer *renderer) : textureId(std::move(spriteSheetid)), sdlRenderer(renderer) {
    TextureManager::GetInstance()->load(path, textureId, renderer);

    // Define the height/width of each sprite by rows/columns.
    m_clip.w = width;
    m_clip.h = height;
}


// Free the surface in order to free memory.
Spritesheet::~Spritesheet()
{
    TextureManager::GetInstance()->clearFromTextureMap(textureId);
}


void Spritesheet::select_sprite(int x, int y)
{
    m_clip.x = x * m_clip.w;
    m_clip.y = y * m_clip.h;
}

void Spritesheet::draw_selected_sprite(float x, float y)
{
    return TextureManager::GetInstance()->drawFrame(textureId, &m_clip, x, y, sdlRenderer, SDL_FLIP_NONE);
}
