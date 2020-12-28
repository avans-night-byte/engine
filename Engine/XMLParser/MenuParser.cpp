#include <string>
#include <regex>
#include "MenuParser.hpp"
#include "../Audio/Adapter/SDLAudioEngineAdapter.hpp"
#include "../Rendering/TextWrapper.hpp"


MenuParser *MenuParser::_instance = nullptr;
std::map<std::string, SDL_Color> MenuParser::_colors{};

MenuParser::MenuParser(const RenderingAPI &renderer) : _renderer(renderer) {
    if (_instance != nullptr) {
        throw std::runtime_error("[ERROR] [MenuParser] Manager has already been initiated!");
    }

    _resourceManager = ResourceManager::getInstance();
    _instance = this;
}

MenuParser::~MenuParser() {
    _textItems.clear();
}

void MenuParser::initialize(const std::string &path) {
    AudioEngineAdapter &audioEngineAdapter = SDLAudioEngineAdapter::getInstance();

    _menu = Menu::menu_(path);
    _textItems = std::map<std::string, TextWrapper*>();

    for (auto &resource : _menu->preloadResources().resource()) {
        _resourceManager->loadResource(resource);
    }

    if (_menu->buttons().present()) {
        int index = 0;
        for (auto button : _menu->buttons()->button()) {
            if (!button.text().present())
                continue;

            std::string createdString = _buttonPrefix + std::to_string(index);

            const auto font = _fontPath + button.text()->font().family() + "-" + button.text()->font().weight() +".ttf";
            auto wrapper = TextWrapper::createText(_renderer, button.text()->content(),
                                                   font, button.text()->font().size(),
                                                   button.text()->color().hex(), createdString);
            _textItems[createdString] = wrapper;

            index++;
        }
    }

    int index = 0;
    for (auto text : _menu->texts().text()) {

        auto createdString = _textPrefix + std::to_string(index);

        if(text.text_type().dynamic().present()){
            std::string id = text.text_type().dynamic()->c_str();
            _dynamicTextItems[id] = createdString;
        }

        auto wrapper = TextWrapper::createText(_renderer, text.content(),
                                               (_fontPath + text.font().family() + "-" + text.font().weight() +".ttf"), text.font().size(),
                                               text.color().hex(), createdString);

        _textItems[createdString] = wrapper;
        index++;
    }


    if (_menu->backgroundMusic().present() && _previousSong != _menu->backgroundMusic()->c_str()) {
        audioEngineAdapter.playFromMemory(_menu->backgroundMusic()->c_str());
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

    MenuParser::renderBoxes();
    MenuParser::renderImages();
    MenuParser::renderText();
    MenuParser::renderButtons();
}

void MenuParser::renderButtons() {

    int index = 0;
    if (!_menu->buttons().present()) return;

    for (auto button : _menu->buttons()->button()) {
        float posX = button.position().x();
        float posY = button.position().y();

        float width = button.size().width();
        float height = button.size().height();

        Vector2 v2(posX, posY);

        if (button.color().present()) {
            auto id = _buttonPrefix + std::to_string(index);
            auto textWrapper = _textItems[id];

            _renderer.drawRectangle(v2, width, height, button.color()->hex(), button.color()->alpha());

            textWrapper->render((posX + (width / 2) - textWrapper->getSize().x / 2),
                                (posY + (height / 2) - textWrapper->getSize().y / 2)
            );
        } else {
            _renderer.drawTexture(button.resources()->default_(), v2.x, v2.y, width, height, 1, 0);
        }

        index++;
    }
}

void MenuParser::renderText() {

    int index = 0;
    for (auto text : _menu->texts().text()) {
        auto id = _textPrefix + std::to_string(index);
        auto textWrapper = _textItems[id];
        textWrapper->render(text.position().x(), text.position().y());

        index++;
    }
}

void MenuParser::renderImages() {
    int index = 0;

    for (auto image : _menu->images()->image()) {
        _renderer.drawTexture(image.resources().default_(), image.position().x(), image.position().y(),
                              image.size().width(), image.size().height(), 1, 0);
        index++;
    }

}

void MenuParser::renderBoxes() {
    int index = 0;
    if (!_menu->boxes().present()) return;

    for (auto box : _menu->boxes()->box()) {
        Vector2 v2(box.position().x(), box.position().y());

        _renderer.drawRectangle(v2, box.size().width(), box.size().height(), box.color().hex(),
                                box.color().alpha());
        index++;
    }
}

std::map<std::string, std::string> MenuParser::getDynamicFields() {
    return _dynamicTextItems;
}

void MenuParser::setDynamicFieldValue(const std::string &field, const std::string &value) {

    for(auto &text : _menu->texts().text()){
        if(text.text_type().dynamic().present() && text.text_type().dynamic()->c_str() == field){

            auto textFieldId = _dynamicTextItems[field];

            auto wrapper = TextWrapper::createText(_renderer, value,
                                                   (_fontPath + text.font().family() + "-" + text.font().weight() +".ttf"), text.font().size(),
                                                   text.color().hex(), textFieldId);

            _textItems[textFieldId] = wrapper;
        }
    }


}

void MenuParser::onClick(const Input &input) {
    if (!_menu->buttons().present() || !_resourceManager->inMenu) return;

    for (auto button : _menu->buttons()->button()) {
        if (!button.events().onClick().present())
            continue;

        Vector2 buttonPos(button.position().x(), button.position().y());
        Vector2 buttonBounds(buttonPos.x + button.size().width(), buttonPos.y + button.size().height());

        if (buttonPos.x <= input.x && buttonPos.y <= input.y && buttonBounds.x >= input.x &&
            buttonBounds.y >= input.y) {


            if (button.events().onClick()->custom().present()) {
                const std::string action = button.events().onClick()->custom()->c_str();
                _customEventHandler(action);
            }

            if (button.events().onClick()->playSound().present())
                SDLAudioEngineAdapter::getInstance().playFromMemory(
                        button.events().onClick()->playSound()->c_str());

            if (button.events().onClick()->loadScene().present()) {

                std::string nextScene = button.events().onClick()->loadScene()->c_str();

                if (nextScene == "Previous") {
                    nextScene = PreviousScenes.top();
                    PreviousScenes.pop();
                } else {
                    PreviousScenes.push(_menu->name());
                }
                ResourceManager::getInstance()->loadResource(nextScene);
            }

            if (button.events().onClick()->loadURL().present()) {
#if WIN32
                //Windows open
                std::string command = "start ";
                command += button.events().onClick()->loadURL()->c_str();
                system(command.c_str());
#endif

#if __linux__
                std::string command = "start ";
                //Linux open
                command = "open ";
                command += button.events().onClick()->loadURL()->c_str();
                system(command.c_str());
#endif
            }

            return;
        }
    }
}

MenuParser *MenuParser::getInstance() {
    if (_instance == nullptr) {
        throw std::runtime_error("No instance found!");
    }
    return _instance;
}

Event <std::string> &MenuParser::getCustomEventHandler() {
    return _customEventHandler;
}








