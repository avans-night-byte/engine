#pragma once

#include "string"
#include <iostream>
#include <vector>

#include "SDL_mixer.h"

#include "../../Engine/Audio/Adapter/SDLAudioEngineAdapter.hpp"
#include "../../Engine/Audio/AudioType.h"

class AudioAPI {

public:
    ~AudioAPI();
    AudioAPI();

    AudioAPI(const AudioAPI &other) = default;
    AudioAPI(AudioAPI &&other) noexcept = default;

    AudioAPI &operator=(const AudioAPI &other) = default;
    AudioAPI &operator=(AudioAPI &&other) noexcept = default;

    std::vector<std::string> getAudioNames();

    void playFromMemory(const std::string &name);

    void playFromPath(const std::string &path, AudioType &type);

    void loadInMemory(const std::string &path, AudioType &type);

    static void stopAudio();

    static void stopMusic();

    static void stopSound(int channel);

    static void stopSounds();

    static void changeMasterVolume(int volume);

    static void changeChannelVolume(int channel, int volume);

    static void changeMusicVolume(int volume);

    static int getChannelsAverageVolume();

    static int getChannelVolume(int channel);

    static int getMusicVolume();

    static void toggleMusic();

    static void toggleSound(int channel);

    static void toggleSounds();

private:
    SDLAudioEngineAdapter *_adapter;
};