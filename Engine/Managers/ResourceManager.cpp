#include <iostream>
#include "ResourceManager.hpp"
#include <memory>


ResourceManager::ResourceManager(std::string resourcePath) {
    try {
        std::cout << "ResourceManager is parsing..." << std::endl;
        auto resources = GameResources::resources_(resourcePath);
    } catch (const xml_schema::exception& e) {
        std::cout << e << std::endl;
    }


//    for (GameResources::texture texture_ : resources->textures().texture()) {
//        std::cout << texture_.name() << std::endl;
//        std::string name = texture_.name();
//        _textures[name] = std::unique_ptr<GameResources::texture>(&texture_);
//    }
}
