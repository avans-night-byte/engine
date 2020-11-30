//
// Created by Storm on 30/11/2020.
//

#pragma once


#include <string>
#include "../Rendering/RenderingAPI.hpp"
#include "../../Engine/XMLParser/menu_parser.hpp"

class menu_parser_api {
public:
    menu_parser_api(RenderingAPI &renderer);
    Page load_scene(std::string& path);
private:
    std::unique_ptr<menu_parser> menu_parser_;
};


