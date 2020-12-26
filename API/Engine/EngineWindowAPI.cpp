#include "./EngineWindowAPI.hpp"

EngineWindowAPI::EngineWindowAPI() : _engine(*Engine::getInstance()) {}

void EngineWindowAPI::initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT) const {
    return _engine.initWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void EngineWindowAPI::closeWindow() const {
    return _engine.closeWindow();
}

void EngineWindowAPI::renderImGui(bool &cheatMode) const {
    Engine::renderImGui(cheatMode);
}
