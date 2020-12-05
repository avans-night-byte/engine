#include <iostream>
#include "ResourceManager.hpp"
#include <memory>


ResourceManager::ResourceManager(const std::string &resourcePath) {
    try {
        std::cout << "[ResourceManager] Starting parsing of all resources" << std::endl;
        auto resources = GameResources::resources_(resourcePath);

        for (GameResources::texture &texture : resources->textures().texture()) {
            std::cout << "[ResourceManager] Texture discovered: " << texture.name() << std::endl;

            std::string name = texture.name();
            _textures[name] = std::unique_ptr<GameResources::texture>(&texture);
        }

    } catch (const xml_schema::exception &e) {
        std::cout << e << std::endl;
    }

}

void ResourceManager::loadRequiredResources(const std::vector<std::string>& resources) {
    for (const std::string& resource : resources) {
        if(!_resources.count(resource)) {
            std::cout << "[ResourceManager] Fatal error! Required resource " << resource << " not found." << std::endl;
            throw std::invalid_argument("Resource not found!");
        }

        // If it's already loaded in, we can skip it.
        if(std::find(_loadedResources.begin(), _loadedResources.end(), resource) != _loadedResources.end()) {
            return;
        }

        ResourceTypes type = _resources[resource];

        switch (type) {
            case TEXTURES:
                // TODO: TextureManager create the texture in memory
                break;
            case SPRITES:
                // TODO: Create a new spritesheet
                break;
            case SOUNDS:
                // TODO: Create a new sound
                break;
            case MUSIC:
                // TODO: Create a new sound (but music)
                break;
            case SCENES:
                // TODO: Load the scene
                break;
            case LEVELS:
                // TODO: Load the level
                break;
        }

    }
}

void ResourceManager::loadResource(std::string resource) {

}

void ResourceManager::unloadResource(std::string resource) {

}

