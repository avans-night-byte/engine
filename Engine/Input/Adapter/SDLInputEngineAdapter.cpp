#include "SDLInputEngineAdapter.hpp"

#include <iostream>

#include "../../../SDL/include/SDL_events.h"
#include "../Input.hpp"
#include "../KeyMap.hpp"

void debugLog(Input i);

Input SDLInputEngineAdapter::getInput()
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_KEYDOWN)
            return getKeyInput(e.key.keysym.sym);
        if (e.type == SDL_MOUSEBUTTONDOWN)
            return getMouseInput(e);
        if (e.type == SDL_CONTROLLERBUTTONDOWN)
            return getControllerInput(e);
    }
}

Input SDLInputEngineAdapter::getKeyInput(SDL_Keycode keyEvent) const
{
    std::string keyCode = KeyMap::keyboardMap[keyEvent];
    return Input{
        .device = Input::KEYBOARD, .x = -1, .y = -1, .keyCode = keyCode};
}

Input SDLInputEngineAdapter::getMouseInput(SDL_Event mouseEvent) const
{
    std::string keyCode = KeyMap::mouseMap[mouseEvent.button.button];
    int mouseX = mouseEvent.button.x;
    int mouseY = mouseEvent.button.y;

    return Input{
        .device = Input::MOUSE, .x = mouseX, .y = mouseY, .keyCode = keyCode};
}

Input SDLInputEngineAdapter::getControllerInput(SDL_Event controllerEvent)
{
    std::string keyCode = KeyMap::controllerMap[controllerEvent.cbutton.button];
    return Input{.device = Input::CONTROLLER, .x = -1, .y = -1, .keyCode = keyCode};
}

void SDLInputEngineAdapter::initializeControllers()
{
    if (SDL_NumJoysticks() < 1)
    {
        std::cout << "There are no controllers plugged in" << std::endl;
    }
    else
    {
        for (int i = 0; i < SDL_NumJoysticks(); i++)
        {
            if (SDL_IsGameController(i))
            {
                gameController = SDL_GameControllerOpen(i);
                std::cout << "Initialized controllers:" << SDL_GameControllerName(gameController) << std::endl;
                break;
            }
        }
    }
}

void SDLInputEngineAdapter::closeController()
{
    SDL_GameControllerClose(gameController);
}
