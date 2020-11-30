#include <string>
#include "menu_parser.hpp"
#include "Page.hpp"
#include "../Resources/XML/Generated/menu.hxx"
#include "../Resources/XML/Generated/wall.hxx"

Page menu_parser::open_scene(std::string path) {
    auto menu = menu_(path);

   for(auto button : menu->buttons().button()){
       std::cout << button.content() << std::endl;
   }

    return Page();
}

menu_parser::menu_parser(RenderingAPI &renderer) : renderer_(renderer) {

}
