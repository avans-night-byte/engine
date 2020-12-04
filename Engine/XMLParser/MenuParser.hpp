#pragma once

#include "Page.hpp"
#include "../../API/Rendering/EngineRenderingAPI.hpp"
#include "Generated/menu.hxx"
#include "../Rendering/TextWrapper.hpp"
#include <memory>

class MenuParser {
public:
    MenuParser(const EngineRenderingAPI &renderer);
    void openScene(const std::string& path);
    void render();
private:
    std::map<std::string, std::unique_ptr<TextWrapper>> _textItems;
    const EngineRenderingAPI& _renderer;
    std::unique_ptr<menu> _menu;
};


