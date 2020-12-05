#pragma once
#include <string>
#include <map>
#include <memory>
#include "../../Resources/XML/Generated/resources.hxx"


enum ResourceTypes {
    TEXTURES,
    SPRITES,
    SOUNDS,
    MUSIC,
    SCENES,
    LEVELS
};


class ResourceManager {
private:
    std::vector<std::string> _loadedResources;
    std::map<std::string, ResourceTypes> _resources;
    std::map<std::string, std::unique_ptr<GameResources::texture>> _textures;

public:
    explicit ResourceManager(const std::string& resourcePath);

    /**
     * Loads all required resources and unloads non-required ones.
     *
     * @param resources
     */
    void loadRequiredResources(const std::vector<std::string>& resources);

    void loadResource(std::string resource);
    void unloadResource(std::string resource);


};
