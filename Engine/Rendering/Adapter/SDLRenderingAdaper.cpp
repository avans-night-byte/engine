#include <iostream>
#include "RenderingEngineAdapter.hpp"

typedef signed int int32;

TextureManager *RenderingEngineAdapter::GetTextureManager() {
    return TextureManager::GetInstance();
}

void
RenderingEngineAdapter::drawTexture(std::string textureId, int x, int y, int width, int height, double scale, double r,
                                    SDL_Renderer *renderer, SDL_RendererFlip flip) {
    TextureManager *textureManager = TextureManager::GetInstance();
    return textureManager->draw(textureId, x, y, width, height, scale, r, renderer, flip);
}

Spritesheet *
RenderingEngineAdapter::createSpriteSheet(char const *path, std::string spriteSheetId, int rows, int columns, int width,
                                          int height, SDL_Renderer *renderer) {
    return new Spritesheet(path, spriteSheetId, rows, columns, width, height, renderer);
}

void RenderingEngineAdapter::drawRectangle(const Vector2 *vertices, int32 vertexCount, SDL_Renderer *renderer) const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_FPoint points[vertexCount + 1];
    for (int i = 0; i < vertexCount; ++i) {
        SDL_FPoint p = SDL_FPoint();
        p.x = vertices[i].x;
        p.y = vertices[i].y;

        points[i] = p;
    }

    Vector2 begin = Vector2(points[0].x, points[0].y);
    Vector2 end = Vector2(points[3].x, points[3].y);

    drawLine(begin, end, renderer);
    SDL_RenderDrawLinesF(renderer, points, vertexCount);
}

void RenderingEngineAdapter::drawLine(const Vector2 &begin, const Vector2 &end, SDL_Renderer *renderer) const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLineF(renderer, begin.x, begin.y, end.x, end.y);
}

void RenderingEngineAdapter::drawSolidRectangle(const Vector2 &position,
                                                const Vector2 &size,
                                                SDL_Renderer *renderer) const {
    float x = position.x;
    float y = position.y;

    SDL_FRect rect;
    rect.x = x;
    rect.y = y;
    rect.w = size.x;
    rect.h = size.y;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 200);
    SDL_RenderFillRectF(renderer, &rect);
    SDL_RenderDrawRectF(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}