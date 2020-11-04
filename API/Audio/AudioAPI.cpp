//
// Created by Storm on 05/10/2020.
//
#include "AudioAPI.hpp"

void AudioAPI::playAudioFile(const std::string &name) {

}

std::vector<std::string> AudioAPI::getAudioFiles() {
    return std::vector<std::string>();
}

void AudioAPI::loadInMemory(const std::string &path, AudioAPI::fileType type) {
    _adapter->loadInMemory(path, type);
}

AudioAPI::AudioAPI() {
    _adapter = new SDLAudioEngineAdapter;
}

AudioAPI::~AudioAPI() {
    delete _adapter;
}

