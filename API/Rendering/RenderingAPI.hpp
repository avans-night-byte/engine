#pragma once
#include "../../Engine/Rendering/Adapter/RenderingEngineAdapter.hpp"

class RenderingAPI {
    virtual void drawTexture(std::string textureId, int x, int y, int width, int height, double scale, double r) = 0;

    virtual Spritesheet *createSpriteSheet(char const *path, std::string spriteSheetId, int rows, int columns, int width, int height) const = 0;

    virtual bool loadTexture(const char *path, std::string textureId) = 0;

    virtual void drawLine(Vector2 a, Vector2 b) const = 0;



public:
    [[nodiscard]] virtual const RenderingEngineAdapter& GetRendererAdapter() const = 0;
};