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

    std::vector<std::string> getAudioNames();

    void playFromMemory(const std::string &name);

    static void playFromPath(const std::string &path, AudioType &type);

    void loadInMemory(const std::string &path, AudioType &type);

private:
    SDLAudioEngineAdapter *_adapter;
};