#pragma once

#include "../../../API/Helpers/Vector2.hpp"

#include <SDL_render.h>
#include <string>

class EngineRenderingAdapter {
public:
    virtual void drawTexture(std::string textureId, float x, float y, float width, float height, double scale, double r,
                             SDL_RendererFlip flip = SDL_FLIP_NONE) = 0;

    virtual SpriteSheet *
    createSpriteSheet(const std::string &path, std::string &spriteSheetId, int width, int height, int offsetX,
                      int offsetY) = 0;

    virtual void drawBox(const Vector2 *vertices, int32 vertexCount) const = 0;

    virtual void drawLine(const Vector2 &begin, const Vector2 &end) const = 0;

    virtual void drawCircle(const Vector2 &center, const float &radius) const = 0;

    virtual void
    drawRectangle(Vector2 &vector2, float width, float height, const std::string &color, float opacity) const = 0;

    virtual void createText(const std::string &fontName, const std::string &text, int fontSize, const std::string &hex,
                            const std::string &textureId) = 0;

    virtual void drawBackground(std::string &color, float alpha) = 0;

    virtual void render() = 0;

    virtual void
    drawAnimation(std::string &spriteId, const Vector2 &position, const Vector2 &size, const int &speed,
                  const std::vector<std::pair<int, int>> &animation) = 0;

    virtual void deleteRenderer() = 0;
};