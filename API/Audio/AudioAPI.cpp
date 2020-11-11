//
// Created by Storm on 05/10/2020.
//
#include "AudioAPI.hpp"

void AudioAPI::playFromMemory(const std::string &name) {
    _adapter->playFromMemory(name);
}

std::vector<std::string> AudioAPI::getAudioNames() {
    return _adapter->getAudioNames();
}

void AudioAPI::loadInMemory(const std::string &path, AudioType &type) {
    _adapter->loadInMemory(path, type);
}

AudioAPI::AudioAPI() {
    _adapter = new SDLAudioEngineAdapter;
}

void AudioAPI::playFromPath(const std::string &path, AudioType &type) {
    SDLAudioEngineAdapter::playFromPath(path, type);

}

AudioAPI::~AudioAPI() {
    delete _adapter;
}



