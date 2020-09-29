#include "SDLInputEngineAdapter.hpp"

#include "../../SDL/include/SDL.h"
#include "../../SDL/include/SDL_events.h"

#include <iostream>
#include <string>

#include "../Input.hpp"

void SDLInputEngineAdapter::update() const {}

void SDLInputEngineAdapter::printInput(std::string input) const
{
    std::cout << input << std::endl;
}

Input SDLInputEngineAdapter::getInput(SDL_Keycode keyEvent) const
{

    std::string keyCode;

    switch (keyEvent)
    {
    case SDLK_UP:
        keyCode = "UP";
        break;
    case SDLK_DOWN:
        keyCode = "DOWN";
        break;
    case SDLK_LEFT:
        keyCode = "LEFT";
        break;
    case SDLK_RIGHT:
        keyCode = "RIGHT";
        break;
    case SDLK_SPACE:
        keyCode = "SPACE";
        break;
    case SDLK_e:
        keyCode = "E";
        break;
    case SDLK_q:
        keyCode = "Q";
        break;
    default:
        std::cout << "Unsupported Operation";
        // throw std::runtime_error("Unsupported Operation");
    }

    // Return new input
    return Input{.x = 1, .y = 1, .keyCode = keyCode};
}

Input SDLInputEngineAdapter::getInput() const
{
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_KEYDOWN)
        {
            return getInput(e.key.keysym.sym);
        }
    }
}
