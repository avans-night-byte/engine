#pragma once

#include "Page.hpp"
#include "../../API/Rendering/EngineRenderingAPI.hpp"
#include "Generated/menu.hxx"
#include "../Rendering/TextWrapper.hpp"
#include "../Input/Input.hpp"
#include <memory>

class MenuParser {
public:
    explicit MenuParser(const RenderingAPI &renderer);
    void openScene(const std::string& path);
    void render();
    void onClick(Input input);
private:
    std::map<std::string, std::unique_ptr<TextWrapper>> _textItems;
    const RenderingAPI& _renderer;
    std::unique_ptr<Menu::menu> _menu;


};


