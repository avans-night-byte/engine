#include "../../Engine/Input/Adapter/SDLInputEngineAdapter.hpp"
#include "../../Engine/Input/Input.hpp"

class InputAPI {
   public:
    virtual Input getInput(SDLInputEngineAdapter adapter) const = 0;
    virtual void initializeControllers(SDLInputEngineAdapter adapter) const = 0;
    virtual void closeController(SDLInputEngineAdapter adapter) const = 0;
    virtual ~InputAPI() {}
};
