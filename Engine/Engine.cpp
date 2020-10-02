#include <iostream>

#include "Engine.hpp"

// Dependencies
#include "../SDL/include/SDL.h"
#include "../SDL/include/SDL_surface.h"
#include "../SDL/include/SDL_video.h"

// Variables
SDL_Window *window = NULL;

/**
 * Initialize the game window
 * 
 * Stores a SDL_Window pointer in the Engine class.
 * 
 * @param SCREEN_WIDTH The width of the window.
 * @param SCREEN_HEIGHT The height of the window.
 **/
void Engine::initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
  SDL_Surface *surface = NULL;

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER) < 0)
  {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  }
  else
  {

    // Create window
    window = SDL_CreateWindow("Tutorial", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
      printf("Window could not be created! SDL_Error: %s\n",
             SDL_GetError());
    }
    else
    {
      // Get window surface
      surface = SDL_GetWindowSurface(window);

      // Fill the surface white
      SDL_FillRect(surface, NULL,
                   SDL_MapRGB(surface->format, 0x00, 0x00, 0xFF));

      // Update the surface
      SDL_UpdateWindowSurface(window);
    }
  }
}

/**
 * Close the game window
 * 
 * Clears the SDL_Window pointer in the Engine class and calls SDL_DestroyWindow & SDL_Quit.
 **/
void Engine::closeWindow()
{
  window = NULL;
  SDL_DestroyWindow(window);
  SDL_Quit();
}