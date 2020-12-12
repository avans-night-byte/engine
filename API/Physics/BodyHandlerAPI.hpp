#pragma once

#include "PhysicsAPI.hpp"
#include "../../Engine/Physics/BodyHandler.hpp"

#include <memory>


class BodyHandlerAPI {
private:
    std::unique_ptr<BodyHandler> _bodyHandler;

public:
    BodyHandlerAPI(const PhysicsAPI &physicsApi) {
        _bodyHandler = std::make_unique<BodyHandler>(physicsApi.getPhysicsEngineAdapter());
    }

    inline void update() {
        _bodyHandler->update();
    }

    inline void eventOnWorldLocked(const std::function<void()> &fun) {
        _bodyHandler->eventOnWorldLocked(fun);
    }

    inline void eventOnBodiesHandled(const std::function<void()> &fun) {
        _bodyHandler->eventOnBodiesHandles(fun);
    }
};