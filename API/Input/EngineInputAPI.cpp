#include "./EngineInputAPI.hpp"

Input EngineInputAPI::getInput(SDLInputEngineAdapter adapter) const {
    return adapter.getInput();
}

void EngineInputAPI::initializeControllers(
    SDLInputEngineAdapter adapter) const {
    adapter.initializeControllers();
}

void EngineInputAPI::closeController(SDLInputEngineAdapter adapter) const {
    adapter.closeController();
}
