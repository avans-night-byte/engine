#pragma once
#include <string>
#include "../Helpers/Vector2.hpp"
#include "Adapter/SDLRenderingAdapter.hpp"
#include "../../API/Rendering/EngineRenderingAPI.hpp"
#include <SDL_ttf.h>

class TextWrapper {
private:
    const RenderingAPI& _renderingAPI;
    const std::string _textureId;
    const std::string _text;
    Vector2 _size;
    TextWrapper(std::string text, const std::string& fontPath, int fontSize, const std::string& hex, std::string textureId, const RenderingAPI& renderingAPI);

public:
    Vector2 getSize();
    std::string getTextureId();
    void render(float x, float y, int width, int height, double scale, double r);
    void render(float x, float y);
    static TextWrapper* createText(const RenderingAPI &renderingAPI, std::string &text, const std::string &fontPath, int fontSize, std::string &hex, const std::string& textureId);
};