#include <iostream>
#include "./Engine.hpp"
#include "Rendering/TextureManager.hpp"


// Dependencies
#include "SDL.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include "SDL_render.h"
#include <SDL_ttf.h>


// Variables
SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;


/**
 * Initialize the game window
 * 
 * Stores a SDL_Window pointer in the Engine class.
 * 
 * @param SCREEN_WIDTH The width of the window.
 * @param SCREEN_HEIGHT The height of the window.
 **/
void Engine::initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT) {

    SDL_Surface *surface = nullptr;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER | SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {

        // Create window
        window = SDL_CreateWindow("Tutorial", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n",
                   SDL_GetError());
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
            TTF_Init();
        }

    }
}

SDL_Renderer *Engine::getRenderer() {
    return renderer;
}

/**
 * Close the game window
 * 
 * Clears the SDL_Window pointer in the Engine class and calls SDL_DestroyWindow & SDL_Quit.
 **/
void Engine::closeWindow() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


// Singleton
Engine *Engine::instance_{nullptr};
std::mutex Engine::mutex_;


Engine *Engine::getInstance() {
    std::lock_guard<std::mutex> lock(mutex_);

    if(instance_ == nullptr) {
        instance_ = new Engine();
    }

    return instance_;
}

TextureManager *Engine::getTextureManager() {
    return TextureManager::GetInstance();
}
