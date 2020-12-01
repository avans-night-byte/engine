#pragma once

#include "Page.hpp"
#include "../../API/Rendering/EngineRenderingAPI.hpp"
#include "../../../../Resources/XML/Generated/menu.hxx"

class MenuParser {
public:
    MenuParser(const EngineRenderingAPI &renderer);
    void openScene(const std::string& path);
    void render();
private:
   const EngineRenderingAPI& _renderer;
   std::unique_ptr<menu> _menu;
};


