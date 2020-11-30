#include <string>
#include "menu_parser.hpp"
#include "Page.hpp"
#include "../Resources/XML/Generated/menu.hxx"
#include "../Resources/XML/Generated/wall.hxx"

Page menu_parser::createPage() {
    auto menu = menu_(path_);

    return Page();
}

menu_parser::menu_parser(RenderingAPI &renderer, std::string &path) {

}
