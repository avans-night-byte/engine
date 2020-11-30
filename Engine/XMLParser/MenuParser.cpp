#include <string>
#include "MenuParser.hpp"
#include "Page.hpp"

void MenuParser::openScene(const std::string& path) {
    _menu = menu_(path);
}

void MenuParser::render() {
    if(_menu == nullptr) return;

    for(auto button : _menu->buttons().button()){
        Vector2 v2(button.position().x(), button.position().y());
        _renderer.drawRectangle(v2, button.size().width(), button.size().height(), button.color()->hex(), button.color()->alpha());
    }

}

MenuParser::MenuParser(const EngineRenderingAPI &renderer) : _renderer(renderer) {}


