#include "SDLInputEngineAdapter.hpp"

#include <iostream>

#include "../../../SDL/include/SDL_events.h"
#include "../Input.hpp"
#include "../KeyMap.hpp"

void debugLog(Input i);

SDL_GameController *gameController;

Input SDLInputEngineAdapter::getInput() const
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
        case SDL_KEYDOWN:
            return getKeyInput(e.key.keysym.sym);
        case SDL_CONTROLLERBUTTONDOWN:
            return getControllerInput(e);
        case SDL_MOUSEBUTTONDOWN:
            return getMouseInput(e);

        case SDL_CONTROLLERDEVICEADDED:
            openController(e.cdevice.which);
            break;
        case SDL_CONTROLLERDEVICEREMOVED:
            closeController();
            break;
        }
    }
}

Input SDLInputEngineAdapter::getKeyInput(SDL_Keycode keyEvent) const
{
    InputAction keyMap = KeyMap::keyboardMap[keyEvent];
    return Input{
        .device = Input::KEYBOARD, .x = -1, .y = -1, .keyMap = keyMap};
}

Input SDLInputEngineAdapter::getMouseInput(SDL_Event mouseEvent) const
{
    InputAction keyMap = KeyMap::mouseMap[mouseEvent.button.button];
    int mouseX = mouseEvent.button.x;
    int mouseY = mouseEvent.button.y;

    return Input{
        .device = Input::MOUSE, .x = mouseX, .y = mouseY, .keyMap = keyMap};
}

Input SDLInputEngineAdapter::getControllerInput(SDL_Event controllerEvent) const
{
    InputAction keyMap = KeyMap::controllerMap[controllerEvent.cbutton.button];
    return Input{.device = Input::CONTROLLER, .x = -1, .y = -1, .keyMap = keyMap};
}

void SDLInputEngineAdapter::openController(int deviceId) const
{
    if (SDL_IsGameController(deviceId))
    {
        gameController = SDL_GameControllerOpen(deviceId);
        std::cout << "Controller Connected: " << SDL_GameControllerName(gameController) << std::endl;
    }
    else
    {
        std::cout << "Unsupported Controller: " << SDL_GameControllerName(gameController) << std::endl;
    }
}

void SDLInputEngineAdapter::closeController() const
{
    std::cout << "Controller Disconnected" << std::endl;
    SDL_GameControllerClose(gameController);
    gameController == NULL;
}
