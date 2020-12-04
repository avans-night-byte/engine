#pragma once

#include <string>

#include "SDL.h"
#include "SDL_events.h"
#include "../Input.hpp"
#include "../../Event.h"

/**
 * Input Adapter for user input.
 */
class InputEngineAdapter
{
public:
    virtual Event<Input>& getInputEvent() = 0;
    virtual Input getInput() = 0;
    virtual ~InputEngineAdapter() {}

private:
    virtual Input getKeyInput(SDL_Keycode input, Uint32 type) const = 0;
    virtual Input getMouseInput(SDL_Event input) = 0;
    virtual Input getControllerInput(SDL_Event input) const = 0;
    virtual Input getControllerMotionInput(SDL_Event input) const = 0;
    virtual void closeController() const = 0;
    virtual void openController(int deviceId) const = 0;
};
