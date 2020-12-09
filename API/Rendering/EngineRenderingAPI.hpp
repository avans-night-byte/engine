#pragma once

#include "RenderingAPI.hpp"
#include "../../Engine/Engine.hpp"
#include "../../Engine/Rendering/Adapter/RenderingEngineAdapter.hpp"

class TextureManager;

/**
 * This class acts as a facade for the engine, it stores and references variables and constants needed for rendering
 * and resource allocation like textures.
 */
class EngineRenderingAPI : public RenderingAPI {
private:
    RenderingEngineAdapter *_adapter;
    SDL_Renderer *_renderer;

public:
    EngineRenderingAPI() : _renderer(Engine::getInstance()->getRenderer()), _adapter(new RenderingEngineAdapter{}) {

    };

    void drawTexture(std::string textureId, float x, float y, float width, float height, double scale, double r) const override;

    Spritesheet *createSpriteSheet(char const *path, std::string spriteSheetId, int rows, int columns, int width,
                                   int height) const override;

    Spritesheet *createSpriteSheet(char const *path, char const *jsonPath, std::string spriteSheetId);

    void createText(std::string fontName, const char *text, int fontSize, SDL_Color color,
                    std::string textureId) const override;

    static TextureManager *GetTextureManager();

    bool loadTexture(const char *path, std::string textureId) override;

    void drawRectangle(Vector2 &position, float width, float height, std::string &color, float opacity) const override;

    void drawBackground(std::string hex, float alpha) const override;

    TMXLevel *loadLevel(const TMXLevelData &levelData, PhysicsEngineAdapter &physicsEngineAdapter) override;

private:
    [[nodiscard]] RenderingEngineAdapter &GetRendererAdapter() const override;
};