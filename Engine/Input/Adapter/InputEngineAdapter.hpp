#pragma once

#include <string>

#include "../Input.hpp"

class InputEngineAdapter {
   public:
    virtual void update() const = 0;
    virtual void printInput(std::string input) const = 0;
    virtual Input getInput() const = 0;
    virtual ~InputEngineAdapter() {}
};
