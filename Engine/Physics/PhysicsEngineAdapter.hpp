#pragma once

#include "../Vector2.hpp"
#include "BodyType.hpp"
#include "../../API/Physics/PhysicsAPI.hpp"
#include "../Rendering/Adapter/RenderingEngineAdapter.hpp"


typedef signed int int32;
typedef unsigned int BodyId;
struct RPosition;

class PhysicsEngineAdapter {
public:
    PhysicsEngineAdapter() = default;

    virtual ~PhysicsEngineAdapter() = default;

public:
    virtual void update(const float &timeStep, const int32 &velocityIterations, const int32 &positionIterations) = 0;

    virtual BodyId createBody(BodyType bodyType, Vector2 position, Vector2 size) = 0;

    virtual BodyId createBody(BodyType bodyType, Vector2 position, float radius) = 0;

    virtual void referencePositionToBody(BodyId bodyId, float &x, float &y) = 0;

    virtual RPosition getRPosition(BodyId bodyId) = 0;

    virtual void destroyBody(BodyId BodyID) = 0;

    virtual void DebugDraw(const RenderingEngineAdapter &renderingAdapter, SDL_Renderer &renderer) = 0;

    virtual void getVelocity(Vector2 &velocity, BodyId bodyId) const = 0;

    virtual void setLinearVelocity(const BodyId bodyId, const Vector2 &vector2) = 0;

    virtual void setFixedRotation(const BodyId bodyId, bool b) = 0;
};