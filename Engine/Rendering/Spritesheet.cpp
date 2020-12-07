#include <fstream>
#include <iostream>
#include "Spritesheet.hpp"

#include <utility>
#include "TextureManager.hpp"


//TODO: Load metadata from json file.
Spritesheet::Spritesheet(const char *path, std::string spriteSheetid, int width, int height,
                         SDL_Renderer *renderer)
{
    textureId = spriteSheetid;
    sdlRenderer = renderer;
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


void Spritesheet::select_sprite(const std::string& spriteName){
    auto el = j["frames"][spriteName];
    auto frame = el["frame"];

    m_clip.x = frame["x"];
    m_clip.y = frame["y"];

    m_clip.w = frame["w"];
    m_clip.h = frame["h"];
}


void Spritesheet::select_sprite(int x, int y)
{
        m_clip.x = x * m_clip.w;
        m_clip.y = y * m_clip.h;
}



void Spritesheet::draw_selected_sprite(float x, float y, float scale, float rotation)
{
    return TextureManager::GetInstance()->drawFrame(textureId, &m_clip, x, y, sdlRenderer, SDL_FLIP_NONE, scale, rotation);
}


Spritesheet::Spritesheet(const char *path, const char *jsonPath, std::string spriteSheetId, SDL_Renderer *renderer) {
    textureId = spriteSheetId;
    sdlRenderer = renderer;

    TextureManager::GetInstance()->load(path, textureId, renderer);

    // Load the json file contents into the class variable.
    std::ifstream i(jsonPath);
    i >> j;
    i.close();
}
