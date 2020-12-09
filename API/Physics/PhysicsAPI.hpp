#pragma once

#include "../../Engine/Physics/PhysicsEngineAdapter.hpp"

#include "memory"
#include "b2_types.h"
#include "../../Engine/Physics/ContactHandler.hpp"

class PhysicsEngineAdapter;
class RenderingAPI;
class SDL_Renderer;

typedef unsigned int BodyId;
struct Box2DBoxData;
struct Box2DCircleData;
struct Box2DPolygonData;

struct RPosition;
class Vector2;

class PhysicsAPI {
public:
    virtual void update(const float& timeStep, const int32& velocityIterations, const int32& positionIterations) = 0;

    virtual BodyId createBody(const Box2DBoxData& box2DBoxData) const = 0;

    virtual BodyId createBody(const Box2DCircleData& box2DCircleData) const = 0;

    virtual BodyId createBody(const Box2DPolygonData& box2DPolygonData) const = 0;

    virtual void destroyBody(BodyId bodyId) = 0;

    virtual RPosition getRPosition(BodyId bodyId) const = 0;

    virtual void DebugDraw(const RenderingAPI &renderingApi, SDL_Renderer& renderer) = 0;

    virtual void GetVelocity(Vector2 &velocity, const BodyId bodyId) const = 0;

    virtual void setLinearVelocity(const BodyId bodyId, const Vector2 &vector2) const = 0;

    virtual void setFixedRotation(const BodyId i, bool b) const = 0;

    virtual void destroyBody(BodyId i) const = 0;

    virtual void setAngle(const BodyId bodyId, float angle) const = 0;

    virtual std::unique_ptr<PhysicsEngineAdapter>& getPhysicsEngineAdapter() = 0;
};
