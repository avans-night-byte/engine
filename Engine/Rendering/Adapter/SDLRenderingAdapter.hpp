#pragma once

typedef signed int int32;

#include <iostream>
#include "memory"
#include <math.h>

#include "../TextureManager.hpp"
#include "../Spritesheet.hpp"
#include "../../../API/Helpers/Vector2.hpp"
#include "EngineRenderingAdapter.h"
#include <SDL.h>


// TODO: Store the SDL_renderer here, in the _engine instead of the API?

class SDLRenderingAdapter : public EngineRenderingAdapter {
private:
    SDL_Color HexToRGB(std::string hex, float opacity) const;

public:
    void drawTexture(std::string textureId, float x, float y, float width, float height, double scale, double r,
                     SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE) override;

    Spritesheet *createSpriteSheet(const std::string &path, std::string &spriteSheetId, int width, int height) override;

    Spritesheet *createSpriteSheet(const std::string &path, const std::string &jsonPath, std::string &spriteSheetId,
                                   SDL_Renderer *renderer) override;

    static TextureManager *GetTextureManager();

    void drawBox(const Vector2 *vertices, int32 vertexCount, SDL_Renderer *renderer) const override;

    void drawLine(const Vector2 &begin, const Vector2 &end, SDL_Renderer *renderer) const override;

//    void drawSolidRectangle(const Vector2 &position, const Vector2 &size, SDL_Renderer *renderer) const;

    void drawCircle(const Vector2 &center, const float &radius, SDL_Renderer *renderer) const override;

    void drawRectangle(Vector2 &vector2, float width, float height, const std::string &color, float opacity,
                       SDL_Renderer *renderer) const override;


    void createText(const std::string &fontName, const std::string &text, int fontSize, const std::string &hex,
                    const std::string &textureId,
                    SDL_Renderer *renderer) override;

    void drawBackground(std::string &color, float alpha, SDL_Renderer *renderer) override;

    void render(SDL_Renderer *pRenderer) override;
};