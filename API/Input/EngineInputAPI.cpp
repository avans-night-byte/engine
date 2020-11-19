#include "./EngineInputAPI.hpp"

EngineInputAPI::EngineInputAPI() : _adapter {} {
    _adapter = new SDLInputEngineAdapter;
}

Input EngineInputAPI::getInput() const {
    return _adapter->getInput();
}
EngineInputAPI::~EngineInputAPI() {
    delete _adapter;
}
