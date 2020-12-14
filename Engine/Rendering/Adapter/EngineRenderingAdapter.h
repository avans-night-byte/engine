#pragma once

#include <SDL_render.h>
#include <string>
#include "../../Helpers/Vector2.hpp"
#include "SDLRenderingAdapter.hpp"
#include "../TextureManager.hpp"

class EngineRenderingAdapter{
    virtual void drawTexture(std::string textureId, float x, float y, float width, float height, double scale, double r,
                     SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE)  = 0;

    virtual Spritesheet *createSpriteSheet(const std::string &path, std::string &spriteSheetId, int width, int height) = 0;

    virtual Spritesheet *createSpriteSheet(const std::string &path, const std::string &jsonPath, std::string &spriteSheetId,
                                   SDL_Renderer *renderer) = 0;

    virtual void drawBox(const Vector2 *vertices, int32 vertexCount, SDL_Renderer *renderer) const = 0;

    virtual void drawLine(const Vector2 &begin, const Vector2 &end, SDL_Renderer *renderer) const = 0;

    virtual void drawCircle(const Vector2 &center, const float &radius, SDL_Renderer *renderer) const = 0;

    virtual void drawRectangle(Vector2 &vector2, float width, float height, const std::string &color, float opacity, SDL_Renderer *renderer) const = 0;

    virtual void createText(const std::string &fontName, const std::string &text, int fontSize, const std::string &hex,const std::string &textureId, SDL_Renderer *renderer) = 0;

    virtual void drawBackground(std::string &color, float alpha, SDL_Renderer *renderer) = 0;

    virtual void render(SDL_Renderer *pRenderer) = 0;
};