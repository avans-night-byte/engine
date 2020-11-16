#include "../../Engine/Input/Adapter/SDLInputEngineAdapter.hpp"
#include "../../Engine/Input/Input.hpp"

class InputAPI {
   public:
    virtual Input getInput() const = 0;
    virtual ~InputAPI() {}
};
