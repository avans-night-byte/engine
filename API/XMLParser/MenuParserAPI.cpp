#include "MenuParserAPI.hpp"
#include "../Rendering/RenderingAPI.hpp"

MenuParserAPI::MenuParserAPI(RenderingAPI &renderer, Event<Input>& event){
    menuParser = std::make_unique<MenuParser>(renderer);
    event += std::bind(&MenuParserAPI::onClick, this, std::placeholders::_1);
}

void MenuParserAPI::loadScene(std::string path) {
    return menuParser->initialize(path);
}

void MenuParserAPI::render() {
    menuParser->render();
}

void MenuParserAPI::onClick(Input input) {
    menuParser->onClick(input);
}
