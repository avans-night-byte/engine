#pragma once


#include <memory>
#include <stack>


#include "../../API/Rendering/EngineRenderingAPI.hpp"
#include "../../Resources/XML/Generated/menu.hxx"
#include "../Rendering/TextWrapper.hpp"
#include "../Input/Input.hpp"
#include "../Managers/ResourceManager.hpp"
#include "../Helpers/Event.h"

class RenderingAPI;


class MenuParser {

private:
    std::map<std::string, TextWrapper*> _textItems;

    const RenderingAPI &_renderer;
    std::unique_ptr<Menu::menu> _menu;
    std::string _previousSong;

    const std::string _buttonPrefix = "button_";
    const std::string _textPrefix = "text_";
    const std::string _fontPath = "../../Resources/Fonts/";

    static MenuParser *_instance;
    static std::map<std::string, SDL_Color> _colors;

    ResourceManager *_resourceManager = nullptr;
    Event<std::string> _customEventHandler;
public:

    std::stack<std::string> PreviousScenes;

    MenuParser(MenuParser &other) = delete;

    void operator=(const MenuParser &) = delete;

    explicit MenuParser(const RenderingAPI &renderer);

    void initialize(const std::string &path);

    void render();

    void onClick(const Input& input);

    static MenuParser *getInstance();

    Event<std::string> &getCustomEventHandler();

    ~MenuParser();

private:

    void renderButtons();

    void renderText();

    void renderImages();

    void renderBoxes();
};


