//
// Created by Storm on 05/10/2020.
//

#include <vector>
#include "SDLAudioEngineAdapter.hpp"

SDLAudioEngineAdapter::SDLAudioEngineAdapter()
{

    // TODO: Try higher frequency
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }

    if(Mix_Init(MIX_INIT_MP3) < 0)
    {
        printf( "Failed to init Mix: %s\n", Mix_GetError() );
    }
}

std::vector<std::string> SDLAudioEngineAdapter::getAudioFiles() {
    std::vector<std::string> keys;

    //Get from global music
    for(auto const& musicFile : _globalMusic)
        keys.push_back(musicFile.first);
    for(auto const& soundFile : _sounds)
        keys.push_back(soundFile.first);

    return keys;
}

void SDLAudioEngineAdapter::playAudioFile(const std::string& name) {
    Mix_Music* music = _globalMusic.at(name);
    if(music != nullptr){
        Mix_PlayMusic(music, 1);
        return;
    }
    Mix_Chunk* soundEffect = _sounds.at(name);
    if(soundEffect != nullptr){
        Mix_PlayChannel(-1, soundEffect, 0);
    }

}

void SDLAudioEngineAdapter::loadInMemory(const std::string& path, fileType type) {

    switch (type) {
        case music:
            _globalMusic[path] = Mix_LoadMUS(path.c_str());
            break;
        case sound:
            _sounds[path] = Mix_LoadWAV(path.c_str());
            break;
    }
}


