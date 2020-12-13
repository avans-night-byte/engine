#pragma once

#include "RenderingAPI.hpp"
#include "../../Engine/Engine.hpp"
#include "../../Engine/Rendering/Adapter/SDLRenderingAdapter.hpp"

class TextureManager;

/**
 * This class acts as a facade for the _engine, it stores and references variables and constants needed for rendering
 * and resource allocation like textures.
 */
class EngineRenderingAPI : public RenderingAPI {
private:
    SDLRenderingAdapter *_adapter;
    SDL_Renderer *_renderer;

public:
    EngineRenderingAPI() : _renderer(Engine::getInstance()->getRenderer()), _adapter(new SDLRenderingAdapter{}) {

    };

    void drawTexture(const std::string &textureId, float x, float y, float width, float height, double scale, double r) const override;

    Spritesheet *createSpriteSheet(std::string path, std::string spriteSheetId, int width, int height) const override;

    Spritesheet *createSpriteSheet(const std::string &path, const std::string &jsonPath, std::string &spriteSheetId);

    void createText(const std::string &fontName, const std::string &text, int fontSize, const std::string &hex,
                    const std::string &textureId) const override;

    void drawLine(Vector2 &a, Vector2 &b) const override;

    static TextureManager *GetTextureManager();

    bool loadTexture(const std::string &path, std::string &textureId) override;

    void drawRectangle(Vector2 &position, float width, float height, std::string &color, float opacity) const override;

    void drawBackground(std::string &hex, float alpha) const override;

    TMXLevel *loadLevel(const LevelData &levelData, PhysicsEngineAdapter &physicsEngineAdapter) override;

    void render() const override;

private:
    [[nodiscard]] SDLRenderingAdapter &GetRendererAdapter() const override;
};