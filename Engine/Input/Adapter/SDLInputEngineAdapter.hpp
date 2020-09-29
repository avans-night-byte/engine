#include <string>

#include "InputEngineAdapter.hpp"

class SDLInputEngineAdapter : public InputEngineAdapter {
   public:
    void update() const override;
    void printInput(std::string input) const override;
    Input getInput() const override;
    ~SDLInputEngineAdapter(){};
};
