#pragma once

#include <string>
#include "../../Engine/XMLParser/MenuParser.hpp"
#include "../../API/Helpers/Event.h"

class RenderingAPI;

class MenuParserAPI {
public:
    MenuParserAPI(RenderingAPI &renderer, Event<Input>& event);
    void loadScene(const std::string& path);
    void render();
    void onClick(const Input& input);
    std::map<std::string, std::string> getDynamicFields();
    void setDynamicFieldValue(const std::string &field, const std::string &value);
    Event<std::string> &getCustomEventHandler();
private:
    std::unique_ptr<MenuParser> menuParser;
};


