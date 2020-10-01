#include "../../Engine/Input/Adapter/InputEngineAdapter.hpp"
#include "InputAPI.hpp"

class EngineInputAPI : public InputAPI {
   public:
    Input getInput(SDLInputEngineAdapter adapter) const override;
    void initializeControllers(SDLInputEngineAdapter adapter) const override;
    void closeController(SDLInputEngineAdapter adapter) const override;
};
