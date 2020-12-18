#pragma once

#include <SDL_render.h>
#include <mutex>
#include <memory>

class TextureManager;

class EngineRenderingAdapter;

class Engine {
private:
    static Engine *instance_;
    static std::mutex mutex_;

    std::unique_ptr<EngineRenderingAdapter> _renderingAdapter;

protected:
    Engine() = default;

public:
    ~Engine() = default;
    Engine(Engine &other) = delete;

    void operator=(const Engine &) = delete;

    static Engine *getInstance();

public:
    void initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT);

    void closeWindow();

    [[nodiscard]] EngineRenderingAdapter &getRenderingAdapter();
};
