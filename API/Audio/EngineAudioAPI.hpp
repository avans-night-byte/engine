#include "AudioAPI.hpp"

class EngineAudioAPI : public AudioAPI
{
public:
    void playAudio(int trackId) override;

    void loadMusic(string fileLocation, int musicId) override;
    void loadSoundEffect(string fileLocation, int trackId) override;

    void playMusic(int musicId) override;
    void stopMusic(int musicId) override;
};