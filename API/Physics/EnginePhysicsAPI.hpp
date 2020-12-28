#pragma once

#include "./PhysicsAPI.hpp"
#include "../../Engine/Physics/Box2DPhysicsEngineAdapter.hpp"
#include "../Rendering/EngineRenderingAPI.hpp"

class EnginePhysicsAPI : public PhysicsAPI {
private:
    const std::unique_ptr<PhysicsEngineAdapter> _physicsEngineAdapter;

public:
    EnginePhysicsAPI() : _physicsEngineAdapter(std::make_unique<Box2DPhysicsEngineAdapter>()) {
    }

    void update(float timeStep) override {
        _physicsEngineAdapter->update(timeStep);
    }


    // TODO: Create a Helper function for BodyId
    inline BodyId createBody(const Box2DBoxData &box2DBoxData) const override {
        return _physicsEngineAdapter->createBody(box2DBoxData);
    }

    inline BodyId createBody(const Box2DCircleData &box2DCircleData) const override {
        return _physicsEngineAdapter->createBody(box2DCircleData);
    }

    inline BodyId createBody(const Box2DPolygonData &box2DPolygonData) const override {
        return _physicsEngineAdapter->createBody(box2DPolygonData);
    }

    inline void destroyBody(BodyId bodyID) override {
        _physicsEngineAdapter->destroyBody(bodyID);
    }

    RTransform getRPosition(BodyId bodyId) const override {
        return _physicsEngineAdapter->getRPosition(bodyId);
    }

    void debugDraw(RenderingAPI &renderingApi) override {
        _physicsEngineAdapter->debugDraw(renderingApi.getRendererAdapter());
    }

    void GetVelocity(Vector2 &velocity, const BodyId bodyId) const override {
        _physicsEngineAdapter->getVelocity(velocity, bodyId);
    }

    void setLinearVelocity(const BodyId bodyId, const Vector2 &vector2) const override {
        _physicsEngineAdapter->setLinearVelocity(bodyId, vector2);
    }

    void setFixedRotation(const BodyId i, bool b) const override {
        _physicsEngineAdapter->setFixedRotation(i, b);
    }

    void addForce(const BodyId i, const Vector2 &position, Vector2 force) const override {
        _physicsEngineAdapter->addForce(i, position, force);
    }

    void setAngle(const BodyId i, float angle) const override {
        _physicsEngineAdapter->setAngle(i, angle);
    }

    void destroyBody(BodyId i) const override {
        _physicsEngineAdapter->destroyBody(i);
    }

    void setTransform(unsigned int bodyId, Vector2 pos, float angle) const override {
        _physicsEngineAdapter->setTransform(bodyId, pos, angle);
    }

    void addFixture(unsigned int bodyId, const Box2DBoxData &box2DBoxData) const override {
        _physicsEngineAdapter->addFixtureToBody(bodyId, box2DBoxData);
    }

    void setEnabled(BodyId id, bool b) const override {
        _physicsEngineAdapter->setEnabled(id, b);
    }

    inline PhysicsEngineAdapter &getPhysicsEngineAdapter() const override {
        return *_physicsEngineAdapter.get();
    }
};
