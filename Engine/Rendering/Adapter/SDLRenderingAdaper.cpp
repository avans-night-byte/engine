#include "SDLRenderingAdapter.hpp"
#include "../../Engine.hpp"

#include <regex>
#include <SDL_ttf.h>


typedef signed int int32;


SDLRenderingAdapter::SDLRenderingAdapter(SDL_Renderer *renderer) {
    _renderer = renderer;
}

TextureManager *SDLRenderingAdapter::GetTextureManager() {
    return TextureManager::getInstance();
}

void SDLRenderingAdapter::drawTexture(std::string textureId, float x, float y, float width, float height, double scale,
                                      double r, SDL_RendererFlip flip) {
    TextureManager *textureManager = TextureManager::getInstance();
    return textureManager->draw(textureId, x, y, width, height, scale, r, _renderer, flip);
}

void SDLRenderingAdapter::drawBackground(std::string &color, float alpha) {
    SDL_Color c = HexToRGB(color, alpha);
    SDL_SetRenderDrawColor(_renderer, c.r, c.g, c.b, c.a);

    SDL_RenderClear(_renderer);
}

SpriteSheet *
SDLRenderingAdapter::createSpriteSheet(const std::string &path, std::string &spriteSheetId, int width, int height,
                                       int offsetX, int offsetY) {
    auto &spriteSheet = _spriteSheets[spriteSheetId];
    if (spriteSheet != nullptr) {
        return spriteSheet.get();
    }

    spriteSheet = std::make_unique<SpriteSheet>(path, spriteSheetId, width, height, offsetX, offsetY, *_renderer);
    auto *p = spriteSheet.get();
    _spriteSheets[spriteSheetId] = std::move(spriteSheet);

    return p;
}

void SDLRenderingAdapter::drawBox(const Vector2 *vertices, int32 vertexCount) const {
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_FPoint points[vertexCount];
    for (int i = 0; i < vertexCount; ++i) {
        SDL_FPoint p = SDL_FPoint();
        p.x = vertices[i].x;
        p.y = vertices[i].y;

        points[i] = p;
    }


    int size = sizeof(points) / sizeof(points[0]);
    Vector2 begin = Vector2(points[0].x, points[0].y);
    Vector2 end = Vector2(points[size - 1].x, points[size - 1].y);

    drawLine(begin, end);
    SDL_RenderDrawLinesF(_renderer, points, vertexCount);
}

void SDLRenderingAdapter::drawRectangle(Vector2 &position, float width, float height, const std::string &color,
                                        float opacity) const {
    SDL_Color sdlColor = HexToRGB(color, opacity);
    SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(_renderer, sdlColor.r, sdlColor.g, sdlColor.b, sdlColor.a);
    SDL_FRect rectangle;

    rectangle.x = position.x;
    rectangle.y = position.y;
    rectangle.w = width;
    rectangle.h = height;

    SDL_RenderFillRectF(_renderer, &rectangle);
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

SDL_Color SDLRenderingAdapter::HexToRGB(std::string hex, float opacity) const {

    std::regex pattern("#?([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})");

    std::smatch match;
    if (std::regex_match(hex, match, pattern)) {
        SDL_Color color;

        color.r = std::stoi(match[1].str(), nullptr, 16);
        color.g = std::stoi(match[2].str(), nullptr, 16);
        color.b = std::stoi(match[3].str(), nullptr, 16);
        color.a = opacity;

        return color;
    } else {
        throw " is an invalid rgb color\n";
    }

}

void SDLRenderingAdapter::drawLine(const Vector2 &begin, const Vector2 &end) const {
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLineF(_renderer, begin.x, begin.y, end.x, end.y);
}

void SDLRenderingAdapter::drawCircle(const Vector2 &center, const float &radius) const {
    float x = center.x;
    float y = center.y;
    float iRadius = radius;
    int num_segments = iRadius * iRadius;

    SDL_Renderer *renderer = _renderer;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    for (int ii = 0; ii < num_segments; ii++) {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float cx = iRadius * cosf(theta);//calculate the x component
        float cy = iRadius * sinf(theta);//calculate the y component

        SDL_RenderDrawPointF(renderer, x + cx, y + cy);//output vertex
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPointF(renderer, x, y);
    SDL_RenderDrawPointF(renderer, x + 1, y);
    SDL_RenderDrawPointF(renderer, x - 1, y);
    SDL_RenderDrawPointF(renderer, x, y + 1);
    SDL_RenderDrawPointF(renderer, x, y - 1);
}

void SDLRenderingAdapter::createText(const std::string &fontName, const std::string &text, const int fontSize,
                                     const std::string &hex, const std::string &textureId) {
    TTF_Font *font = TTF_OpenFont(fontName.c_str(), fontSize);
    SDL_Surface *surfaceMessage = TTF_RenderUTF8_Blended(font, text.c_str(), HexToRGB(hex, 255));

    GetTextureManager()->CreateTexture(surfaceMessage, textureId, _renderer);
    TTF_CloseFont(font);
}

void SDLRenderingAdapter::render() {
    SDL_RenderPresent(_renderer);
    SDL_RenderClear(_renderer);
}

SDL_Renderer &SDLRenderingAdapter::getRenderer() {
    return *_renderer;
}

void SDLRenderingAdapter::drawAnimation(std::string &spriteId, const Vector2 &position, const Vector2 &size,
                                        const int &speed,
                                        const std::vector<std::pair<int, int>> &animation) {
    auto *spriteSheet = _spriteSheets[spriteId].get();
    const auto& clip = spriteSheet->getClip();
    auto *texture = GetTextureManager()->getTexture(spriteSheet->getTextureId());
    const int &totalFrames = animation.size();
    int frame = (int)(SDL_GetTicks() / speed) % totalFrames;

    // Frame
    SDL_Rect rect;
    rect.x = frame * clip.w; // Row
    rect.y = animation[frame].second * clip.h; // Collum
    rect.w = clip.w;
    rect.h = clip.h;

    // Sprite transform
    SDL_FRect windowRect;
    windowRect.x = position.x + clip.x;
    windowRect.y = position.y + clip.y;
    windowRect.w = size.x;
    windowRect.h = size.y;


    SDL_RenderCopyExF(_renderer, texture, &rect, &windowRect, 0, nullptr, SDL_RendererFlip::SDL_FLIP_NONE);
}

void SDLRenderingAdapter::deleteRenderer() {
    SDL_DestroyRenderer(_renderer);
}