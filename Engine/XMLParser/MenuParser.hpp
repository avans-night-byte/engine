#pragma once

#include "../../API/Rendering/EngineRenderingAPI.hpp"
#include "../../Resources/XML/Generated/menu.hxx"
#include "../Rendering/TextWrapper.hpp"
#include "../Input/Input.hpp"
#include "../Managers/ResourceManager.hpp"
#include <memory>

class MenuParser {
public:
    explicit MenuParser(const RenderingAPI &renderer);

    void openScene(const std::string &path);

    void render();

    void onClick(Input input);

private:

    std::map<std::string, std::unique_ptr<TextWrapper>> _textItems;
    const RenderingAPI &_renderer;
    std::unique_ptr<Menu::menu> _menu;

    void renderButtons();

    void renderText();

    std::string _buttonPrefix = "button_";
    std::string _textPrefix = "text_";
    std::string _fontPath = "../../Resources/Fonts/";

    ResourceManager *_resourceManager = nullptr;

    SDL_Color HexToRGB(std::string hex, float opacity) const;
};


