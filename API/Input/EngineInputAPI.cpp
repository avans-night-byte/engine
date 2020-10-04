#include "./EngineInputAPI.hpp"

Input EngineInputAPI::getInput(SDLInputEngineAdapter adapter) const {
    return adapter.getInput();
}
