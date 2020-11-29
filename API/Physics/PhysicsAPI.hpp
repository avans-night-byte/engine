#pragma once


#include "../../Engine/Physics/BodyType.hpp"
#include "../../Engine/Vector2.hpp"
#include "../../Engine/Physics/PhysicsEngineAdapter.hpp"
#include "../Rendering/RenderingAPI.hpp"
#include "../RPosition.hpp"
#include "../../Engine/Physics/ContactHandler.hpp"


typedef unsigned int BodyId;

class PhysicsAPI {
public:
    virtual void update(const float& timeStep, const int32& velocityIterations, const int32& positionIterations) = 0;

    virtual unsigned int createStaticBody(BodyType bodyType, Vector2 position, Vector2 size, const bool &isSensor = false, ContactHandler* userData = nullptr) const = 0;

    virtual unsigned int createStaticBody(BodyType bodyType, Vector2 position, float radius, const bool &isSensor = false, ContactHandler* userData = nullptr) const = 0;

    virtual unsigned int
    createStaticBody(BodyType bodyType, Vector2 position, std::vector<Vector2> &points, const bool &isSensor = false, ContactHandler* userData = nullptr) const = 0;

    virtual void destroyBody(BodyId bodyId) = 0;

    virtual RPosition getRPosition(BodyId bodyId) const = 0;

    virtual void DebugDraw(const RenderingAPI &renderingApi, SDL_Renderer& renderer) = 0;

    virtual void GetVelocity(Vector2 &velocity, const BodyId bodyId) const = 0;

    virtual void setLinearVelocity(const BodyId bodyId, const Vector2 &vector2) const = 0;

    virtual void setFixedRotation(const BodyId i, bool b) const = 0;
};