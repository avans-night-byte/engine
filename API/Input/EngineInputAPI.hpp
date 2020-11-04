#include "../../Engine/Input/Adapter/InputEngineAdapter.hpp"
#include "./InputAPI.hpp"

/**
 * RAII class for managing it's adapter
 */ 
class EngineInputAPI : public InputAPI {
    private:
    InputEngineAdapter* _adapter;
   public:
    EngineInputAPI(InputEngineAdapter* adapter);
    Input getInput() const override;
    ~EngineInputAPI();
};
