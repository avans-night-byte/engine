#pragma once

#include <string>

#include "SDL.h"
#include "SDL_events.h"
#include "../Input.hpp"

/**
 * Input Adapter for user input.
 */
class InputEngineAdapter
{
public:
    virtual Input getInput() const = 0;
    virtual ~InputEngineAdapter() {}
    virtual void getMousePosition(int &x, int &y) const = 0;
private:
    virtual Input getKeyInput(SDL_Keycode input, Uint32 type) const = 0;
    virtual Input getMouseInput(SDL_Event input) const = 0;
    virtual Input getControllerInput(SDL_Event input) const = 0;
    virtual Input getControllerMotionInput(SDL_Event input) const = 0;
    virtual void closeController() const = 0;
    virtual void openController(int deviceId) const = 0;

};
