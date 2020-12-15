#include "ResourceManager.hpp"
#include "../Rendering/TextureManager.hpp"
#include "../Audio/Adapter/SDLAudioEngineAdapter.hpp"
#include "../XMLParser/MenuParser.hpp"
#include "../../Game/Game.hpp"
#include "../../Game/Scenes/LevelBase.hpp"
#include "../../Game/Object/GlobalObjects.hpp"

#include <iostream>
#include <memory>
#include <filesystem>

ResourceManager *ResourceManager::_instance = nullptr;

ResourceManager *ResourceManager::getInstance() {
    if (_instance == nullptr) {
        throw std::runtime_error("No instance found!");
    }
    return _instance;
}

ResourceManager *ResourceManager::instantiate(const std::string &resourcePath, bool debug) {
    if (_instance != nullptr) {
        throw std::runtime_error("[ERROR] [ResourceManager] Manager has already been initiated!");
    }

    if (_instance == nullptr) {
        _instance = new ResourceManager(resourcePath, debug);
    }

    return _instance;
}

ResourceManager::ResourceManager(const std::string &resourcePath, bool debug) {

    _debug = debug;
    try {
        if (_debug)
            std::cout << "[INFO] [ResourceManager] Starting parsing of all resources" << std::endl;

        auto resources = GameResources::resources_(resourcePath);
        _basePath = resources->basePath();

        // Discover textures
        for (GameResources::texture &texture : resources->textures().texture()) {
            verifyFile("Texture", TEXTURES, texture.name(), texture.path());

            std::string name = texture.name();
            _textures[name] = std::unique_ptr<GameResources::texture>(texture._clone());
        }

        // Discover sprites
        for (GameResources::sprite &sprite : resources->sprites().sprite()) {
            verifyFile("Sprite", SPRITES, sprite.name(), sprite.path());

            std::string name = sprite.name();
            _sprites[name] = std::unique_ptr<GameResources::sprite>(sprite._clone());
        }

        // Discover sounds
        for (GameResources::sound &sound : resources->sounds().sound()) {
            verifyFile("Sound", SOUNDS, sound.name(), sound.path());

            std::string name = sound.name();
            _sounds[name] = std::unique_ptr<GameResources::sound>(sound._clone());
        }

        // Discover music
        for (GameResources::music1 &music : resources->music().music1()) {
            verifyFile("Sound", MUSIC, music.name(), music.path());

            std::string name = music.name();
            _music[name] = std::unique_ptr<GameResources::music1>(music._clone());
        }

        // Discover scenes
        for (GameResources::scene &scene : resources->scenes().scene()) {
            verifyFile("Scene", SCENES, scene.name(), scene.path());

            std::string name = scene.name();
            _scenes[name] = std::unique_ptr<GameResources::scene>(scene._clone());
        }

        // Discover levels
        for (GameResources::level &level : resources->levels().level()) {
            verifyFile("Level", LEVELS, level.name(), level.path());

            std::string name = level.name();
            _levels[name] = std::unique_ptr<GameResources::level>(level._clone());
        }

        // Discover Object list
        for (GameResources::objectList &objectList : resources->objectLists().objectList()) {
            verifyFile("PreObject", OBJECTLIST, objectList.name(), objectList.path());

            std::string name = objectList.name();
            _preObjects[name] = std::unique_ptr<GameResources::objectList>(objectList._clone());
        }

    } catch (const xml_schema::exception &e) {
        std::cout << e << std::endl;
    }

}

void ResourceManager::loadRequiredResources(const std::vector<std::string> &resources) {
    for (const std::string &resource : resources) {
        loadResource(resource);
    }
}

void ResourceManager::loadResource(const std::string &resource) {
    if (!_resources.count(resource)) {
        throw std::invalid_argument("[ERROR] [ResourceManager] Fatal error! Required resource with name '" + resource +
                                    "' not found. Register it in resources first.");
    }


    // If it's already loaded in, we can skip it.
    if (std::find(_loadedResources.begin(), _loadedResources.end(), resource) != _loadedResources.end()) {
        return;
    }

    ResourceType type = _resources[resource];

    switch (type) {
        case TEXTURES: {
            auto &texture = _textures[resource];
            TextureManager::GetInstance()->load((_basePath + texture->path()).c_str(), texture->name());
            break;
        }
        case SPRITES:
            // TODO: Create a new spritesheet
            break;
        case SOUNDS: {
            auto &sound_ = _sounds[resource];
            SDLAudioEngineAdapter::getInstance().loadInMemory(_basePath + sound_->path(), sound_->name(), sound);
            break;
        }
        case MUSIC: {
            auto &music_ = _music[resource];
            SDLAudioEngineAdapter::getInstance().loadInMemory(_basePath + music_->path(), music_->name(), music);
            break;
        }
        case SCENES: {
            auto &scene = _scenes[resource];
            MenuParser::getInstance()->initialize(_basePath + scene->path());
            inMenu = true;
            if (quitLevel) {
                Game::getInstance()->unloadLevel();
                quitLevel = false;
                _currentLevel = "";
            }
            break;
        }
        case LEVELS: {
            inMenu = false;
            MenuParser::getInstance()->PreviousScenes.push(resource);
            auto &level = _levels[resource];
            if (level->name().c_str() == _currentLevel)
                break;

            const LevelData tmxData = LevelData(_basePath + level->tmxPath(),
                                                _basePath + level->spriteSheetPath(),
                                                level->spriteName(),
                                                _basePath + level->path());
            Game::getInstance()->initializeLeveL(level->name().c_str(), tmxData);
            _currentLevel = level->name().c_str();
            break;
        }
        case OBJECTLIST: {
            auto &objectList = _preObjects[resource];

            GlobalObjects::getInstance()->initializeObjects(objectList->name(), _basePath + objectList->path());

            break;
        }
    }

    if (type != SCENES && type != LEVELS)
        _loadedResources.push_back(resource);
}

void ResourceManager::unloadResource(std::string resource) {

}

void ResourceManager::verifyFile(const std::string &type, const ResourceType &resourceType, const std::string &name,
                                 const std::string &path) {
    if (_debug)
        std::cout << "[INFO] [ResourceManager] " << type << " discovered with name " << name << ". Verifying resource"
                  << std::endl;

    if (_resources.count(name)) {
        throw std::runtime_error(
                "[ERROR] [ResourceManager] " + name + " has already been declared before. Choose a different name");
    }

    if (!std::filesystem::exists(_basePath + path)) {
        throw std::runtime_error(
                "[ERROR] [ResourceManager] " + type + " " + name + " not found at '" + _basePath + path + "'");
    }

    _resources[name] = resourceType;
    if (_debug)
        std::cout << "[INFO] [ResourceManager] " << type << " with name " << name << " has been validated."
                  << std::endl;
}



