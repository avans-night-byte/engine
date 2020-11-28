#pragma once

#include <vector>
#include <memory>
#include "box2d.h"

#include "PhysicsEngineAdapter.hpp"
#include "PhysicsDebug//Box2dDrawDebug.hpp"

using namespace std;

class Box2DPhysicsEngineAdapter : public PhysicsEngineAdapter {

private:
    b2World world = b2World(b2Vec2_zero);
    vector<b2Body *> bodies = vector<b2Body *>();

    unique_ptr<Box2dDrawDebug> drawDebug = nullptr;

public:
    Box2DPhysicsEngineAdapter() = default;

    ~Box2DPhysicsEngineAdapter() override {
        for (b2Body *body : bodies) {
            world.DestroyBody(body);
        }

        bodies.clear();
    }

public:
    void update(const float &timeStep, const int32 &velocityIterations, const int32 &positionIterations) override;

    BodyId createBody(BodyType bodyType, Vector2 position, Vector2 size) override;

    BodyId createBody(BodyType bodyType, Vector2 position, float radius) override;

    BodyId createBody(BodyType bodyType, Vector2 position, const std::vector<Vector2> &points) override;

    void referencePositionToBody(BodyId bodyId, float &x, float &y) override;

    inline RPosition getRPosition(BodyId bodyId) override;

    inline void destroyBody(BodyId bodyID) override {
        world.DestroyBody(bodies[bodyID]);
    }

    void DebugDraw(const RenderingEngineAdapter &renderingAdapter, SDL_Renderer &renderer) override;

    void getVelocity(Vector2 &velocity, BodyId bodyId) const override;

    void setLinearVelocity(BodyId bodyId, const Vector2 &vector2) override;

    void setFixedRotation(BodyId bodyId, bool b) override;
};