#pragma once

#include "../../Engine/Engine.hpp"
#include "./WindowAPI.hpp"

class EngineWindowAPI : public WindowAPI
{
public:
    Engine &_engine;

     EngineWindowAPI();
    ~EngineWindowAPI() = default;

    void initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT) const override;
    void closeWindow() const override;

    void renderImGui(bool &cheatMode) const override;
};
