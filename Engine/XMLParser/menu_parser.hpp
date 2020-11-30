#pragma once


#include "Page.hpp"
#include "../../API/Rendering/RenderingAPI.hpp"

class menu_parser {
public:
    menu_parser(RenderingAPI &renderer);
    Page open_scene(std::string &path);

private:
    RenderingAPI& renderer_;
};


