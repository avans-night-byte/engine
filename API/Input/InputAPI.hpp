#include "../../Engine/Input/Input.hpp"
#include "../../Engine/Input/Adapter/SDLInputEngineAdapter.hpp"

class InputAPI
{
public:
    virtual Input getInput(SDLInputEngineAdapter adapter) const = 0;
    virtual ~InputAPI() {}
};
