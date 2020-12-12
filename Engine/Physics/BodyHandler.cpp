#include "BodyHandler.hpp"
#include "PhysicsEngineAdapter.hpp"

void BodyHandler::update() {
    if (_physicsAdapter.isWorldLocked() || (onWorldLocked.empty() && onBodiesHandled.empty()))
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
