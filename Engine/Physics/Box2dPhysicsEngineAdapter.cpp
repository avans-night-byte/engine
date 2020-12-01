#include "Box2DPhysicsEngineAdapter.hpp"

// TODO: Remove this shit
#include "../../Game/Components/NextLevelComponent.hpp"

unsigned int
Box2DPhysicsEngineAdapter::createBody(BodyType bodyType,
                                      Vector2 position,
                                      Vector2 size,
                                      const bool &isSensor,
                                      ContactHandler* userData) {
    b2BodyDef bodyDef;
    bodyDef.type = static_cast<b2BodyType>(static_cast<int>(bodyType));
    bodyDef.position.Set(position.x, position.y);
    bodyDef.linearDamping = 0.1f;
    bodyDef.angularDamping = 0.1f;

    b2BodyUserData bodyUserData;
    bodyUserData.pointer = (uintptr_t)userData;

    bodyDef.userData = bodyUserData;

    b2Body *body = world.CreateBody(&bodyDef);

    b2PolygonShape box;
    box.SetAsBox(size.x, size.y);

    b2FixtureDef fixtureDef;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.0f;
    fixtureDef.shape = &box;
    fixtureDef.isSensor = isSensor;

    body->CreateFixture(&fixtureDef);

    bodies.push_back(body);
    return bodies.size() - 1;
}

BodyId Box2DPhysicsEngineAdapter::createBody(BodyType bodyType,
                                             Vector2 position,
                                             const std::vector<Vector2> &points,
                                             const bool &isSensor,
                                             ContactHandler* userData) {
    b2BodyDef bodyDef;
    bodyDef.type = static_cast<b2BodyType>(static_cast<int>(bodyType));

    bodyDef.position.Set(position.x, position.y);

    b2Body *body = world.CreateBody(&bodyDef);
    b2PolygonShape polygonShape;


    std::vector<b2Vec2> verts;
    for(auto it = std::begin(points); it != std::end(points); ++it) {
        verts.emplace_back(it->x, it->y);
    }


    b2PolygonShape polygon;
    b2Vec2 arrayVec [verts.size()];
    std::copy(verts.begin(), verts.end(), arrayVec);
    polygonShape.Set(arrayVec, verts.size());

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &polygonShape;
    fixtureDef.isSensor = isSensor;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 1.0f;
    body->CreateFixture(&fixtureDef);

    bodies.push_back(body);
    return bodies.size() - 1;
}


unsigned int Box2DPhysicsEngineAdapter::createBody(BodyType bodyType,
                                                   Vector2 position,
                                                   float radius,
                                                   ContactHandler* userData) {
    b2BodyDef bodyDef;
    bodyDef.type = static_cast<b2BodyType>(static_cast<int>(bodyType));
    bodyDef.position.Set(position.x, position.y);
    bodyDef.linearDamping = 0.1f;
    bodyDef.angularDamping = 0.1f;
    b2Body *body = world.CreateBody(&bodyDef);
    b2CircleShape circle;
    circle.m_radius = radius;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circle;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 1.0f;
    body->CreateFixture(&fixtureDef);

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

void Box2DPhysicsEngineAdapter::setLinearVelocity(const BodyId bodyId, const Vector2 &vector2) {
    b2Vec2 vel = b2Vec2(vector2.x, vector2.y);

    bodies[bodyId]->SetLinearVelocity(vel);
}

void Box2DPhysicsEngineAdapter::getVelocity(Vector2 &velocity, BodyId bodyId) const {
    b2Vec2 b2Vec2 = bodies[bodyId]->GetLinearVelocity();
    velocity = Vector2(b2Vec2.x, b2Vec2.y);
}

void Box2DPhysicsEngineAdapter::setFixedRotation(const BodyId bodyId, bool b) {
    b2Body *body = bodies[bodyId];
    body->SetFixedRotation(b);
}