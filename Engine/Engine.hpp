#pragma once

#include <SDL_render.h>
#include <mutex>

class TextureManager;

class Engine {
private:
    static Engine *instance_;
    static std::mutex mutex_;

protected:
    Engine() = default;
    ~Engine() = default;

public:
    Engine(Engine &other) = delete;

    void operator=(const Engine&) = delete;

    static Engine *getInstance();

public:
    static void initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT);

    static void closeWindow();

    static SDL_Renderer *getRenderer();

    TextureManager *getTextureManager();
};
