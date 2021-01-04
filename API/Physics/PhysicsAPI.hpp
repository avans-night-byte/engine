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

class b2World;
/**
 * This class is a api to the PhysicsAdapter, which handles all our physics interaction using box2d.
 */
class PhysicsAPI {
public:
    /**
     * Update the physics for the specified physics engine.
     * @param deltaTime
     */
    virtual void update(float deltaTime) = 0;

    /**
     * Create a box physics body.
     * @param box2DBoxData
     * @return
     */
    virtual BodyId createBody(const Box2DBoxData &box2DBoxData) const = 0;

    /**
     * Create a circle physics body.
     * @param box2DCircleData
     * @return
     */
    virtual BodyId createBody(const Box2DCircleData &box2DCircleData) const = 0;

    /**
     * Create a polygon physics body.
     * @param box2DPolygonData
     * @return
     */
    virtual BodyId createBody(const Box2DPolygonData &box2DPolygonData) const = 0;

    /**
     * Destroy the body with the specified id.
     * @param bodyId
     */
    virtual void destroyBody(BodyId bodyId) = 0;

    /**
     * Get a reference position of the specified body.
     * @param bodyId
     * @return
     */
    virtual RTransform getRPosition(BodyId bodyId) const = 0;

    /**
     * Specify a rendering API to the physics api in order to debug physics bodies.
     * @param renderingApi
     */
    virtual void debugDraw(RenderingAPI &renderingApi) = 0;

    /**
     * Get the velocity of the specified object in the specified reference.
     * @param velocity
     * @param bodyId
     */
    virtual void GetVelocity(Vector2 &velocity, const BodyId bodyId) const = 0;

    /**
     * Set the body its velocity as a vector.
     * @param bodyId
     * @param vector2
     */
    virtual void setLinearVelocity(const BodyId bodyId, const Vector2 &vector2) const = 0;

    /**
     * Specify if rotation of the specified object should be locked.
     * @param i
     * @param b
     */
    virtual void setFixedRotation(const BodyId i, bool b) const = 0;

    /**
     * Add force as a impulse to the specified body.
     * @param i
     * @param position
     */
    virtual void addForce(const BodyId i, const Vector2 &position, Vector2) const = 0;


    /**
     * Set the angle of the specified body.
     * @param i
     * @param rotation
     */
    virtual void setAngle(const BodyId i, float rotation) const = 0;

    /**
     * Destroy the specified body.
     * @param i
     */
    virtual void destroyBody(BodyId i) const = 0;

    /**
     * Return the api its adapter.
     * @return
     */
    virtual PhysicsEngineAdapter &getPhysicsEngineAdapter() const = 0;

    /**
     * Set the rotation and position of the specified body.
     * @param bodyId
     * @param pos
     * @param angle
     */
    virtual void setTransform(unsigned int bodyId, Vector2 pos, float angle) const = 0;

    /**
     * Get the box2d world.
     * @return
     */
    virtual const b2World& getWorld() const = 0;

    /**
     * Add a fixture to a body, this allows bodies to use multiple colliders, triggers.
     * @param bodyId
     * @param box2DBoxData
     */
    virtual void addFixture(unsigned int bodyId, const Box2DBoxData &box2DBoxData) const = 0;

    /**
     * Enable or disable a body, useful for pooling objects.
     * @param id
     * @param b
     */
    virtual void setEnabled(BodyId id, bool b) const = 0;
};