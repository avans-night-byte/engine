#pragma once

#include "../../API//Helpers/Vector2.hpp"
#include "../../API/RTransform.hpp"
#include "../../API/Physics/PhysicsAPI.hpp"

#include "BodyType.hpp"
#include "../Rendering/Adapter/SDLRenderingAdapter.hpp"
#include "ContactHandler.hpp"

#include <vector>


typedef signed int int32;
typedef unsigned int BodyId;


struct Box2DData {
    BodyType bodyType;
    Vector2 position;
    bool isBullet = false;
    bool isSensor = false;
    ContactHandler* userData = nullptr;
};

struct Box2DBoxData : public Box2DData
{
    Box2DBoxData() {

    }

    Vector2 size;
};

struct Box2DCircleData : public Box2DData
{
    Box2DCircleData() {

    }

    float radius;
};

struct Box2DPolygonData : public Box2DData
{
    Box2DPolygonData() {

    }

    std::vector<Vector2> points;
};

class PhysicsEngineAdapter {
public:
    PhysicsEngineAdapter() = default;

    virtual ~PhysicsEngineAdapter() = default;

public:
    virtual void update(float timeStep) = 0;

    virtual BodyId createBody(const Box2DBoxData& box2dBoxData) = 0;

    virtual BodyId createBody(const Box2DCircleData &box2DCircleData) = 0;

    virtual BodyId createBody(const Box2DPolygonData &box2DPolygonData) = 0;

    virtual void referencePositionToBody(BodyId bodyId, float &x, float &y) = 0;

    virtual RTransform getRPosition(BodyId bodyId) = 0;

    virtual void destroyBody(BodyId BodyID) = 0;

    virtual void DebugDraw(const SDLRenderingAdapter &renderingAdapter, SDL_Renderer &renderer) = 0;

    virtual void getVelocity(Vector2 &velocity, BodyId bodyId) const = 0;

    virtual void addForce(const BodyId i, Vector2 direction) const = 0;

    virtual void setLinearVelocity(const BodyId bodyId, const Vector2 &vector2) = 0;

    virtual void setTransform(unsigned int bodyId, Vector2 pos, float angle) const = 0;

    virtual void setFixedRotation(const BodyId bodyId, bool b) = 0;

    virtual void setAngle(BodyId bodyId, float angle) const = 0;

    virtual bool isWorldLocked() const = 0;
};