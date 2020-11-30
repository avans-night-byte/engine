#pragma once

#include <string>
#include "../Rendering/RenderingAPI.hpp"
#include "../../Engine/XMLParser/MenuParser.hpp"

class MenuParserAPI {
public:
    MenuParserAPI(EngineRenderingAPI &renderer);
    void loadScene(std::string path);
    void render();
private:
    std::unique_ptr<MenuParser> menuParser;
};


