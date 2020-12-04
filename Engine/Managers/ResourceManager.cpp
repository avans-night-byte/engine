#include <iostream>
#include "ResourceManager.hpp"
#include <memory>


ResourceManager::ResourceManager(std::string resourcePath) {
    auto resources = GameResources::gameResources_(resourcePath);

    for (GameResources::texture texture_ : resources->textures().texture()) {
        std::cout << texture_.name() << std::endl;
        std::string name = texture_.name();
        _textures[name] = std::unique_ptr<GameResources::texture>(&texture_);
    }
}
