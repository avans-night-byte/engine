#pragma once
#include "../../Engine/Rendering/Adapter/RenderingEngineAdapter.hpp"

class RenderingAPI {
    virtual void drawTexture(std::string textureId, int x, int y, int width, int height, double scale, double r) const = 0;

    virtual Spritesheet *createSpriteSheet(char const *path, std::string spriteSheetId, int rows, int columns, int width, int height) const = 0;

    virtual bool loadTexture(const char *path, std::string textureId) = 0;

    virtual void drawRectangle(Vector2& position, float width, float height, std::string& color, float opacity = 1) const = 0;

    virtual void createText(std::string fontName, const char* text, const int fontSize, SDL_Color color, std::string textureId) const = 0;

    virtual void drawBackground(std::string hex, float alpha) const = 0;

public:
    [[nodiscard]] virtual const RenderingEngineAdapter& GetRendererAdapter() const = 0;
};