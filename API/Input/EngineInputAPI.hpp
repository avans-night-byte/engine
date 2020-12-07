#pragma once

#include "../../Engine/Input/Adapter/InputEngineAdapter.hpp"
#include "./InputAPI.hpp"

/**
 * RAII class for managing it's adapter
 */ 
class EngineInputAPI : public InputAPI {
    private:
    InputEngineAdapter* _adapter;
   public:
    EngineInputAPI();
    void getMousePosition(int &x, int &y) const override;
    Input getInput() const override;
    ~EngineInputAPI();
};
