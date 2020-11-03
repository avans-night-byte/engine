//
// Created by Storm on 05/10/2020.
//
#ifndef NIGHTBYTE_SDLAUDIOENGINEADAPTER_HPP
#define NIGHTBYTE_SDLAUDIOENGINEADAPTER_HPP

#include "SDL_mixer.h"
#include <iostream>
#include <map>

class SDLAudioEngineAdapter {
public:
    SDLAudioEngineAdapter();

    enum fileType { music, sound };

    std::vector<std::string> getAudioFiles();
    void playAudioFile(const std::string& name);
    void loadInMemory(const std::string &path, fileType type);



private:
    //The music that will be played
    std::map<std::string, Mix_Music*> _globalMusic;
    std::map<std::string, Mix_Chunk*> _sounds;


};
#endif //NIGHTBYTE_SDLAUDIOENGINEADAPTER_HPP