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

Input SDLInputEngineAdapter::getKeyInput(SDL_Keycode keyEvent) const
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
        keyCode = "Unsupported";
        std::cout << "Unsupported Operation";
    }

    // Return new input
    return Input{.device = Input::KEYBOARD, .x = -1, .y = -1, .keyCode = keyCode};
}

Input SDLInputEngineAdapter::getMouseInput(SDL_Event mouseEvent) const
{

    int mouseX, mouseY;
    std::string keyCode;

    switch (mouseEvent.button.button)
    {
    case SDL_BUTTON_LEFT:
        keyCode = "MOUSE_BUTTON_LEFT";
        break;
    case SDL_BUTTON_RIGHT:
        keyCode = "MOUSE_BUTTON_RIGHT";
        break;
    default:
        std::cout << "Unsupported Operation";
        break;
    }

    mouseX = mouseEvent.button.x;
    mouseY = mouseEvent.button.y;

    // Return new input
    return Input{.device = Input::MOUSE, .x = mouseX, .y = mouseY, .keyCode = keyCode};
}

Input SDLInputEngineAdapter::getInput() const
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_KEYDOWN)
            return getKeyInput(e.key.keysym.sym);
        if (e.type == SDL_MOUSEBUTTONDOWN)
            return getMouseInput(e);
    }
}
