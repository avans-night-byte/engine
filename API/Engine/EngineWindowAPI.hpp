#pragma once

#include "../../Engine/Engine.hpp"
#include "./WindowAPI.hpp"

class EngineWindowAPI : public WindowAPI {
public:
    Engine &_engine;

    EngineWindowAPI();

    ~EngineWindowAPI() = default;

    void initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT) const override;

    void closeWindow() const override;

    void renderCheatMenu(bool &cheatMode) const override;

    void clearCheatMenu() const override;

    bool showCheckBox(const std::string &label, bool *value) const override;

    bool showInputFloat(const std::string &label, float *value) const override;

    bool showInputInt(const std::string &label, int *value) const override;

    bool showInputText(const std::string &label, char *value, int bufferSize) const override;

    [[nodiscard]] bool button(const std::string &label) const override;
};