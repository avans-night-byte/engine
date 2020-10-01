#include <stdio.h>

#include <cstddef>
#include <iostream>
#include <string>

#include "./API/Input/EngineInputAPI.hpp"
#include "./Engine/Input/Adapter/SDLInputEngineAdapter.hpp"
#include "./SDL/include/SDL.h"
#include "./SDL/include/SDL_surface.h"
#include "./SDL/include/SDL_video.h"

void gameLoop();
void debugLog(Input);

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *window = NULL;

int main(int argc, char *args[])
{
    SDL_Surface *surface = NULL;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {

        // Game Controller Mappings
        SDL_GameControllerAddMappingsFromFile("gamecontrollers.txt");

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
                         SDL_MapRGB(surface->format, 0x00, 0x00, 0xFF));

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

    // Initialize controllers
    engineInputAPI.initializeControllers(inputAdapter);

    while (true)
    {
        Input i = engineInputAPI.getInput(inputAdapter);

        debugLog(i);

        if (i.keyCode == "Q")
        {
            engineInputAPI.closeController(inputAdapter);
            SDL_DestroyWindow(window);
            SDL_Quit();
            return;
        }
    }
}

void debugLog(Input i)
{
    std::cout << std::endl;
    std::cout << "device: " << i.device << std::endl;
    std::cout << "keyCode: " << i.keyCode << std::endl;
    std::cout << "x: " << i.x << std::endl;
    std::cout << "y: " << i.y << std::endl;
}
