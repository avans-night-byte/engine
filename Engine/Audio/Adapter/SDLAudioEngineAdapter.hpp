#ifndef NIGHTBYTE_SDLAUDIOENGINEADAPTER_HPP
#define NIGHTBYTE_SDLAUDIOENGINEADAPTER_HPP

#include <iostream>
#include <map>

#include "SDL_mixer.h"
#include "../AudioType.h"


class SDLAudioEngineAdapter {
public:
    SDLAudioEngineAdapter();

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


private:
    //The music that will be played
    std::map<std::string, Mix_Music *> _globalMusic;
    std::map<std::string, Mix_Chunk *> _sounds;

    Mix_Music* _lastPlayedMusic;
};

#endif //NIGHTBYTE_SDLAUDIOENGINEADAPTER_HPP