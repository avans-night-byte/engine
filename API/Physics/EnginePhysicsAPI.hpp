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

    inline BodyId createStaticBody(BodyType bodyType, Vector2 position, float radius) const override {
        return physicsEngineAdapter->createBody(bodyType, position, radius);
    }

    inline void destroyBody(BodyId bodyID) override {
        physicsEngineAdapter->destroyBody(bodyID);
    }

    RPosition getRPosition(BodyId bodyId) override {
        return physicsEngineAdapter->getRPosition(bodyId);
    }

    void DebugDraw(const RenderingAPI &renderingApi, SDL_Renderer& renderer) override {
        physicsEngineAdapter->DebugDraw(renderingApi.GetRendererAdapter(), renderer);
    }
};
