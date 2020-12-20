#include "SpriteSheet.hpp"
#include "TextureManager.hpp"

#include <iostream>


SpriteSheet::SpriteSheet(const std::string &path, std::string &spriteSheetId, int width, int height,
                         SDL_Renderer &renderer) : _sdlRenderer(renderer) {
    textureId = spriteSheetId;

    TextureManager::GetInstance()->load(path, textureId);

    // Define the height/width of each sprite by rows/columns.
    m_clip.w = width;
    m_clip.h = height;
}

SpriteSheet::SpriteSheet(const std::string &path, const std::string &jsonPath, std::string &spriteSheetId,
                         SDL_Renderer &renderer) : _sdlRenderer(renderer) {
    textureId = spriteSheetId;

    TextureManager::GetInstance()->load(path, textureId);

}

// Free the surface in order to free memory.
SpriteSheet::~SpriteSheet() {
    TextureManager::GetInstance()->clearFromTextureMap(textureId);
}

void SpriteSheet::selectSprite(int x, int y) {
    m_clip.x = x * m_clip.w;
    m_clip.y = y * m_clip.h;
}


void SpriteSheet::drawSelectedSprite(float x, float y, float scale, float rotation) {
    return TextureManager::GetInstance()->drawFrame(textureId, &m_clip, x, y, &_sdlRenderer, SDL_FLIP_NONE, scale,
                                                    rotation);
}