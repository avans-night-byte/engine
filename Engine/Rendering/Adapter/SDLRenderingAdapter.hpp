#pragma once

typedef signed int int32;


#include "../TextureManager.hpp"
#include "../SpriteSheet.hpp"
#include "../../../API/Helpers/Vector2.hpp"
#include "EngineRenderingAdapter.hpp"

#include <SDL.h>
#include <iostream>
#include <memory>
#include <map>

class SDLRenderingAdapter : public EngineRenderingAdapter {
private:
    SDL_Renderer* _renderer;
    std::map<std::string, std::unique_ptr<SpriteSheet>> _spriteSheets;

public:
    SDLRenderingAdapter(SDL_Renderer *renderer);

private:
    SDL_Color HexToRGB(std::string hex, float opacity) const;

public:
    [[nodiscard]] SDL_Renderer &getRenderer();

    static TextureManager *GetTextureManager();

public:
    void drawTexture(std::string textureId, float x, float y, float width, float height, double scale, double r,
                     SDL_RendererFlip flip = SDL_FLIP_NONE) override;

    SpriteSheet *createSpriteSheet(const std::string &path, std::string &spriteSheetId, int width, int height) override;

    void drawBox(const Vector2 *vertices, int32 vertexCount) const override;

    void drawLine(const Vector2 &begin, const Vector2 &end) const override;

    void drawCircle(const Vector2 &center, const float &radius) const override;

    void drawRectangle(Vector2 &vector2, float width, float height, const std::string &color, float opacity) const override;


    void createText(const std::string &fontName, const std::string &text, int fontSize, const std::string &hex,
                    const std::string &textureId) override;

    void drawBackground(std::string &color, float alpha) override;

    void render() override;

    void drawAnimation(std::string &spriteId, const Vector2 &position,
                       const std::vector<std::pair<int, int>> &animation, const int &speed) override;

    void deleteRenderer() override;
};