#pragma once

#include <iostream>
#include <map>

#include "SDL_mixer.h"
#include "../AudioType.h"
#include "./AudioEngineAdapter.hpp"

class SDLAudioEngineAdapter : public AudioEngineAdapter {

private:
    static SDLAudioEngineAdapter *_instance;
public:

    SDLAudioEngineAdapter();

    ~SDLAudioEngineAdapter();

    SDLAudioEngineAdapter(const SDLAudioEngineAdapter &other) = default;

    SDLAudioEngineAdapter(SDLAudioEngineAdapter &&other) noexcept = default;

    SDLAudioEngineAdapter &operator=(const SDLAudioEngineAdapter &other);

    SDLAudioEngineAdapter &operator=(SDLAudioEngineAdapter &&other) noexcept = default;

    std::vector<std::string> getAudioNames() override;

    void loadInMemory(const std::string &path, const std::string &name, AudioType type) override;

    void playFromPath(const std::string &path, AudioType &type) override;

    void playFromMemory(const std::string &name) override;

    void changeMasterVolume(int volume) override;

    void changeChannelVolume(int channel, int volume) override;

    void changeMusicVolume(int volume) override;

    int getChannelsAverageVolume() override;

    int getChannelVolume(int channel) override;

    int getMusicVolume() override;

    void stopAudio() override;

    void stopMusic() override;

    void stopSound(int channel) override;

    void stopSounds() override;

    void toggleMusic() override;

    void toggleSound(int channel) override;

    void toggleSounds() override;

    std::string &getCurrentPlayingMusic();

    static SDLAudioEngineAdapter &getInstance();

private:
    std::map<std::string, Mix_Music *> _musicTracks;
    std::map<std::string, Mix_Chunk *> _sounds;
    std::string _currentPlayingMusic;
};