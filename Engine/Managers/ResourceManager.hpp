#pragma once

#include <string>
#include <map>
#include <memory>
#include "../../Resources/XML/Generated/resources.hxx"


enum ResourceType {
    TEXTURES,
    SPRITES,
    SOUNDS,
    MUSIC,
    SCENES,
    LEVELS
};


class ResourceManager {
private:
    std::string _basePath;
    bool _debug;

    // Resources
    std::vector<std::string> _loadedResources;
    std::map<std::string, ResourceType> _resources;

    // Textures
    std::map<std::string, std::unique_ptr<GameResources::texture>> _textures;
    // std::map<std::string, std::unique_ptr<f>> _loadedTextures;

    // Sprites
    std::map<std::string, std::unique_ptr<GameResources::sprite>> _sprites;

    // Sounds
    std::map<std::string, std::unique_ptr<GameResources::sound>> _sounds;

    // Music
    std::map<std::string, std::unique_ptr<GameResources::music1>> _music;

    // Scenes
    std::map<std::string, std::unique_ptr<GameResources::scene>> _scenes;

    // Levels
    std::map<std::string, std::unique_ptr<GameResources::level>> _levels;

    // Verification
    void verifyFile(const std::string& type, const ResourceType& resourceType, const std::string& name, const std::string& path);
    static ResourceManager* _instance;
protected:
    explicit ResourceManager(const std::string &resourcePath, bool debug = true);
public:
    /**
     * Loads all required resources and unloads non-required ones.
     *
     * @param resources
     */
    void loadRequiredResources(const std::vector<std::string> &resources);

    void loadResource(const std::string& resource);

    void unloadResource(std::string resource);

    static ResourceManager* getInstance();
    static ResourceManager* instantiate(const std::string &resourcePath, bool debug = true);
};
