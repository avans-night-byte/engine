#pragma once

#include "RenderingAPI.hpp"
#include "../../Engine/Engine.hpp"
/**
 * This class acts as a facade for the engine, it stores and references variables and constants needed for rendering
 * and resource allocation like textures.
 */
class EngineRenderingAPI : RenderingAPI
{
private:
    RenderingEngineAdapter _adapter;
    SDL_Renderer *_renderer;

public:
    explicit EngineRenderingAPI(RenderingEngineAdapter adapter, Engine *engine) : _adapter(adapter),
                                                                                  _renderer(engine->getRenderer()){};

    void drawTexture(std::string textureId, int x, int y, int width, int height, double scale, double r) override;

    Spritesheet *createSpriteSheet(char const *path, std::string spriteSheetId, int rows, int columns, int width,
                                   int height) override;

    static TextureManager *GetTextureManager();

    bool loadTexture(const char *path, std::string textureId) override;
};