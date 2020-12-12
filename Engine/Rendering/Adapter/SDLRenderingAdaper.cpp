#include <regex>
#include <SDL_ttf.h>
#include "RenderingEngineAdapter.hpp"
#include "../../Engine.hpp"

typedef signed int int32;


TextureManager *RenderingEngineAdapter::GetTextureManager() {
    return TextureManager::GetInstance();
}

void
RenderingEngineAdapter::drawTexture(std::string textureId, float x, float y, float width, float height, double scale, double r,
                                    SDL_Renderer *renderer, SDL_RendererFlip flip) {
    TextureManager *textureManager = TextureManager::GetInstance();


    return textureManager->draw(textureId, x, y, width, height, scale, r, renderer, flip);
}

void RenderingEngineAdapter::drawBackground(std::string &color, float alpha, SDL_Renderer *renderer){
    SDL_Color c = HexToRGB(color, alpha);
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);

    SDL_RenderClear(renderer);
}

Spritesheet *
RenderingEngineAdapter::createSpriteSheet(const std::string &path, std::string &spriteSheetId, int width, int height) {
    return new Spritesheet(path, spriteSheetId, width, height, Engine::getInstance()->getRenderer());
}



void RenderingEngineAdapter::drawBox(const Vector2 *vertices, int32 vertexCount, SDL_Renderer *renderer) const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_FPoint points[vertexCount ];
    for (int i = 0; i < vertexCount; ++i) {
        SDL_FPoint p = SDL_FPoint();
        p.x = vertices[i].x;
        p.y = vertices[i].y;

        points[i] = p;
    }


    int size = sizeof(points)/sizeof(points[0]);
    Vector2 begin = Vector2(points[0].x, points[0].y);
    Vector2 end = Vector2(points[size-1].x, points[size-1].y);

    drawLine(begin, end, renderer);
    SDL_RenderDrawLinesF(renderer, points, vertexCount);
}



void RenderingEngineAdapter::drawRectangle(Vector2 &position, float width, float height, const std::string& color, float opacity, SDL_Renderer *renderer) const {

    SDL_Color sdlColor = HexToRGB(color, opacity);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, sdlColor.r, sdlColor.g, sdlColor.b, sdlColor.a);
    SDL_FRect rectangle;

    rectangle.x = position.x;
    rectangle.y = position.y;
    rectangle.w = width;
    rectangle.h = height;

    SDL_RenderFillRectF(renderer, &rectangle);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

SDL_Color RenderingEngineAdapter::HexToRGB(std::string hex, float opacity) const {

    std::regex pattern("#?([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})");

    std::smatch match;
    if (std::regex_match(hex, match, pattern))
    {
        SDL_Color color;

        color.r = std::stoi(match[1].str(), nullptr, 16);
        color.g = std::stoi(match[2].str(), nullptr, 16);
        color.b = std::stoi(match[3].str(), nullptr, 16);
        color.a = opacity;

        return color;
    }
    else
    {
       throw " is an invalid rgb color\n";
    }

}

void RenderingEngineAdapter::drawLine(const Vector2 &begin, const Vector2 &end, SDL_Renderer *renderer) const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLineF(renderer, begin.x, begin.y, end.x, end.y);
}

void RenderingEngineAdapter::drawCircle(const Vector2 &center, const float &radius, SDL_Renderer *renderer) const {
    float x = center.x;
    float y = center.y;
    float iRadius = radius;
    int num_segments = iRadius * iRadius;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    for(int ii = 0; ii < num_segments; ii++)
    {
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



Spritesheet *RenderingEngineAdapter::createSpriteSheet(const std::string &path, const std::string &jsonPath, std::string &spriteSheetId,
                                          SDL_Renderer *renderer) {
    return new Spritesheet(path, jsonPath, spriteSheetId, renderer);
}

void RenderingEngineAdapter::createText(const std::string &fontName, const std::string &text, const int fontSize, const std::string &hex, const std::string &textureId,  SDL_Renderer *renderer){
    TTF_Font* font = TTF_OpenFont(fontName.c_str(), fontSize);
    SDL_Surface* surfaceMessage = TTF_RenderUTF8_Blended(font, text.c_str(), HexToRGB(hex, 255));

    RenderingEngineAdapter::GetTextureManager()->CreateTexture(surfaceMessage, textureId, renderer);
    TTF_CloseFont(font);
}








