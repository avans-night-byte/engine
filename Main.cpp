#include <stdio.h>
#include <iostream>
#include <cstddef>
#include <string>

#include "./SDL/include/SDL_video.h"
#include "./SDL/include/SDL.h"
#include "./SDL/include/SDL_surface.h"

#include "./Engine/Input/Adapter/SDLInputEngineAdapter.hpp"
#include "./API/Input/EngineInputAPI.hpp"

void gameLoop();

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *window = NULL;

int main(int argc, char *args[])
{
    SDL_Surface *surface = NULL;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        // Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
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
                         SDL_MapRGB(surface->format, 0x00, 0xFF, 0xFF));

            // Update the surface
            SDL_UpdateWindowSurface(window);

            // Start temp game loop for development
            gameLoop();
        }
    }

    return 0;
}

void gameLoop()
{
    // Dependencies, we can inject those later
    SDLInputEngineAdapter inputAdapter;
    EngineInputAPI engineInputAPI;

    // Loopert
    while (true)
    {
        Input i = engineInputAPI.getInput(inputAdapter);

        if (i.keyCode == "Q")
        {
            SDL_DestroyWindow(window);
            SDL_Quit();
            return;
        }
        else
        {
            std::cout << i.keyCode << std::endl;
        }
    }
}