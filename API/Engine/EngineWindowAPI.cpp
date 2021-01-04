#include "./EngineWindowAPI.hpp"

/**
 * This class is responsible for managing the windows of the Game and the library used for our cheat menu: ImgUI.
 */
EngineWindowAPI::EngineWindowAPI() : _engine(*Engine::getInstance()) {}


/**
 * Initialize a SDL window with the specified width and height in pixels.
 * @param SCREEN_WIDTH
 * @param SCREEN_HEIGHT
 */
void EngineWindowAPI::initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT) const {
    return _engine.initWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
}

/**
 * Closes the Game window.
 */
void EngineWindowAPI::closeWindow() const {
    return _engine.closeWindow();
}

/**
 * Renders the imgUi cheat menu on top of the game and pauses the game loop.
 * @param cheatMode
 */
void EngineWindowAPI::renderCheatMenu(bool &cheatMode) const {
    Engine::renderImGui(cheatMode);
}

/**
 * Clears the imgUi screen.
 */
void EngineWindowAPI::clearCheatMenu() const {
    Engine::clearImGui();
}



/**
 * Render a imgUI Checkbox.
 * @param label
 * @param value
 * @return
 */
bool EngineWindowAPI::showCheckBox(const std::string &label, bool *value) const {
    return Engine::ShowCheckBox(label, value);
}


/**
 * Render a imgUI float input.
 * @param label
 * @param value
 * @return
 */
bool EngineWindowAPI::showInputFloat(const std::string &label, float *value) const {
    return Engine::InputFloat(label, value);
}

/**
 * Render a imgUI float input.
 * @param label
 * @param value
 * @return
 */
bool EngineWindowAPI::showInputInt(const std::string &label, int *value) const {
    return Engine::InputInt(label, value);
}


/**
 * Render a imgUi text input.
 * @param label
 * @param value
 * @return
 */
bool EngineWindowAPI::showInputText(const std::string &label, char *value, int bufferSize) const {
    return Engine::InputText(label, value, bufferSize);
}


/**
 * Render a imgUi button.
 * @param label
 * @return
 */
bool EngineWindowAPI::button(const std::string &label) const {
    return Engine::Button(label);
}
