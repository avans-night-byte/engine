#pragma once

#include "b2_draw.h"
#include "../../Rendering/Adapter/RenderingEngineAdapter.hpp"

class Box2dDrawDebug : public b2Draw {
private:
    const RenderingEngineAdapter &renderingEngineAdapter;
    SDL_Renderer &renderer;

public:
    explicit Box2dDrawDebug(const RenderingEngineAdapter &adapter, SDL_Renderer &renderer) :
            renderingEngineAdapter(adapter), renderer(renderer) {

    }

    void DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) override {

    }

    void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) override {
        if(vertexCount <= 1)
            return;

        Vector2 vert[vertexCount];
        for (int i = 0; i < vertexCount; ++i) {
            vert[i] = Vector2(vertices[i].x, vertices[i].y);
        }

        renderingEngineAdapter.drawRectangle(vert, vertexCount, &renderer);
    }

    void DrawCircle(const b2Vec2 &center, float radius, const b2Color &color) override {

    }

    void DrawSolidCircle(const b2Vec2 &center, float radius, const b2Vec2 &axis, const b2Color &color) override {

    }

    void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) override {

    }

    void DrawTransform(const b2Transform &xf) override {

    }

    void DrawPoint(const b2Vec2 &p, float size, const b2Color &color) override {

    }
};