#pragma once

#include <SDL_render.h>

class Engine {
public:
    static void initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT);

    static void closeWindow();

    static SDL_Renderer *getRenderer();
};
