#pragma once

#include "../../Engine/Engine.hpp"
#include "./WindowAPI.hpp"

/**
 * RAII class for managing the _engine
 */
class EngineWindowAPI : public WindowAPI
{
public:
    Engine &_engine;

     EngineWindowAPI();
    ~EngineWindowAPI() = default;

    void initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT) const override;
    void closeWindow() const override;
    [[nodiscard]] SDL_Renderer *getRenderer() const override;
};
