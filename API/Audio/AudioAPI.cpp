//
// Created by Storm on 05/10/2020.
//
#include "AudioAPI.hpp"

AudioAPI::AudioAPI() {
    _adapter = new SDLAudioEngineAdapter;
}

void AudioAPI::playFromMemory(const std::string &name) {
    _adapter->playFromMemory(name);
}

std::vector<std::string> AudioAPI::getAudioNames() {
    return _adapter->getAudioNames();
}

void AudioAPI::loadInMemory(const std::string &path, AudioType &type) {
    _adapter->loadInMemory(path, type);
}

void AudioAPI::playFromPath(const std::string &path, AudioType &type) {
    _adapter->playFromPath(path, type);

}

void AudioAPI::changeMasterVolume(int volume) {
    SDLAudioEngineAdapter::changeMasterVolume(volume);
}

void AudioAPI::changeChannelVolume(int channel, int volume) {
    SDLAudioEngineAdapter::changeChannelVolume(channel, volume);
}

void AudioAPI::changeMusicVolume(int volume) {
    SDLAudioEngineAdapter::changeMusicVolume(volume);
}

int AudioAPI::getChannelVolume(int channel) {
    return SDLAudioEngineAdapter::getChannelVolume(channel);
}

int AudioAPI::getMusicVolume() {
    return SDLAudioEngineAdapter::getMusicVolume();
}

int AudioAPI::getChannelsAverageVolume() {
    return SDLAudioEngineAdapter::getChannelsAverageVolume();
}

void AudioAPI::stopAudio() {
    SDLAudioEngineAdapter::stopAudio();
}

void AudioAPI::stopMusic() {

    SDLAudioEngineAdapter::stopMusic();
}

void AudioAPI::stopSound(int channel) {
    SDLAudioEngineAdapter::stopSound(channel);
}

void AudioAPI::stopSounds() {
    SDLAudioEngineAdapter::stopSounds();
}

AudioAPI::~AudioAPI() {
    delete _adapter;
}
















