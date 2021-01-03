#pragma once

#include <vector>
#include "../../Engine/Audio/Adapter/SDLAudioEngineAdapter.hpp"
#include "../../Engine/Audio/AudioType.h"

class AudioAPI{
public:
   virtual std::vector<std::string> getAudioNames() = 0;

   virtual void playFromMemory(const std::string &name) = 0;

   virtual void playFromPath(const std::string &path, AudioType &type) = 0;

   virtual void loadInMemory(const std::string &path, const std::string &name, AudioType type) = 0;

   virtual void stopAudio() = 0;

   virtual void stopMusic() = 0;

   virtual void stopSound(int channel) = 0;

   virtual void stopSounds() = 0;

   virtual void changeMasterVolume(int volume) = 0;

   virtual void changeChannelVolume(int channel, int volume) = 0;

   virtual void changeMusicVolume(int volume) = 0;

   virtual int getChannelsAverageVolume() = 0;

   virtual int getChannelVolume(int channel) = 0;

   virtual int getMusicVolume() = 0;

   virtual void toggleMusic() = 0;

   virtual void toggleSound(int channel) = 0;

   virtual void toggleSounds() = 0;

};
