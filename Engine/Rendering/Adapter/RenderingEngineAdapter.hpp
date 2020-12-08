#pragma once

typedef signed int int32;

#include <iostream>
#include "memory"
#include <math.h>

#include "../TextureManager.hpp"
#include "../Spritesheet.hpp"
#include "../../Vector2.hpp"
#include <SDL.h>


// TODO: Store the SDL_renderer here, in the engine instead of the API?

class RenderingEngineAdapter {
private:
    SDL_Color HexToRGB(std::string hex, float opacity) const;
    void drawRectContent(Vector2 &position, float width, float height, std::string &content, SDL_Renderer *renderer);
public:
    void drawTexture(std::string textureId, int x, int y, int width, int height, double scale, double r,
                     SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    Spritesheet *
    createSpriteSheet(char const *path, std::string spriteSheetId, int rows, int columns, int width, int height,
                      SDL_Renderer *renderer);

    Spritesheet *
    createSpriteSheet(char const *path, char const *jsonPath, std::string spriteSheetId,
                      SDL_Renderer *renderer);

    static TextureManager *GetTextureManager();

    void drawBox(const Vector2 *vertices, int32 vertexCount, SDL_Renderer *renderer) const;

    void drawLine(const Vector2 &begin, const Vector2 &end, SDL_Renderer *renderer) const;

//    void drawSolidRectangle(const Vector2 &position, const Vector2 &size, SDL_Renderer *renderer) const;

    void drawCircle(const Vector2 &center, const float &radius, SDL_Renderer *renderer) const;

    void drawRectangle(Vector2 &vector2, float width, float height, const std::string& color, float opacity, SDL_Renderer *renderer) const;



    void createText(std::string fontName, const char *text, const int fontSize, SDL_Color color, std::string textureId,
                    SDL_Renderer *renderer);

    void drawBackground(std::string color, float alpha, SDL_Renderer *renderer);
};