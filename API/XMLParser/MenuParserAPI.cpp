#include "MenuParserAPI.hpp"


MenuParserAPI::MenuParserAPI(EngineRenderingAPI &renderer){
    menuParser = std::make_unique<MenuParser>(renderer);
}

void MenuParserAPI::loadScene(std::string path) {
    return menuParser->openScene(path);
}

void MenuParserAPI::render() {
    menuParser->render();
}
