#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

#include <cstddef>

#include "Input/Adapter/SDLInputEngineAdapter.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
    SDL_Window* window = NULL;
    SDL_Surface* surface = NULL;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        // Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n",
                   SDL_GetError());
        } else {
            // Get window surface
            surface = SDL_GetWindowSurface(window);

            // Fill the surface white
            SDL_FillRect(surface, NULL,
                         SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

            // Update the surface
            SDL_UpdateWindowSurface(window);

            // Get Input
            SDLInputEngineAdapter adapter;
            adapter.getInput();
        }
    }

    // Destroy window
    // SDL_DestroyWindow(window);

    // Quit SDL subsystems
    // SDL_Quit();

    return 0;
}
