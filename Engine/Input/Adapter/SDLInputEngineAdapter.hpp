#pragma once

#include <string>
#include "../../SDL/include/SDL_events.h"

#include "InputEngineAdapter.hpp"

class SDLInputEngineAdapter : public InputEngineAdapter {
   public:
    void update() const override;
    void printInput(std::string input) const override;
    Input getInput() const override;
    Input getInput(SDL_Keycode input) const override;
    ~SDLInputEngineAdapter(){};
};
