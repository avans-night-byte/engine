#include "Box2DPhysicsEngineAdapter.hpp"

unsigned int Box2DPhysicsEngineAdapter::createBody(BodyType bodyType, Vector2 position, Vector2 size) {
    b2BodyDef bodyDef;
    bodyDef.type = static_cast<b2BodyType>(static_cast<int>(bodyType));

    bodyDef.position.Set(position.x, position.y);

    b2Body *body = world.CreateBody(&bodyDef);
    b2PolygonShape box;
    box.SetAsBox(size.x, size.y);

    body->CreateFixture(&box, 0.0f);

    bodies.push_back(body);
    return bodies.size() - 1;
}

unsigned int Box2DPhysicsEngineAdapter::createBody(BodyType bodyType, Vector2 position, float radius) {
    b2BodyDef bodyDef;
    bodyDef.type = static_cast<b2BodyType>(static_cast<int>(bodyType));
    bodyDef.position.Set(position.x, position.y);

    b2Body *body = world.CreateBody(&bodyDef);
    b2CircleShape circle;
    circle.m_radius = radius;

    body->CreateFixture(&circle, 0.0f);


    bodies.push_back(body);
    return bodies.size() - 1;
}

void Box2DPhysicsEngineAdapter::referencePositionToBody(BodyId bodyId, float &x, float &y) {
    b2Body *body = bodies[bodyId];
    x = body->GetPosition().x;
    y = body->GetPosition().y;
}

inline RPosition Box2DPhysicsEngineAdapter::getRPosition(BodyId bodyId) {
    b2Body *body = bodies[bodyId];
    return RPosition(body->GetPosition().x, body->GetPosition().y);
}

void Box2DPhysicsEngineAdapter::DebugDraw(const RenderingEngineAdapter& renderingAdapter, SDL_Renderer &renderer) {
    if(drawDebug == nullptr)
    {
        drawDebug = make_unique<Box2dDrawDebug>(renderingAdapter, renderer);

        world.SetDebugDraw(drawDebug.get());

        uint32 flags = 0;
        flags += b2Draw::e_shapeBit;
        flags += b2Draw::e_jointBit;
        flags += b2Draw::e_centerOfMassBit;
        flags += b2Draw::e_aabbBit;
        flags += b2Draw::e_pairBit;
        drawDebug->SetFlags(flags);
    }

    world.DebugDraw();
}

void Box2DPhysicsEngineAdapter::update(const float &timeStep, const int32 &velocityIterations,
                                       const int32 &positionIterations) {
    world.Step(timeStep, velocityIterations, positionIterations);
}
