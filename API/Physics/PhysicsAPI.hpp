#pragma once

#include "../../Engine/Physics/PhysicsEngineAdapter.hpp"

#include "memory"
#include <b2_types.h>
#include "../../Engine/Physics/ContactHandler.hpp"

class PhysicsEngineAdapter;

class RenderingAPI;

class SDL_Renderer;

typedef unsigned int BodyId;
class Box2DBoxData;
class Box2DCircleData;
class Box2DPolygonData;

struct RTransform;

class Vector2;

class PhysicsAPI {
public:
    virtual void update(float deltaTime) = 0;

    virtual BodyId createBody(const Box2DBoxData &box2DBoxData) const = 0;

    virtual BodyId createBody(const Box2DCircleData &box2DCircleData) const = 0;

    virtual BodyId createBody(const Box2DPolygonData &box2DPolygonData) const = 0;

    virtual void destroyBody(BodyId bodyId) = 0;

    virtual RTransform getRPosition(BodyId bodyId) const = 0;

    virtual void debugDraw(RenderingAPI &renderingApi) = 0;

    virtual void GetVelocity(Vector2 &velocity, const BodyId bodyId) const = 0;

    virtual void setLinearVelocity(const BodyId bodyId, const Vector2 &vector2) const = 0;

    virtual void setFixedRotation(const BodyId i, bool b) const = 0;

    virtual void addForce(const BodyId i, const Vector2 &position, Vector2) const = 0;

    virtual void setAngle(const BodyId i, float rotation) const = 0;

    virtual void destroyBody(BodyId i) const = 0;

    virtual PhysicsEngineAdapter &getPhysicsEngineAdapter() const = 0;

    virtual void setTransform(unsigned int bodyId, Vector2 pos, float angle) const = 0;

    virtual void addFixture(unsigned int bodyId, const Box2DBoxData &box2DBoxData) const = 0;

    virtual void setEnabled(BodyId id, bool b) const = 0;
};