#include "SpriteSheet.hpp"
#include "TextureManager.hpp"

#include <utility>
#include <fstream>
#include <iostream>


//TODO: Load metadata from json file.
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

    // Load the json file contents into the class variable.
    std::ifstream i(jsonPath);
    i >> j;
    i.close();
}



// Free the surface in order to free memory.
SpriteSheet::~SpriteSheet() {
    TextureManager::GetInstance()->clearFromTextureMap(textureId);
}


void SpriteSheet::select_sprite(const std::string &spriteName) {
    auto el = j["frames"][spriteName];
    auto frame = el["frame"];

    m_clip.x = frame["x"];
    m_clip.y = frame["y"];

    m_clip.w = frame["w"];
    m_clip.h = frame["h"];
}


void SpriteSheet::select_sprite(int x, int y) {
    m_clip.x = x * m_clip.w;
    m_clip.y = y * m_clip.h;
}


void SpriteSheet::draw_selected_sprite(float x, float y, float scale, float rotation) {
    return TextureManager::GetInstance()->drawFrame(textureId, &m_clip, x, y, &_sdlRenderer, SDL_FLIP_NONE, scale,
                                                    rotation);
}