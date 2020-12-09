#pragma once

#include "./PhysicsAPI.hpp"
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
    inline BodyId createBody(const Box2DBoxData &box2DBoxData) const override {
        return physicsEngineAdapter->createBody(box2DBoxData.bodyType,
                                                box2DBoxData.position,
                                                box2DBoxData.size,
                                                box2DBoxData.isSensor,
                                                box2DBoxData.userData);
    }

    inline BodyId createBody(const Box2DCircleData &box2DCircleData) const override {
        return physicsEngineAdapter->createBody(box2DCircleData.bodyType,
                                                box2DCircleData.position,
                                                box2DCircleData.radius,
                                                box2DCircleData.userData);
    }

    inline BodyId createBody(const Box2DPolygonData &box2DPolygonData) const override {
        return physicsEngineAdapter->createBody(box2DPolygonData.bodyType,
                                                box2DPolygonData.position,
                                                box2DPolygonData.points,
                                                box2DPolygonData.isSensor,
                                                box2DPolygonData.userData);
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

    void destroyBody(BodyId i) const override {
        physicsEngineAdapter->destroyBody(i);
    }

    inline unique_ptr<PhysicsEngineAdapter>& getPhysicsEngineAdapter() override
    {
        return physicsEngineAdapter;
    }
};
