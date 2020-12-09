#pragma once
#include <string>
#include "../Vector2.hpp"
#include "Adapter/RenderingEngineAdapter.hpp"
#include "../../API/Rendering/EngineRenderingAPI.hpp"
#include <SDL_ttf.h>

class TextWrapper {
private:
    const RenderingAPI& _renderingAPI;
    const std::string _textureId;
    const std::string _text;
    Vector2 _size;
    TextWrapper(std::string  text, const char* fontPath, int fontSize, SDL_Color color, std::string textureId, const RenderingAPI& renderingAPI);

public:
    Vector2 getSize();
    std::string getTextureId();
    void render(float x, float y, int width, int height, double scale, double r);
    void render(float x, float y);
    static TextWrapper* createText(const RenderingAPI& _renderingAPI, std::string text, const char* fontPath, int fontSize, SDL_Color color, std::string textureId);
};