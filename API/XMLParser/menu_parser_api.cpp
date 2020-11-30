//
// Created by Storm on 30/11/2020.
//

#include "menu_parser_api.hpp"

menu_parser_api::menu_parser_api(RenderingAPI &renderer, std::string &path){
    menu_parser_ = std::make_unique<menu_parser>(renderer, path);
}