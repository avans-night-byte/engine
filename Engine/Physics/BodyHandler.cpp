#include "BodyHandler.hpp"
#include "PhysicsEngineAdapter.hpp"
void BodyHandler::update() {
    if (_physicsAdapter.isWorldLocked())
        return;

    for (auto &it : onWorldLocked) {
        it();
    }

    onWorldLocked.clear();

    for (auto &it : onBodiesHandled) {
        it();
    }

    onBodiesHandled.clear();
}
