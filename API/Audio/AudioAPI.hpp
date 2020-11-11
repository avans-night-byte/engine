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

    static void changeMasterVolume(int volume);

    static void changeChannelVolume(int channel, int volume);

    static void changeMusicVolume(int volume);

    static int getChannelsAverageVolume();

    static int getChannelVolume(int channel);

    static int getMusicVolume();


private:
    SDLAudioEngineAdapter *_adapter;
};