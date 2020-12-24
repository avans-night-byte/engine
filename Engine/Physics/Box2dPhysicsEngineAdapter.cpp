#include "b2_user_settings.h"
#include "Box2DPhysicsEngineAdapter.hpp"

#include <cmath>

unsigned int
Box2DPhysicsEngineAdapter::createBody(const Box2DBoxData &box2dBoxData) {
    BodyType bodyType = box2dBoxData.bodyType;
    Vector2 position = box2dBoxData.position;
    Vector2 size = box2dBoxData.size;

    b2BodyDef bodyDef;
    bodyDef.type = static_cast<b2BodyType>(static_cast<int>(bodyType));
    bodyDef.position.Set(position.x, position.y);
    bodyDef.linearDamping = 0.01f;
    bodyDef.angularDamping = 0.1f;
    bodyDef.bullet = box2dBoxData.isBullet;
    bodyDef.enabled = box2dBoxData.isEnabled;

    b2BodyUserData bodyUserData;
    bodyUserData.contactHandler = box2dBoxData.contactHandler;

    bodyDef.userData = bodyUserData;

    b2Body *body = world.CreateBody(&bodyDef);


    b2PolygonShape box;
    box.SetAsBox(size.x, size.y);

    b2FixtureDef fixtureDef;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.0f;
    fixtureDef.shape = &box;
    fixtureDef.isSensor = box2dBoxData.isSensor;

    body->CreateFixture(&fixtureDef);

    availableBodyId++;
    bodies[availableBodyId] = (body);
    return availableBodyId;
}


unsigned int Box2DPhysicsEngineAdapter::createBody(const Box2DCircleData &box2DCircleData) {
    BodyType bodyType = box2DCircleData.bodyType;
    float radius = box2DCircleData.radius;
    Vector2 position = box2DCircleData.position;

    b2BodyDef bodyDef;
    bodyDef.type = static_cast<b2BodyType>(static_cast<int>(bodyType));
    bodyDef.position.Set(position.x, position.y);
    bodyDef.linearDamping = 1.1f;
    bodyDef.angularDamping = 0.1f;
    bodyDef.bullet = box2DCircleData.isBullet;
    bodyDef.enabled = box2DCircleData.isEnabled;

    b2BodyUserData bodyUserData;
    bodyUserData.contactHandler = box2DCircleData.contactHandler;

    bodyDef.userData = bodyUserData;

    b2Body *body = world.CreateBody(&bodyDef);
    b2CircleShape circle;
    circle.m_radius = radius;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circle;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 1.0f;
    body->CreateFixture(&fixtureDef);

    availableBodyId++;
    bodies[availableBodyId] = (body);
    return availableBodyId;
}

void Box2DPhysicsEngineAdapter::addFixtureToBody(BodyId id, const Box2DBoxData &box2dBoxData) {
    Vector2 size = box2dBoxData.size;
    b2Vec2 center = b2Vec2(box2dBoxData.offset.x, box2dBoxData.offset.y);
    b2PolygonShape box;
    box.SetAsBox(size.x, size.y, center, 0);

    b2FixtureDef fixtureDef;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.0f;
    fixtureDef.shape = &box;
    fixtureDef.isSensor = box2dBoxData.isSensor;

    b2Body *body = this->bodies[id];
    body->CreateFixture(&fixtureDef);
}

