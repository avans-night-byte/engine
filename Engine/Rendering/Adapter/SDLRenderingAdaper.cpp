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

void RenderingEngineAdapter::drawRectangle(Vector2 &position, float width, float height, SDL_Renderer &renderer) {
    SDL_SetRenderDrawColor(&renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_Rect rectangle;

    rectangle.x = position.x;
    rectangle.y = position.y;
    rectangle.w = width;
    rectangle.h = height;

    SDL_RenderFillRect(&renderer, &rectangle);
}

void RenderingEngineAdapter::drawLine(const Vector2 &begin, const Vector2 &end, SDL_Renderer *renderer) const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLineF(renderer, begin.x, begin.y, end.x, end.y);
}

//void RenderingEngineAdapter::drawSolidRectangle(const Vector2 &position,
//                                                const Vector2 &size,
//                                                SDL_Renderer *renderer) const {
//    float x = position.x;
//    float y = position.y;
//
//    SDL_FRect rect;
//    rect.x = x;
//    rect.y = y;
//    rect.w = size.x;
//    rect.h = size.y;
//
//    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 200);
//    SDL_RenderFillRectF(renderer, &rect);
//    SDL_RenderDrawRectF(renderer, &rect);
//
//    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//}

void RenderingEngineAdapter::drawCircle(const Vector2 &center, const float &radius, SDL_Renderer *renderer) const {
    float x = center.x;
    float y = center.y;
    float iRadius = radius;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    for (float w = 0; w < iRadius * 2; w++) {
        for (float h = 0; h < iRadius * 2; h++) {
            float dx = iRadius - w; // horizontal offset
            float dy = iRadius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (iRadius * iRadius)) {
                SDL_RenderDrawPointF(renderer, x + dx, y + dy);
            }
        }
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPointF(renderer, x, y);
    SDL_RenderDrawPointF(renderer, x + 1, y);
    SDL_RenderDrawPointF(renderer, x - 1, y);
    SDL_RenderDrawPointF(renderer, x, y + 1);
    SDL_RenderDrawPointF(renderer, x, y - 1);
}






