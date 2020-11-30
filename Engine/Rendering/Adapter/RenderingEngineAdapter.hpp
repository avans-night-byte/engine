#pragma once

typedef signed int int32;

#include <iostream>
#include "memory"
#include <math.h>

#include "../TextureManager.hpp"
#include "../Spritesheet.hpp"
#include "../../Vector2.hpp"

// TODO: Store the SDL_renderer here, in the engine instead of the API?

class RenderingEngineAdapter {
private:
public:
    void drawTexture(std::string textureId, int x, int y, int width, int height, double scale, double r,
                     SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    Spritesheet *
    createSpriteSheet(char const *path, std::string spriteSheetId, int rows, int columns, int width, int height,
                      SDL_Renderer *renderer);

    static TextureManager *GetTextureManager();

    void drawRectangle(const Vector2 *vertices, int32 vertexCount, SDL_Renderer *renderer) const;

    void drawLine(const Vector2 &begin, const Vector2 &end, SDL_Renderer *renderer) const;

//    void drawSolidRectangle(const Vector2 &position, const Vector2 &size, SDL_Renderer *renderer) const;

    void drawCircle(const Vector2 &center, const float &radius, SDL_Renderer *renderer) const;
};