#include <string>
#include "MenuParser.hpp"
#include "Page.hpp"

void MenuParser::openScene(const std::string& path) {
    _menu = menu_(path);

    _textItems = std::map<std::string, std::unique_ptr<TextWrapper>>();
    std::string buttonString = "button_";

    int index = 0;
    for(auto button : _menu->buttons().button()){
        auto createdString = buttonString.append(std::to_string(index));
        auto wrapper = TextWrapper::createText(_renderer, button.content().c_str(), "../../Resources/Fonts/LiberationMono-Regular.ttf", 32, SDL_Color {255, 255, 255}, createdString);

        _textItems[createdString] = std::unique_ptr<TextWrapper>(wrapper);
        index++;
    }
}

void MenuParser::render() {
    if(_menu == nullptr) return;

    std::string buttonString = "button_";
    int index = 0;

    for(auto button : _menu->buttons().button()){
        Vector2 v2(button.position().x(), button.position().y());

        if(button.color().present()){
            _renderer.drawRectangle(v2, button.size().width(), button.size().height(), button.color()->hex(), button.color()->alpha());
            auto id = buttonString.append(std::to_string(index));
            auto textWrapper = (&_textItems[id])->get();

            textWrapper->render(button.position().x() + ((button.size().width() / 2) - textWrapper->getSize().x / 2),button.position().y() + ((button.size().height() / 2) - textWrapper->getSize().y / 2));
        } else {
            //TODO: draw rectangle with resource image
            //_renderer.drawRectangle(v2, button.size().width(), button.size().height(), button.color()->hex(), button.color()->alpha());
        }

        if(button.events().onClick().present()){

        }

        index++;
    }

}

MenuParser::MenuParser(const EngineRenderingAPI &renderer) : _renderer(renderer) {}

void MenuParser::onClick(Input input) {
    std::cout << input.x << std::endl;
}


