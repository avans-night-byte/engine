#pragma once

#include "../../Engine/Input/Adapter/InputEngineAdapter.hpp"
#include "./InputAPI.hpp"

enum KeyType {
    None = 0,
    KeyDown = 0x300,
    KeyUp
};

/**
 * RAII class for managing it's adapter
 */ 
class EngineInputAPI : public InputAPI {
    private:
    InputEngineAdapter* _adapter;
   public:
    EngineInputAPI();
    [[nodiscard]] Input getInput() const override;
    Event<Input>& getInputEvent() override;
    ~EngineInputAPI() override;
    void getMousePosition(int &x, int &y) const override;

};
