#include "SDLInputEngineAdapter.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

#include <iostream>
#include <string>

#include "../Input.hpp"

void SDLInputEngineAdapter::update() const {}

void SDLInputEngineAdapter::printInput(std::string input) const {
    std::cout << input << std::endl;
}

Input SDLInputEngineAdapter::getInput() const {
    std::cout << "getInput()" << std::endl;

    SDL_Event e;

    while (true) {
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                break;
            }
            // User presses a key
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        printInput("UP");
                    case SDLK_DOWN:
                        printInput("DOWN");
                    case SDLK_LEFT:
                        printInput("LEFT");
                    case SDLK_RIGHT:
                        printInput("RIGHT");
                }

                Input input{.x = 1, .y = 1};

                return input;
            }
        }
    }
}
