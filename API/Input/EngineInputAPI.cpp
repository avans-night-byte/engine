#include "./EngineInputAPI.hpp"

EngineInputAPI::EngineInputAPI(InputEngineAdapter* adapter) : _adapter {adapter} {}
Input EngineInputAPI::getInput() const {
    return _adapter->getInput();
}
EngineInputAPI::~EngineInputAPI() {
    delete _adapter;
}
