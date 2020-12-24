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
    EngineRenderingAdapter& _adapter;

public:
    EngineRenderingAPI() : _adapter(Engine::getInstance()->getRenderingAdapter()) {

    };

    void drawTexture(const std::string &textureId, float x, float y, float width, float height, double scale, double r) const override;

    [[nodiscard]] SpriteSheet *
    loadSpriteSheet(std::string path, std::string spriteSheetId, int width, int height, int offsetX, int offsetY) const override;

    void createText(const std::string &fontName, const std::string &text, int fontSize, const std::string &hex,
                    const std::string &textureId) const override;

    void drawLine(Vector2 &a, Vector2 &b) const override;

    static TextureManager *getTextureManager();

    bool loadTexture(const std::string &path, const std::string &textureId) override;

    void drawRectangle(Vector2 &position, float width, float height, std::string &color, float opacity) const override;

    void drawBackground(std::string &hex, float alpha) const override;

    TMXLevel *loadTMX(const LevelData &levelData, PhysicsEngineAdapter &physicsEngineAdapter) override;

    void render() const override;

    void drawAnimation(std::string &spriteId, const Vector2 &position, const Vector2 &size, const int &speed,
                       const std::vector<std::pair<int, int>> &animation) override;


    void drawBox(const Vector2 *vertices, int32 vertexCount) const override;

    [[nodiscard]] EngineRenderingAdapter &getRendererAdapter() override;
};