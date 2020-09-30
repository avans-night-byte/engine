#include "SDLInputEngineAdapter.hpp"

#include "../../SDL/include/SDL_events.h"

#include "../Input.hpp"
#include "../KeyMap.hpp"

#include <iostream>

void debugLog(Input i);

Input SDLInputEngineAdapter::getInput() const
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_KEYDOWN)
        {
            return getKeyInput(e.key.keysym.sym);
        }

        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            return getMouseInput(e);
        }
    }
}

Input SDLInputEngineAdapter::getKeyInput(SDL_Keycode keyEvent) const
{
    std::string keyCode = KeyMap::keyboardMap[keyEvent];
    return Input{.device = Input::KEYBOARD, .x = -1, .y = -1, .keyCode = keyCode};
}

Input SDLInputEngineAdapter::getMouseInput(SDL_Event mouseEvent) const
{

    std::string keyCode = KeyMap::mouseMap[mouseEvent.button.button];
    int mouseX = mouseEvent.button.x;
    int mouseY = mouseEvent.button.y;

    return Input{.device = Input::MOUSE, .x = mouseX, .y = mouseY, .keyCode = keyCode};
}