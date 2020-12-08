#include <string>
#include <regex>
#include "MenuParser.hpp"
#include "../Audio/Adapter/SDLAudioEngineAdapter.hpp"


MenuParser *MenuParser::_instance = nullptr;

MenuParser::MenuParser(const RenderingAPI &renderer) : _renderer(renderer) {
    if (_instance != nullptr) {
        throw std::runtime_error("[ERROR] [MenuParser] Manager has already been initiated!");
    }
    _resourceManager = ResourceManager::getInstance();
    _instance = this;
}

void MenuParser::initialize(const std::string &path) {
    SDLAudioEngineAdapter *audioEngineAdapter = SDLAudioEngineAdapter::getInstance();

    _menu = Menu::menu_(path);

    _textItems = std::map<std::string, std::unique_ptr<TextWrapper>>();

    for (auto &resource : _menu->preloadResources().resource()) {
        _resourceManager->loadResource(resource);
    }

    if (_menu->buttons().present()) {
        int index = 0;
        for (auto button : _menu->buttons()->button()) {
            if(!button.content().present())
                continue;

            auto createdString = _buttonPrefix + std::to_string(index);
            auto wrapper = TextWrapper::createText(_renderer, button.content()->c_str(),
                                                   (_fontPath + "Montserrat-Bold.ttf").c_str(), 32,
                                                   SDL_Color{255, 255, 255}, createdString);

            _textItems[createdString] = std::unique_ptr<TextWrapper>(wrapper);
            index++;
        }
    }

    int index = 0;
    for (auto text : _menu->texts().text()) {

        auto createdString = _textPrefix + std::to_string(index);
        auto wrapper = TextWrapper::createText(_renderer, text.content().c_str(),
                                               (_fontPath + "Montserrat-Regular.ttf").c_str(), 32,
                                               HexToRGB(text.color().hex(), text.color().alpha()), createdString);

        _textItems[createdString] = std::unique_ptr<TextWrapper>(wrapper);
        index++;
    }


    if (_menu->backgroundMusic().present() && _previousSong != _menu->backgroundMusic()->c_str()) {
        audioEngineAdapter->playFromMemory(_menu->backgroundMusic()->c_str());
        _previousSong = _menu->backgroundMusic()->c_str();
    }


}

void MenuParser::render() {
    if (_menu == nullptr) return;

    if (_menu->color().present()) {
        _renderer.drawBackground(_menu->color()->hex(), _menu->color()->alpha());
    } else {
        _renderer.drawTexture(_menu->resources()->default_(), 0, 0, 1920, 1080, 1, 0);
    }

    MenuParser::renderImages();
    MenuParser::renderText();
    MenuParser::renderButtons();
}

void MenuParser::renderButtons() {

    int index = 0;
    if (!_menu->buttons().present()) return;

    for (auto button : _menu->buttons()->button()) {
        Vector2 v2(button.position().x(), button.position().y());

        if (button.color().present()) {
            _renderer.drawRectangle(v2, button.size().width(), button.size().height(), button.color()->hex(),
                                    button.color()->alpha());
            auto id = _buttonPrefix + std::to_string(index);
            auto textWrapper = (&_textItems[id])->get();

            textWrapper->render(button.position().x() + ((button.size().width() / 2) - textWrapper->getSize().x / 2),
                                button.position().y() + ((button.size().height() / 2) - textWrapper->getSize().y / 2));
        } else {
            //TODO: draw rectangle with resource image

            _renderer.drawTexture(   button.resources()->default_(), v2.x, v2.y, button.size().width(), button.size().height(), 1, 0);
            //_renderer.drawRectangle(v2, button.size().width(), button.size().height(), button.color()->hex(), button.color()->alpha());
        }
        index++;
    }
}

void MenuParser::renderText() {

    int index = 0;
    for (auto text : _menu->texts().text()) {
        auto id = _textPrefix + std::to_string(index);
        auto textWrapper = (&_textItems[id])->get();
        textWrapper->render(text.position().x(), text.position().y());

        index++;
    }
}

void MenuParser::renderImages() {
    int index = 0;

    for (auto image : _menu->images().image()) {
        _renderer.drawTexture(image.resources().default_(), image.position().x(), image.position().y(),
                              image.size().width(), image.size().height(), 1, 0);
        index++;
    }

}

SDL_Color MenuParser::HexToRGB(const std::string& hex, float opacity) {

    std::regex pattern("#?([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})");

    std::smatch match;
    if (std::regex_match(hex, match, pattern)) {
        SDL_Color color;

        color.r = std::stoi(match[1].str(), nullptr, 16);
        color.g = std::stoi(match[2].str(), nullptr, 16);
        color.b = std::stoi(match[3].str(), nullptr, 16);
        color.a = opacity;

        return color;
    } else {
        throw " is an invalid rgb color\n";
    }

}

void MenuParser::onClick(const Input& input) {
    if (!_menu->buttons().present()) return;

    for (auto button : _menu->buttons()->button()) {
        Vector2 v2(button.position().x(), button.position().y());

        if (button.events().onClick().present()) {
            if (v2.x <= input.x && v2.y <= input.y && (v2.x + button.size().width()) >= input.x &&
                (v2.y + button.size().height()) >= input.y) {

                if (button.events().onClick()->playSound().present())
                    SDLAudioEngineAdapter::getInstance()->playFromMemory(
                            button.events().onClick()->playSound()->c_str());

                if (button.events().onClick()->loadScene().present())
                    ResourceManager::getInstance()->loadResource(button.events().onClick()->loadScene()->c_str());

                if (button.events().onClick()->custom().present()) {
                    const std::string action = button.events().onClick()->custom()->c_str();

                    if(action == "close") {
                        // TODO: Close
                    }
                }

                return;
            }
        }
    }
}

MenuParser *MenuParser::getInstance() {
    if (_instance == nullptr) {
        throw std::runtime_error("No instance found!");
    }
    return _instance;
}




