#pragma once

#include <iostream>
#include <map>

#include "SDL_mixer.h"
#include "../AudioType.h"

class SDLAudioEngineAdapter {
public:

    SDLAudioEngineAdapter();

    ~SDLAudioEngineAdapter();

    SDLAudioEngineAdapter(const SDLAudioEngineAdapter &other) = default;

    SDLAudioEngineAdapter(SDLAudioEngineAdapter &&other) noexcept = default;

    SDLAudioEngineAdapter &operator=(const SDLAudioEngineAdapter &other);

    SDLAudioEngineAdapter &operator=(SDLAudioEngineAdapter &&other) noexcept = default;

    std::vector<std::string> getAudioNames();

    void loadInMemory(const std::string &path, AudioType &type);

    void playFromPath(const std::string &path, AudioType &type);

    void playFromMemory(const std::string &name);

    static void changeMasterVolume(int volume);

    static void changeChannelVolume(int channel, int volume);

    static void changeMusicVolume(int volume);

    static int getChannelsAverageVolume();

    static int getChannelVolume(int channel);

    static int getMusicVolume();

    static void stopAudio();

    static void stopMusic();

    static void stopSound(int channel);

    static void stopSounds();

    static void toggleMusic();

    static void toggleSound(int channel);

    static void toggleSounds();
private:
    std::map<std::string, Mix_Music *> _musicTracks;
    std::map<std::string, Mix_Chunk *> _sounds;
};