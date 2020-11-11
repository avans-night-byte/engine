//
// Created by Storm on 05/10/2020.
//
#ifndef NIGHTBYTE_SDLAUDIOENGINEADAPTER_HPP
#define NIGHTBYTE_SDLAUDIOENGINEADAPTER_HPP

#include "SDL_mixer.h"
#include "../AudioType.h"
#include <iostream>
#include <map>

class SDLAudioEngineAdapter {
public:
    SDLAudioEngineAdapter();

    std::vector<std::string> getAudioNames();

    void loadInMemory(const std::string &path, AudioType &type);

    static void playFromPath(const std::string &path, AudioType &type);

    void playFromMemory(const std::string &name);

    static void changeMasterVolume(int volume);

    static void changeChannelVolume(int channel, int volume);

    static void changeMusicVolume(int volume);

    static int getChannelsAverageVolume();

    static int getChannelVolume(int channel);

    static int getMusicVolume();

private:
    //The music that will be played
    std::map<std::string, Mix_Music *> _globalMusic;
    std::map<std::string, Mix_Chunk *> _sounds;


};

#endif //NIGHTBYTE_SDLAUDIOENGINEADAPTER_HPP