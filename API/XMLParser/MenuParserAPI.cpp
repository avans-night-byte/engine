#include "MenuParserAPI.hpp"
#include "../Rendering/RenderingAPI.hpp"


/**
 * Creates a MenuParser and registers click events.
 * @param renderer
 * @param event
 */
MenuParserAPI::MenuParserAPI(RenderingAPI &renderer, Event<Input>& event){
    menuParser = std::make_unique<MenuParser>(renderer);
    event += std::bind(&MenuParserAPI::onClick, this, std::placeholders::_1);
}


/**
 * Loads a menu scene from xml.
 * @param path
 */
void MenuParserAPI::loadScene(const std::string& path) {
    return menuParser->initialize(path);
}

/**
 * Renders the currently loaded scene.
 */
void MenuParserAPI::render() {
    menuParser->render();
}

/**
 * Handles click listeners for menu items.
 * @param input
 */
void MenuParserAPI::onClick(const Input& input) {
    menuParser->onClick(input);
}

/**
 * Returns a eventHandler with custom behaviour if defined by the user.
 * @return
 */
Event<std::string> &MenuParserAPI::getCustomEventHandler() {
    return menuParser->getCustomEventHandler();
}

void MenuParserAPI::setDynamicFieldValue(const std::string &field, const std::string &value) {
    menuParser->setDynamicFieldValue(field, value);
}

/**
 * @deprecated
 * @return
 */
std::map<std::string, std::string> MenuParserAPI::getDynamicFields() {
    return menuParser->getDynamicFields();
}
