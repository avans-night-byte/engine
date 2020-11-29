#pragma once

#include "./PhysicsAPI.hpp"
#include "../../Engine/Physics/PhysicsEngineAdapter.hpp"
#include "../../Engine/Physics/Box2DPhysicsEngineAdapter.hpp"
#include "../Rendering/EngineRenderingAPI.hpp"

class EnginePhysicsAPI : public PhysicsAPI {
private:
    unique_ptr<PhysicsEngineAdapter> physicsEngineAdapter;

public:
    EnginePhysicsAPI() {
        physicsEngineAdapter = make_unique<Box2DPhysicsEngineAdapter>();
    }

    void update(const float &timeStep, const int32 &velocityIterations, const int32 &positionIterations) override {
        physicsEngineAdapter->update(timeStep, velocityIterations, positionIterations);
    }

    // TODO: Create a Helper function for BodyId
    inline BodyId createStaticBody(BodyType bodyType, Vector2 position, Vector2 size) const override {
        return physicsEngineAdapter->createBody(bodyType, position, size);
    }

    inline BodyId createStaticBody(BodyType bodyType, Vector2 position, std::vector<Vector2> &points) const override {
        return physicsEngineAdapter->createBody(bodyType, position, points);
    }

    inline BodyId createStaticBody(BodyType bodyType, Vector2 position, float radius) const override {
        return physicsEngineAdapter->createBody(bodyType, position, radius);
    }

    inline void destroyBody(BodyId bodyID) override {
        physicsEngineAdapter->destroyBody(bodyID);
    }

    RPosition getRPosition(BodyId bodyId) const override {
        return physicsEngineAdapter->getRPosition(bodyId);
    }

    void DebugDraw(const RenderingAPI &renderingApi, SDL_Renderer& renderer) override {
        physicsEngineAdapter->DebugDraw(renderingApi.GetRendererAdapter(), renderer);
    }

    void GetVelocity(Vector2 &velocity, const BodyId bodyId) const override {
        physicsEngineAdapter->getVelocity(velocity, bodyId);
    }

    void setLinearVelocity(const BodyId bodyId, const Vector2 &vector2) const override {
        physicsEngineAdapter->setLinearVelocity(bodyId, vector2);
    }

    void setFixedRotation(const BodyId i, bool b) const override {
        physicsEngineAdapter->setFixedRotation(i, b);
    }
};
