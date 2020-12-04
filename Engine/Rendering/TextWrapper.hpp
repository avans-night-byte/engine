//
// Created by sascha on 12/3/20.
//

#ifndef NIGHTBYTE_TEXTWRAPPER_HPP
#define NIGHTBYTE_TEXTWRAPPER_HPP


#include <string>
#include "../Vector2.hpp"
#include "Adapter/RenderingEngineAdapter.hpp"
#include "../../API/Rendering/EngineRenderingAPI.hpp"
#include <SDL_ttf.h>

class TextWrapper {
private:
    const EngineRenderingAPI& _renderingAPI;
    const std::string _textureId;
    const std::string _text;
    Vector2 _size;
    TextWrapper(std::string  text, const char* fontPath, int fontSize, SDL_Color color, std::string textureId, const EngineRenderingAPI& renderingAPI);

public:
    Vector2 getSize();
    std::string getTextureId();
    void render(int x, int y, int width, int height, double scale, double r);
    void render(int x, int y);
    static TextWrapper* createText(const EngineRenderingAPI& _renderingAPI, std::string text, const char* fontPath, int fontSize, SDL_Color color, std::string textureId);
};


#endif //NIGHTBYTE_TEXTWRAPPER_HPP
