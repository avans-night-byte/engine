#include "../../Engine/Engine.hpp"
#include "./WindowAPI.hpp"

/**
 * RAII class for managing the engine
 */
class EngineWindowAPI : public WindowAPI
{
public:
    Engine *_engine;

    EngineWindowAPI(Engine *engine);
    ~EngineWindowAPI();

    void initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT) const override;
    void closeWindow() const override;
    SDL_Renderer *getRenderer() const override;
};
