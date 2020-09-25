#pragma once

#include "input.hpp"

class InputEngine {
   public:
    virtual void update() const = 0;
    virtual struct input getInput() const = 0;
    virtual ~InputEngine();
};
