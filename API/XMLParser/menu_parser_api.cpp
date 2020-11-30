//
// Created by Storm on 30/11/2020.
//

#include "menu_parser_api.hpp"

menu_parser_api::menu_parser_api(RenderingAPI &renderer){
    menu_parser_ = std::make_unique<menu_parser>(renderer);
}

Page menu_parser_api::load_scene(std::string &path) {
    return menu_parser_->open_scene(path);
}
