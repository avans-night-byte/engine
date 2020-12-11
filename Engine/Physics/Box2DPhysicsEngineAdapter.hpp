#pragma once

#include <vector>
#include <memory>
#include "box2d.h"

#include "PhysicsEngineAdapter.hpp"
#include "PhysicsDebug//Box2dDrawDebug.hpp"
#include "ContactListener.hpp"

using namespace std;

class Box2DPhysicsEngineAdapter : public PhysicsEngineAdapter {

private:
    b2World world = b2World(b2Vec2_zero);
    unique_ptr<ContactListener> contactListener;
    map<BodyId, b2Body *> bodies{};
    vector<b2Body *> bodiesToDestroy = {};

    unique_ptr<Box2dDrawDebug> drawDebug = nullptr;

public:
    Box2DPhysicsEngineAdapter(){
        contactListener = make_unique<ContactListener>();
        world.SetContactListener(&(*contactListener));
    }

    ~Box2DPhysicsEngineAdapter() override {
        for (auto &body : bodies) {
            world.DestroyBody(body.second);
        }

        bodies.clear();
    }

public:
    void update(const float &timeStep, const int32 &velocityIterations, const int32 &positionIterations) override;

    BodyId createBody(BodyType bodyType, Vector2 position, Vector2 size, const bool &isSensor = false, ContactHandler* userData = nullptr) override;

    BodyId createBody(BodyType bodyType, Vector2 position, float radius, ContactHandler* userData = nullptr) override;

    BodyId createBody(BodyType bodyType, Vector2 position, const std::vector<Vector2> &points, const bool &isSensor, ContactHandler* userData = nullptr) override;

    void referencePositionToBody(BodyId bodyId, float &x, float &y) override;

    inline RPosition getRPosition(BodyId bodyId) override;

    inline void destroyBody(BodyId bodyID) override;

    void DebugDraw(const RenderingEngineAdapter &renderingAdapter, SDL_Renderer &renderer) override;

    void getVelocity(Vector2 &velocity, BodyId bodyId) const override;

    void setLinearVelocity(BodyId bodyId, const Vector2 &vector2) override;

    void setFixedRotation(BodyId bodyId, bool b) override;


    void setAngle(BodyId bodyId, float angle) const override;

    void sweepBodies() override;

    bool bodiesAreDestroyed() override;
};