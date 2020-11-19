#pragma once


#include "../../Engine/Physics/BodyType.hpp"
#include "../../Engine/Vector2.hpp"
#include "../../Engine/Physics/PhysicsEngineAdapter.hpp"
#include "../Rendering/RenderingAPI.hpp"
#include "../RPosition.hpp"


typedef unsigned int BodyId;

class PhysicsAPI {
public:
    virtual void update(const float& timeStep, const int32& velocityIterations, const int32& positionIterations) = 0;

    virtual unsigned int createStaticBody(BodyType bodyType, Vector2 position, Vector2 size) = 0;

    virtual unsigned int createStaticBody(BodyType bodyType, Vector2 position, float radius) = 0;

    virtual void destroyBody(BodyId bodyId) = 0;

    virtual RPosition getRPosition(BodyId bodyId) = 0;

    virtual void DebugDraw(const RenderingAPI &renderingApi, SDL_Renderer& renderer) = 0;
};