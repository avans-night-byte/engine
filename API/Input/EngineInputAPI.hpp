#include "../../Engine/Input/Adapter/InputEngineAdapter.hpp"
#include "InputAPI.hpp"

class EngineInputAPI : public InputAPI {
   public:
    Input getInput(SDLInputEngineAdapter adapter) const override;
};
