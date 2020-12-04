//
// Created by sascha on 12/3/20.
//

#include "TextWrapper.hpp"

#include <utility>
#include "../../Game/Game.hpp"

Vector2 TextWrapper::getSize() {
    return _size;
}

std::string TextWrapper::getTextureId() {
    return _textureId;
}

TextWrapper*
TextWrapper::createText(const EngineRenderingAPI& _renderingAPI, std::string text, const char *fontPath, int fontSize,
                        SDL_Color color,
                        std::string textureId) {

    _renderingAPI.createText(fontPath, text.c_str(), fontSize, color, textureId);
    return new TextWrapper(text, fontPath, fontSize, color, textureId, _renderingAPI);
}

TextWrapper::TextWrapper(std::string text, const char *fontPath, int fontSize, SDL_Color color,
                         std::string textureId, const EngineRenderingAPI& renderingAPI) : _text(std::move(text)), _textureId(std::move(textureId)), _renderingAPI(renderingAPI) {
    _size = TextureManager::GetInstance()->getDimensions(_textureId);
}

void TextWrapper::render(int x, int y, int width, int height, double scale, double r) {
    _renderingAPI.drawTexture(_textureId, x, y, width, height, scale, r);
}

void TextWrapper::render(int x, int y) {
    _renderingAPI.drawTexture(_textureId, x, y, _size.x, _size.y, 1, 0);
}

