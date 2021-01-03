#pragma once

#include "string"
#include <vector>
#include <memory>

#include "SDL_mixer.h"

#include "../../Engine/Audio/Adapter/SDLAudioEngineAdapter.hpp"
#include "../../Engine/Audio/AudioType.h"
#include "AudioAPI.h"

class EngineAudioAPI : public AudioAPI {

public:
    ~EngineAudioAPI() = default;

    EngineAudioAPI();

    EngineAudioAPI(const EngineAudioAPI &other) = delete;

    EngineAudioAPI(EngineAudioAPI &&other) noexcept = default;

    EngineAudioAPI &operator=(const EngineAudioAPI &other) = delete;

    EngineAudioAPI &operator=(EngineAudioAPI &&other) noexcept = default;

    std::vector<std::string> getAudioNames() override;

    void playFromMemory(const std::string &name) override;

    void playFromPath(const std::string &path, AudioType &type) override;

    void loadInMemory(const std::string &path, const std::string &name, AudioType type) override;

    void stopAudio() override;

    void stopMusic() override;

    void stopSound(int channel) override;

    void stopSounds() override;

    void changeMasterVolume(int volume) override;

    void changeChannelVolume(int channel, int volume) override;

    void changeMusicVolume(int volume) override;

    int getChannelsAverageVolume() override;

    int getChannelVolume(int channel) override;

    int getMusicVolume() override;

    void toggleMusic() override;

    void toggleSound(int channel) override;

    void toggleSounds() override;

private:
    SDLAudioEngineAdapter &_adapter;
};