#pragma once

#include "b2_user_settings.h" // must be declared before box2d
#include "box2d.h"

#include "PhysicsEngineAdapter.hpp"
#include "PhysicsDebug//Box2dDrawDebug.hpp"
#include "ContactListener.hpp"
#include "../../Engine/Managers/ResourceManager.hpp"

#include <vector>
#include <memory>
#include <chrono>

class Box2DPhysicsEngineAdapter : public PhysicsEngineAdapter {

private:
    b2World world = b2World(b2Vec2_zero);
    std::unique_ptr<ContactListener> contactListener;
    std::map<BodyId, b2Body *> bodies{};
    BodyId availableBodyId = 0;

    std::unique_ptr<Box2dDrawDebug> drawDebug = nullptr;

    int32 _velocityIterations = 6;
    int32 _positionIterations = 2;

public:
    Box2DPhysicsEngineAdapter(){
        contactListener = std::make_unique<ContactListener>();
        world.SetContactListener(&(*contactListener));
    }

    ~Box2DPhysicsEngineAdapter() override {
        for (auto &body : bodies) {
            world.DestroyBody(body.second);
        }

        bodies.clear();
    }

public:
    void update(float deltaTime) override;

    BodyId createBody(const Box2DBoxData& box2dBoxData) override;

    BodyId createBody(const Box2DCircleData &box2DCircleData) override;

    BodyId createBody(const Box2DPolygonData &box2DPolygonData) override;

    void referencePositionToBody(BodyId bodyId, float &x, float &y) override;

    inline RTransform getRPosition(BodyId bodyId) override;

    inline void destroyBody(BodyId bodyID) override;

    void debugDraw(const EngineRenderingAdapter &renderingAdapter) override;

    void getVelocity(Vector2 &velocity, BodyId bodyId) const override;

    void addForce(const BodyId i, const Vector2 &position, Vector2 force) const override;

    void setLinearVelocity(BodyId bodyId, const Vector2 &vector2) override;

    void setTransform(unsigned int bodyId, Vector2 pos, float angle) const override;

    void setFixedRotation(BodyId bodyId, bool b) override;

    void setAngle(BodyId bodyId, float angle) const override;

    void setEnabled(BodyId id, bool b) const override;

    [[nodiscard]] bool isWorldLocked() const override;
};