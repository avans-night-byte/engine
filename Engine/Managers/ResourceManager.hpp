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
    std::map<std::string, ResourceTypes> _resources;
    std::map<std::string, std::unique_ptr<GameResources::texture>> _textures;

public:
    ResourceManager(std::string resourcePath);

};