BodyId Box2DPhysicsEngineAdapter::createBody(const Box2DPolygonData &box2DPolygonData) {
    BodyType bodyType = box2DPolygonData.bodyType;
    Vector2 position = box2DPolygonData.position;
    const std::vector<Vector2> &points = box2DPolygonData.points;

    b2BodyDef bodyDef;
    bodyDef.type = static_cast<b2BodyType>(static_cast<int>(bodyType));
    bodyDef.position.Set(position.x, position.y);
    bodyDef.bullet = box2DPolygonData.isBullet;
    bodyDef.enabled = box2DPolygonData.isEnabled;

    b2BodyUserData bodyUserData;
    bodyUserData.contactHandler = box2DPolygonData.contactHandler;

    bodyDef.userData = bodyUserData;

    b2Body *body = world.CreateBody(&bodyDef);
    b2PolygonShape polygonShape;


    std::vector<b2Vec2> vertices;
    for (auto it = std::begin(points); it != std::end(points); ++it) {
        vertices.emplace_back(it->x, it->y);
    }


    b2PolygonShape polygon;
    b2Vec2 arrayVec[vertices.size()];
    std::copy(vertices.begin(), vertices.end(), arrayVec);
    polygonShape.Set(arrayVec, vertices.size());

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &polygonShape;
    fixtureDef.isSensor = box2DPolygonData.isSensor;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 1.0f;
    body->CreateFixture(&fixtureDef);

    availableBodyId++;
    bodies[availableBodyId] = (body);
    return availableBodyId;
}


void Box2DPhysicsEngineAdapter::referencePositionToBody(BodyId bodyId, float &x, float &y) {
    b2Body *body = bodies[bodyId];
    x = body->GetPosition().x;
    y = body->GetPosition().y;
}

inline RTransform Box2DPhysicsEngineAdapter::getRPosition(BodyId bodyId) {
    b2Body *body = bodies[bodyId];

    return RTransform(body->GetPosition().x, body->GetPosition().y, (body->GetAngle() * 180.f / M_PI));
}

void Box2DPhysicsEngineAdapter::debugDraw(const EngineRenderingAdapter &renderingAdapter) {
    if (drawDebug == nullptr) {
        drawDebug = std::make_unique<Box2dDrawDebug>(renderingAdapter);

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

void Box2DPhysicsEngineAdapter::update(float timeStep) {
    world.Step(timeStep, _velocityIterations, _positionIterations);
}

void Box2DPhysicsEngineAdapter::setLinearVelocity(const BodyId bodyId, const Vector2 &vector2) {
    b2Vec2 vel = b2Vec2(vector2.x, vector2.y);

    bodies[bodyId]->SetLinearVelocity(vel);
}

void Box2DPhysicsEngineAdapter::getVelocity(Vector2 &velocity, BodyId bodyId) const {
    b2Vec2 b2Vec2 = bodies.find(bodyId)->second->GetLinearVelocity();
    velocity = Vector2(b2Vec2.x, b2Vec2.y);
}

void Box2DPhysicsEngineAdapter::setFixedRotation(const BodyId bodyId, bool b) {
    b2Body *body = bodies[bodyId];
    body->SetFixedRotation(b);
}

void Box2DPhysicsEngineAdapter::destroyBody(BodyId bodyID) {
    auto *body = bodies[bodyID];

    world.DestroyBody(body);
    bodies.erase(bodyID);
}


void Box2DPhysicsEngineAdapter::setAngle(BodyId bodyId, float angle) const {
    b2Body *body = bodies.find(bodyId)->second;

    body->SetTransform(body->GetPosition(), angle);
}

bool Box2DPhysicsEngineAdapter::isWorldLocked() const {
    return world.IsLocked();
}

void Box2DPhysicsEngineAdapter::setTransform(unsigned int bodyId, Vector2 pos, float angle) const {
    b2Body *body = bodies.find(bodyId)->second;
    b2Vec2 p = b2Vec2(pos.x, pos.y);

    body->SetTransform(p, angle);
}

void Box2DPhysicsEngineAdapter::addForce(const BodyId i, const Vector2 &position, Vector2 force) const {
    b2Body *body = bodies.find(i)->second;
    b2Vec2 f = b2Vec2(force.x, force.y);
    b2Vec2 p = b2Vec2(position.x, position.y);

    body->ApplyLinearImpulseToCenter(f, true);
}

void Box2DPhysicsEngineAdapter::setEnabled(BodyId id, bool b) const {
    b2Body *body = bodies.find(id)->second;

    body->SetEnabled(b);
}


const b2World& Box2DPhysicsEngineAdapter::getWorld() const{
    return world;
}
