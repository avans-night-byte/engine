#include "./EngineWindowAPI.hpp"

EngineWindowAPI::EngineWindowAPI() : _engine(*Engine::getInstance()) {}

void EngineWindowAPI::initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT) const {
    return _engine.initWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void EngineWindowAPI::closeWindow() const {
    return _engine.closeWindow();
}

void EngineWindowAPI::renderCheatMenu(bool &cheatMode) const {
    Engine::renderImGui(cheatMode);
}

void EngineWindowAPI::clearCheatMenu() const {
    Engine::clearImGui();
}

bool EngineWindowAPI::showCheckBox(const std::string &label, bool *value) const {
    return Engine::ShowCheckBox(label, value);
}

bool EngineWindowAPI::showInputFloat(const std::string &label, float *value) const {
    return Engine::InputFloat(label, value);
}

bool EngineWindowAPI::showInputInt(const std::string &label, int *value) const {
    return Engine::InputInt(label, value);;
}
