#pragma once


#include "Page.hpp"
#include "../../API/Rendering/RenderingAPI.hpp"

class menu_parser {
public:
    menu_parser(RenderingAPI &renderer, std::string &path);
    Page createPage();

private:
    std::string& path_;
};


