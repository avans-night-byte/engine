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

/**
 * Returns the mouse position as a reference.
 * @param x
 * @param y
 */
void EngineInputAPI::getMousePosition(int &x, int &y) const {
    return _adapter->getMousePosition(x,y);
}

Event<Input>& EngineInputAPI::getInputEvent() {
    return _adapter->getInputEvent();
}




