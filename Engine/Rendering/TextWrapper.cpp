#include "TextWrapper.hpp"

Vector2 TextWrapper::getSize() {
    return _size;
}

std::string TextWrapper::getTextureId() {
    return _textureId;
}

TextWrapper* TextWrapper::createText(const RenderingAPI& _renderingAPI,  const std::string &text, const std::string &fontPath, int fontSize,
                        const std::string &hex,
                        const std::string& textureId) {

    _renderingAPI.createText(fontPath, text, fontSize, hex, textureId);
    return new TextWrapper(text, fontPath, fontSize, hex, textureId, _renderingAPI);
}

TextWrapper::TextWrapper(std::string text, const std::string& fontPath, int fontSize, const std::string& hex,
                         std::string textureId, const RenderingAPI &renderingAPI) : _text(std::move(text)), _textureId(std::move(textureId)), _renderingAPI(renderingAPI) {
    _size = TextureManager::GetInstance()->getDimensions(_textureId);
}

void TextWrapper::render(float x, float y, int width, int height, double scale, double r) {
    _renderingAPI.drawTexture(_textureId, x, y, width, height, scale, r);
}

void TextWrapper::render(float x, float y) {
    _renderingAPI.drawTexture(_textureId, x, y, _size.x, _size.y, 1, 0);
}

