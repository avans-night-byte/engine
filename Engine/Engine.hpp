#pragma once
#include <SDL_render.h>

class Engine
{
public:
  void initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT);
  void closeWindow();
  SDL_Renderer *getRenderer();
};
