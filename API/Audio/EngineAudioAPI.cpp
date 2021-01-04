#include "EngineAudioAPI.hpp"

/**
 * A class that separates the adapter and the Game layer
 */

EngineAudioAPI::EngineAudioAPI() : _adapter(SDLAudioEngineAdapter::getInstance()) {}


/**
 * Play a file from memory specified by name.
 * @param name
 */
void EngineAudioAPI::playFromMemory(const std::string &name) {
    _adapter.playFromMemory(name);
}

/**
 * Return a list of all audio names loaded in memory.
 * @return
 */
std::vector<std::string> EngineAudioAPI::getAudioNames() {
    return _adapter.getAudioNames();
}

/**
 * Load the specified audio into memory.
 * @param path
 * @param name
 * @param type
 */
void EngineAudioAPI::loadInMemory(const std::string &path, const std::string &name, AudioType type) {
    _adapter.loadInMemory(path, name, type);
}

/**
 * Play a audio file straight from the specified path.
 * @param path
 * @param type
 */
void EngineAudioAPI::playFromPath(const std::string &path, AudioType &type) {
    _adapter.playFromPath(path, type);

}

void EngineAudioAPI::changeMasterVolume(int volume) {
    _adapter.changeMasterVolume(volume);
}


void EngineAudioAPI::changeChannelVolume(int channel, int volume) {
    _adapter.changeChannelVolume(channel, volume);
}

void EngineAudioAPI::changeMusicVolume(int volume) {
    _adapter.changeMusicVolume(volume);
}

int EngineAudioAPI::getChannelVolume(int channel) {
    return  _adapter.getChannelVolume(channel);
}

int EngineAudioAPI::getMusicVolume() {
    return  _adapter.getMusicVolume();
}

int EngineAudioAPI::getChannelsAverageVolume() {
    return  _adapter.getChannelsAverageVolume();
}

/**
 * Stops all the audio that is currently playing.
 */
void EngineAudioAPI::stopAudio() {
    _adapter.stopAudio();
}

/**
 * Stops all the music that is currently playing.
 */
void EngineAudioAPI::stopMusic() {
    _adapter.stopMusic();
}

/**
 * Stop the sound that is playing in the specified channel.
 * @param channel
 */
void EngineAudioAPI::stopSound(int channel) {
    _adapter.stopSound(channel);
}


/**
 * Stops all the channel sounds except the music.
 */
void EngineAudioAPI::stopSounds() {
    _adapter.stopSounds();
}

/**
 * Pauses/Plays music.
 */
void EngineAudioAPI::toggleMusic() {
    _adapter.toggleMusic();
}

/**
 * Pauses/Plays the specified channel.
 * @param channel
 */
void EngineAudioAPI::toggleSound(int channel) {
    _adapter.toggleSound(channel);
}


/**
 * Pauses/resumes all the sound channels
 **/
void EngineAudioAPI::toggleSounds() {
    _adapter.toggleSounds();
}

