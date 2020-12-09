#pragma once

#include <string>

#include "SDL_events.h"
#include "InputEngineAdapter.hpp"


/**
 * SDL Compatible Input Adapter for user input.
 */

class SDLInputEngineAdapter : public InputEngineAdapter
{
public:
    [[nodiscard]] Event<Input>& getInputEvent() override;
    [[nodiscard]] Input getInput() override;
    [[nodiscard]] Input getKeyInput(SDL_Keycode input, Uint32 type = SDL_KEYDOWN) const override;
    [[nodiscard]] Input getMouseInput(SDL_Event input) override;
    [[nodiscard]] Input getControllerInput(SDL_Event input) const override;
    [[nodiscard]] Input getControllerMotionInput(SDL_Event input) const override;
    ~SDLInputEngineAdapter() override= default;
    void getMousePosition(int &x, int &y) const override;

private:
    Event<Input> _inputEvent;
    void openController(int deviceId) const override;
    void closeController() const override;
};
