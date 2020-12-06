#include <string>
#include <regex>
#include "MenuParser.hpp"


MenuParser::MenuParser(const RenderingAPI &renderer) : _renderer(renderer) {}

void MenuParser::openScene(const std::string& path) {
    _menu = Menu::menu_(path);
    _textItems = std::map<std::string, std::unique_ptr<TextWrapper>>();

    if(_menu->buttons().present()){
        int index = 0;
        for(auto button : _menu->buttons()->button()){
            auto createdString = _buttonPrefix + std::to_string(index);
            auto wrapper = TextWrapper::createText(_renderer, button.content().c_str(), (_fontPath + "Montserrat-Bold.ttf").c_str(), 32, SDL_Color {255, 255, 255}, createdString);

            _textItems[createdString] = std::unique_ptr<TextWrapper>(wrapper);
            index++;
        }
    }

    int index = 0;
    for(auto text : _menu->texts().text()){

        auto createdString = _textPrefix + std::to_string(index);
        auto wrapper = TextWrapper::createText(_renderer, text.content().c_str(), (_fontPath + "Montserrat-Regular.ttf").c_str(), 32, HexToRGB(text.color().hex(), text.color().alpha()), createdString);

        _textItems[createdString] = std::unique_ptr<TextWrapper>(wrapper);
        index++;
    }

}

void MenuParser::render() {
    if(_menu == nullptr) return;

    _renderer.drawBackground(_menu->color()->hex(), _menu->color()->alpha());
    MenuParser::renderButtons();
    MenuParser::renderText();
}

void MenuParser::renderButtons(){

    int index = 0;
    if(!_menu->buttons().present()) return;

    for(auto button : _menu->buttons()->button()){
        Vector2 v2(button.position().x(), button.position().y());

        if(button.color().present()){
            _renderer.drawRectangle(v2, button.size().width(), button.size().height(), button.color()->hex(), button.color()->alpha());
            auto id = _buttonPrefix + std::to_string(index);
            auto textWrapper = (&_textItems[id])->get();

            textWrapper->render(button.position().x() + ((button.size().width() / 2) - textWrapper->getSize().x / 2),button.position().y() + ((button.size().height() / 2) - textWrapper->getSize().y / 2));
        } else {
            //TODO: draw rectangle with resource image
            //_renderer.drawRectangle(v2, button.size().width(), button.size().height(), button.color()->hex(), button.color()->alpha());
        }
        index++;
    }
}

void MenuParser::renderText(){

    int index = 0;
    std::string textString = "text_";

    for(auto text : _menu->texts().text()){
        auto id = _textPrefix + std::to_string(index);
        auto textWrapper = (&_textItems[id])->get();
        textWrapper->render(text.position().x(), text.position().y());

        index++;
    }
}

SDL_Color MenuParser::HexToRGB(std::string hex, float opacity) const {

    std::regex pattern("#?([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})");

    std::smatch match;
    if (std::regex_match(hex, match, pattern))
    {
        SDL_Color color;

        color.r = std::stoi(match[1].str(), nullptr, 16);
        color.g = std::stoi(match[2].str(), nullptr, 16);
        color.b = std::stoi(match[3].str(), nullptr, 16);
        color.a = opacity;

        return color;
    }
    else
    {
        throw " is an invalid rgb color\n";
    }

}

void MenuParser::onClick(Input input) {
    if(!_menu->buttons().present()) return;

    for(auto button : _menu->buttons()->button()){
        Vector2 v2(button.position().x(), button.position().y());

        if(button.events().onClick().present()){
            if(v2.x <= input.x && v2.y <= input.y && (v2.x + button.size().width()) >= input.x &&  (v2.y + button.size().height()) >= input.y){

                std::cout << "button clicked" << std::endl;
            }
        }
    }
}




