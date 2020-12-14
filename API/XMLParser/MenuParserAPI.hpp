#pragma once

#include <string>
#include "../../Engine/XMLParser/MenuParser.hpp"
#include "../../Engine/Helpers/Event.h"

class RenderingAPI;

class MenuParserAPI {
public:
    MenuParserAPI(RenderingAPI &renderer, Event<Input>& event);
    void loadScene(std::string path);
    void render();
    void onClick(Input input);
    Event<std::string> &getCustomEventHandler();
private:
    std::unique_ptr<MenuParser> menuParser;
};


