#include "EngineAudioAPI.hpp"

/**
 * A class that separates the adapter and the Game layer
 */

EngineAudioAPI::EngineAudioAPI() {
    _adapter = std::make_unique<SDLAudioEngineAdapter>();
}


void EngineAudioAPI::playFromMemory(const std::string &name) {
    _adapter->playFromMemory(name);
}

std::vector<std::string> EngineAudioAPI::getAudioNames() {
    return _adapter->getAudioNames();
}

void EngineAudioAPI::loadInMemory(const std::string &path, const std::string &name, AudioType type) {
    _adapter->loadInMemory(path, name, type);
}

void EngineAudioAPI::playFromPath(const std::string &path, AudioType &type) {
    _adapter->playFromPath(path, type);

}

void EngineAudioAPI::changeMasterVolume(int volume) {
    _adapter->changeMasterVolume(volume);
}

void EngineAudioAPI::changeChannelVolume(int channel, int volume) {
    _adapter->changeChannelVolume(channel, volume);
}

void EngineAudioAPI::changeMusicVolume(int volume) {
    _adapter->changeMusicVolume(volume);
}

int EngineAudioAPI::getChannelVolume(int channel) {
    return  _adapter->getChannelVolume(channel);
}

int EngineAudioAPI::getMusicVolume() {
    return  _adapter->getMusicVolume();
}

int EngineAudioAPI::getChannelsAverageVolume() {
    return  _adapter->getChannelsAverageVolume();
}

void EngineAudioAPI::stopAudio() {
    _adapter->stopAudio();
}

void EngineAudioAPI::stopMusic() {

    _adapter->stopMusic();
}

void EngineAudioAPI::stopSound(int channel) {
    _adapter->stopSound(channel);
}

void EngineAudioAPI::stopSounds() {
    _adapter->stopSounds();
}

void EngineAudioAPI::toggleMusic() {
    _adapter->toggleMusic();
}

void EngineAudioAPI::toggleSound(int channel) {
    _adapter->toggleSound(channel);
}

void EngineAudioAPI::toggleSounds() {
    _adapter->toggleSounds();
}

