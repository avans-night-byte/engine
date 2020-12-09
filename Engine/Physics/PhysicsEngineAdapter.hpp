#pragma once

#include "../Vector2.hpp"
#include "BodyType.hpp"
#include "../../API/Physics/PhysicsAPI.hpp"
#include "../Rendering/Adapter/RenderingEngineAdapter.hpp"
#include "ContactHandler.hpp"
#include "../../API/RPosition.hpp"
#include <vector>


typedef signed int int32;
typedef unsigned int BodyId;


struct Box2DData {
    BodyType bodyType;
    Vector2 position;
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
    virtual void update(const float &timeStep, const int32 &velocityIterations, const int32 &positionIterations) = 0;

    virtual BodyId createBody(BodyType bodyType, Vector2 position, Vector2 size, const bool &isSensor = false, ContactHandler* handler = nullptr) = 0;

    virtual BodyId createBody(BodyType bodyType, Vector2 position, float radius, ContactHandler* handler = nullptr) = 0;

    virtual BodyId createBody(BodyType bodyType, Vector2 position, const std::vector<Vector2> &points, const bool &isSensor, ContactHandler* handler = nullptr) = 0;

    virtual void referencePositionToBody(BodyId bodyId, float &x, float &y) = 0;

    virtual RPosition getRPosition(BodyId bodyId) = 0;

    virtual void destroyBody(BodyId BodyID) = 0;

    virtual void DebugDraw(const RenderingEngineAdapter &renderingAdapter, SDL_Renderer &renderer) = 0;

    virtual void getVelocity(Vector2 &velocity, BodyId bodyId) const = 0;

    virtual void setLinearVelocity(const BodyId bodyId, const Vector2 &vector2) = 0;

    virtual void setFixedRotation(const BodyId bodyId, bool b) = 0;

    virtual void setAngle(BodyId bodyId, float angle) const = 0;
};