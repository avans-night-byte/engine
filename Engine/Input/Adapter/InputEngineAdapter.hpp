#pragma once

#include <string>
#include "../../SDL/include/SDL_events.h"

#include "../Input.hpp"

class InputEngineAdapter {
   public:
    virtual void update() const = 0;
    virtual void printInput(std::string input) const = 0;
    virtual void getInput() const = 0;
    virtual Input getInput(SDL_Keycode input) const = 0;
    virtual ~InputEngineAdapter() {}
};
