#include "../../Engine/Input/Adapter/SDLInputEngineAdapter.hpp"
#include "../../Engine/Input/Input.hpp"

class InputAPI {
   public:
    [[nodiscard]] virtual Input getInput() const = 0;
    virtual Event<Input>& getInputEvent() = 0;
    virtual ~InputAPI() = default;
};
