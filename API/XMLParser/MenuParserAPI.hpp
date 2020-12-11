#pragma once

#include <string>
#include "../../Engine/XMLParser/MenuParser.hpp"
#include "../../Engine/Event.h"

class RenderingAPI;

class MenuParserAPI {
public:
    MenuParserAPI(RenderingAPI &renderer, Event<Input>& event);
    void loadScene(std::string path);
    void render();
    void onClick(Input input);
private:
    std::unique_ptr<MenuParser> menuParser;
};


