#include <vector>
#include "SDLAudioEngineAdapter.hpp"

/**
 * A class that holds all the needed functions to load in and play music
 *
 * You can either choose to load a sound file directly from a file path or trough memory by adding it to a dictionary
 *
 * Some functions are declared static for easier sound managing and optimisation.
 * Only loading and playing of a new file requires an instance of the object
 */
SDLAudioEngineAdapter::SDLAudioEngineAdapter() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }

    if (Mix_Init(MIX_INIT_MP3) < 0) {
        printf("Failed to init Mix: %s\n", Mix_GetError());
    }
}

SDLAudioEngineAdapter::~SDLAudioEngineAdapter() {
    Mix_CloseAudio();
    _musicTracks.clear();
    _sounds.clear();
}

SDLAudioEngineAdapter &SDLAudioEngineAdapter::operator=(const SDLAudioEngineAdapter& other) {
    return *this = SDLAudioEngineAdapter(other);
}

std::vector<std::string> SDLAudioEngineAdapter::getAudioNames() {
    std::vector<std::string> keys;

    //Get from global music
    for (auto const &musicFile : _musicTracks)
        keys.push_back(musicFile.first);
    for (auto const &soundFile : _sounds)
        keys.push_back(soundFile.first);

    return keys;
}

void SDLAudioEngineAdapter::playFromMemory(const std::string &name) {

    if (_musicTracks.count(name) > 0) {
        Mix_Music* music = _musicTracks.at(name);
        Mix_PlayMusic(music, 1);
        return;
    }

    if (_sounds.count(name) > 0) {
        Mix_Chunk *soundEffect = _sounds.at(name);
        Mix_PlayChannel(-1, soundEffect, 0);
    }
}

void SDLAudioEngineAdapter::loadInMemory(const std::string &path, AudioType &type) {

    auto index = path.find_last_of('/');
    if (index == std::string::npos) index = 0;

    std::string name = path.substr(index, path.length());

    switch (type) {
        case music:
            _musicTracks[name] = Mix_LoadMUS(path.c_str());
            break;
        case sound:
            _sounds[name] = Mix_LoadWAV(path.c_str());
            break;
    }
}

void SDLAudioEngineAdapter::playFromPath(const std::string &path, AudioType &type) {
    Mix_Music *mixMusic = Mix_LoadMUS(path.c_str());
    Mix_Chunk *mixChunk = Mix_LoadWAV(path.c_str());

    switch (type) {
        case music:
            if (mixMusic != nullptr) {
                Mix_PlayMusic(mixMusic, 1);
            }
            break;
        case sound:
            if (mixChunk != nullptr) {
                Mix_PlayChannel(-1, mixChunk, 0);
            }
            break;
    }
}

void SDLAudioEngineAdapter::changeMasterVolume(int volume) {
    Mix_Volume(-1, volume);
    Mix_VolumeMusic(volume);
}

void SDLAudioEngineAdapter::changeChannelVolume(int channel, int volume) {
    Mix_Volume(channel, volume);
}

void SDLAudioEngineAdapter::changeMusicVolume(int volume) {
    Mix_VolumeMusic(volume);
}

int SDLAudioEngineAdapter::getChannelVolume(int channel) {
    return Mix_Volume(channel, -1);
}

int SDLAudioEngineAdapter::getMusicVolume() {
    return Mix_VolumeMusic(-1);
}

int SDLAudioEngineAdapter::getChannelsAverageVolume() {
    return Mix_Volume(-1, -1);
}

void SDLAudioEngineAdapter::stopAudio() {
    Mix_CloseAudio();
}

void SDLAudioEngineAdapter::stopMusic() {
    if (Mix_PlayingMusic())
        Mix_HaltMusic();
}

void SDLAudioEngineAdapter::stopSound(int channel) {
    Mix_HaltChannel(channel);
}

void SDLAudioEngineAdapter::stopSounds() {
    Mix_HaltChannel(-1);
}

void SDLAudioEngineAdapter::toggleMusic() {
    if(Mix_PausedMusic())
        Mix_ResumeMusic();
    else
        Mix_PauseMusic();
}

void SDLAudioEngineAdapter::toggleSound(int channel) {
    if(Mix_Paused(channel))
        Mix_Pause(channel);
    else
        Mix_Resume(channel);
}

void SDLAudioEngineAdapter::toggleSounds() {
    if(Mix_Paused(-1))
        Mix_Pause(-1);
    else
        Mix_Resume(-1);
}
