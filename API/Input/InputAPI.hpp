#include "../../Engine/Input/Adapter/SDLInputEngineAdapter.hpp"
#include "../../Engine/Input/Input.hpp"

class InputAPI {
   public:
    virtual Input getInput() const = 0;
    virtual ~InputAPI() {}
    virtual void getMousePosition(int &x, int &y) const = 0;
};
