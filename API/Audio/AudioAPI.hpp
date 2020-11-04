#include "string"
#include <iostream>
#include <vector>
#include "SDL_mixer.h"
#include "../../Engine/Audio/Adapter/SDLAudioEngineAdapter.hpp"
#include "../../Engine/Audio/SoundType.h"

class AudioAPI {
    AudioAPI();
    ~AudioAPI();



    std::vector<std::string> getAudioFiles();
    void playAudioFile(const std::string& name);
    void loadInMemory(const std::string& path, SoundType type);

private:
    SDLAudioEngineAdapter* _adapter;
};