#include "./EngineWindowAPI.hpp"

EngineWindowAPI::EngineWindowAPI(Engine &engine) : _engine{engine} {}

void EngineWindowAPI::initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT) const
{
    return Engine::initWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void EngineWindowAPI::closeWindow() const
{
    return Engine::closeWindow();
}

SDL_Renderer *EngineWindowAPI::getRenderer() const
{
    return _engine.getRenderer();
}
