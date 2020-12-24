#pragma once

#include <deque>
#include <functional>


class PhysicsEngineAdapter;

class BodyHandler {
private:
    const PhysicsEngineAdapter &_physicsAdapter;

    std::deque<std::function<void()>> onWorldLocked;
    std::vector<std::function<void()>> onBodiesHandled;

public:
    explicit BodyHandler(const PhysicsEngineAdapter &physicsApi) : _physicsAdapter(physicsApi) {

    }

    void update();

    inline void eventOnWorldLocked(const std::function<void()> &fun) {
        onWorldLocked.push_back(fun);
    }

    inline void eventOnBodiesHandles(const std::function<void()> &fun) {
        onBodiesHandled.push_back(fun);
    }
};
