#include <string>
#include "MenuParser.hpp"
#include "Page.hpp"


void MenuParser::openScene(const std::string& path) {
    _menu = menu_(path);

    int index = 0;
    for(auto button : _menu->buttons().button()){
        _renderer.createText("../../Resources/Fonts/LiberationMono-Regular.ttf", button.content().c_str(), 32, SDL_Color {255, 255, 255}, &"button_" [ index]);
        index++;
    }
}

void MenuParser::render() {
    if(_menu == nullptr) return;

    int index = 0;
    for(auto button : _menu->buttons().button()){
        Vector2 v2(button.position().x(), button.position().y());
        if(button.color().present()){
            _renderer.drawRectangle(v2, button.size().width(), button.size().height(), button.color()->hex(), button.color()->alpha());
            _renderer.drawTexture(&"button_" [ index], 0, 0, 0, 0, 1, 0);
        } else {
            //TODO: draw rectangle with resource image
            //_renderer.drawRectangle(v2, button.size().width(), button.size().height(), button.color()->hex(), button.color()->alpha());
        }
        index++;
    }

}

MenuParser::MenuParser(const EngineRenderingAPI &renderer) : _renderer(renderer) {}


