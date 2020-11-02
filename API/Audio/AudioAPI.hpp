#include "string"

using namespace std;

class AudioAPI {
    virtual void loadMusic(string fileLocation, int musicId) = 0;
    virtual void loadSoundEffect(string fileLocation, int trackId) = 0;

    virtual void playMusic(int musicId) = 0;
    virtual void stopMusic(int musicId) = 0;

    virtual void playAudio(int trackId) = 0;
};