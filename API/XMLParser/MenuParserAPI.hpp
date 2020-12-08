#pragma once

#include <string>
#include "../Rendering/EngineRenderingAPI.hpp"
#include "../../Engine/XMLParser/MenuParser.hpp"
#include "../../Engine/Event.h"

class MenuParserAPI {
public:
    MenuParserAPI(RenderingAPI &renderer, Event<Input>& event);
    void loadScene(std::string path);
    void render();
    void onClick(Input input);
private:
    std::unique_ptr<MenuParser> menuParser;
};


