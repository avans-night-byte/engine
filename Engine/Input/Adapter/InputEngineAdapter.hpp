#pragma once

#include <string>

#include "../../../SDL/include/SDL.h"
#include "../../../SDL/include/SDL_events.h"
#include "../Input.hpp"

class InputEngineAdapter
{
public:
    virtual Input getInput() const = 0;
    virtual Input getKeyInput(SDL_Keycode input) const = 0;
    virtual Input getMouseInput(SDL_Event input) const = 0;
    virtual Input getControllerInput(SDL_Event input) const = 0;
    virtual ~InputEngineAdapter() {}

private:
    virtual void closeController() const = 0;
    virtual void openController(int deviceId) const = 0;
};
