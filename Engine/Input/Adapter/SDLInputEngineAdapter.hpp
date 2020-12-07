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
    Input getInput() const override;
    Input getKeyInput(SDL_Keycode input, Uint32 type = SDL_KEYDOWN) const override;
    Input getMouseInput(SDL_Event input) const override;
    Input getControllerInput(SDL_Event input) const override;
    Input getControllerMotionInput(SDL_Event input) const override;
    void getMousePosition(int &x, int &y) const override;

    ~SDLInputEngineAdapter(){};

private:
    void openController(int deviceId) const override;
    void closeController() const override;
};
