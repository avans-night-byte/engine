#pragma once

#include "../../API/Rendering/EngineRenderingAPI.hpp"
#include "../../Resources/XML/Generated/menu.hxx"
#include "../Rendering/TextWrapper.hpp"
#include "../Input/Input.hpp"
#include "../Managers/ResourceManager.hpp"
#include <memory>

class MenuParser {

private:
    static MenuParser *_instance;

    std::map<std::string, std::unique_ptr<TextWrapper>> _textItems;
    const RenderingAPI &_renderer;
    std::unique_ptr<Menu::menu> _menu;
    std::string _previousSong;

public:

    MenuParser(MenuParser &other) = delete;

    void operator=(const MenuParser &) = delete;

    explicit MenuParser(const RenderingAPI &renderer);

    void initialize(const std::string &path);

    void render();

    void onClick(const Input& input);

    static MenuParser *getInstance();

private:

    void renderButtons();

    void renderText();

    std::string _buttonPrefix = "button_";
    std::string _textPrefix = "text_";
    std::string _fontPath = "../../Resources/Fonts/";
    static std::map<std::string, SDL_Color> _colors;

    ResourceManager *_resourceManager = nullptr;

    static SDL_Color HexToRGB(const std::string& hex, float opacity) ;

    void renderImages();

    void renderBoxes();
};


