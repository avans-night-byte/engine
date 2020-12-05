#pragma once

#include "RenderingAPI.hpp"
#include "../../Engine/Engine.hpp"

/**
 * This class acts as a facade for the engine, it stores and references variables and constants needed for rendering
 * and resource allocation like textures.
 */
class EngineRenderingAPI : public RenderingAPI
{
private:
    RenderingEngineAdapter *_adapter;
    SDL_Renderer *_renderer;

public:
    explicit EngineRenderingAPI(Engine *engine) :
            _renderer(engine->getRenderer()) {
        _adapter = new RenderingEngineAdapter{};
    };

    void drawTexture(std::string textureId, int x, int y, int width, int height, double scale, double r) const override;

    Spritesheet *createSpriteSheet(char const *path, std::string spriteSheetId, int rows, int columns, int width,
                                   int height) const override;

    Spritesheet *createSpriteSheet(char const *path, char const *jsonPath, std::string spriteSheetId);

    void createText(std::string fontName, const char* text, const int fontSize, SDL_Color color, std::string textureId) const override;

    static TextureManager *GetTextureManager();

    bool loadTexture(const char *path, std::string textureId) override;

    void drawRectangle(Vector2& position, float width, float height, std::string& color, float opacity) const override;

    void drawBackground(std::string hex, float alpha) const override;

private:
    [[nodiscard]] const RenderingEngineAdapter &GetRendererAdapter() const override;
};