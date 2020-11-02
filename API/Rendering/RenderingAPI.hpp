#pragma once

#include "../../Engine/Rendering/Adapter/RenderingEngineAdapter.hpp"

class RenderingAPI {
    virtual void drawTexture(std::string textureId, int x, int y, int width, int height, double scale, double r) = 0;

    virtual Spritesheet *
    createSpriteSheet(char const *path, std::string spriteSheetId, int rows, int columns, int width, int height) = 0;


    virtual bool loadTexture(const char *path, std::string textureId) = 0;
};