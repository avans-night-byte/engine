#pragma once

#include <string>

#include "../../../SDL/include/SDL_events.h"
#include "InputEngineAdapter.hpp"

class SDLInputEngineAdapter : public InputEngineAdapter {
   public:
    SDL_Joystick* gameController;

    Input getInput() override;
    Input getKeyInput(SDL_Keycode input) const override;
    Input getMouseInput(SDL_Event input) const override;
    Input getControllerInput(SDL_Event input) override;
    void initializeControllers() override;
    void closeController() override;
    ~SDLInputEngineAdapter(){};
};
