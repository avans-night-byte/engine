#include "SDLInputEngineAdapter.hpp"

#include <iostream>

#include "SDL_events.h"
#include "../Input.hpp"
#include "../KeyMap.hpp"

SDL_GameController *gameController;

/**
 * Function that gets called every iteration from the gameLoop to check for input from the user.
 * Delegates functionality for every device to underlying methods.
 * 
 * Polled events:
 * - SDL_KEYDOWN, returns Input struct
 * - SDL_MOUSEBUTTONDOWN, returns Input struct
 * - SDL_MOUSEBUTTONDOWN, returns Input struct
 * - SDL_CONTROLLERDEVICEADDED, void
 * - SDL_CONTROLLERDEVICEREMOVED, void
 * - SDL_QUIT, returns Input struct
 * 
 * @returns Input{device, x, y, keyMap}
 */
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
        case SDL_CONTROLLERAXISMOTION:
            return getControllerMotionInput(e);
        case SDL_MOUSEBUTTONDOWN:
            return getMouseInput(e);
        case SDL_CONTROLLERDEVICEADDED:
            openController(e.cdevice.which);
            return Input{
                .device = Input::CONTROLLER, .x = -1, .y = -1, .keyMap = InputAction{.code = "CONTROLLER_DEVICE_ADDED", .action = ""}};
        case SDL_CONTROLLERDEVICEREMOVED:
            closeController();
            return Input{ .device = Input::CONTROLLER, .x = -1, .y = -1, .keyMap = InputAction{.code = "CONTROLLER_DEVICE_REMOVED", .action = ""}};
        case SDL_QUIT:
            return Input{.device = Input::OTHER, .x = -1, .y = -1, .keyMap = InputAction{.code = "QUIT", .action = "QUIT"}};
        }
    }

    return Input{.device = Input::NONE, .x = -1, .y = -1, .keyMap = InputAction{.code = "", .action = ""}};
}

/**
 * Handles Keymapping for device 0: KEYBOARD.
 * 
 * @param SDL_Keycode keyEvent - SDL KeyEvent that was received.
 * @returns Input{device, x, y, keyMap}
 */
Input SDLInputEngineAdapter::getKeyInput(SDL_Keycode keyEvent) const
{
    InputAction keyMap = KeyMap::keyboardMap[keyEvent];
    return Input{
        .device = Input::KEYBOARD, .x = -1, .y = -1, .keyMap = keyMap};
}

/**
 * Handles Keymapping for device 1: MOUSE.
 * 
 * @param SDL_Event mouseEvent - SDL Event that was received.
 * @returns Input{device, x, y, keyMap}
 */
Input SDLInputEngineAdapter::getMouseInput(SDL_Event mouseEvent) const
{
    InputAction keyMap = KeyMap::mouseMap[mouseEvent.button.button];
    int mouseX = mouseEvent.button.x;
    int mouseY = mouseEvent.button.y;

    return Input{
        .device = Input::MOUSE, .x = mouseX, .y = mouseY, .keyMap = keyMap};
}

/**
 * Handles Keymapping for device 2: CONTROLLER.
 * 
 * @param SDL_Event controllerEvent - SDL Event that was received.
 * @returns Input{device, x, y, keyMap}
 */
Input SDLInputEngineAdapter::getControllerInput(SDL_Event controllerEvent) const
{
    InputAction keyMap = KeyMap::controllerMap[controllerEvent.cbutton.button];
    return Input{.device = Input::CONTROLLER, .x = -1, .y = -1, .keyMap = keyMap};
}

/**
 * Handles Axis motion events for the controller. 
 * Note: At this time this only logs which axis was moved.
 * 
 * @param SDL_Event controllerEvent - SDL Event that was received.
 * @returns Input{device, x, y, keyMap}
 */
Input SDLInputEngineAdapter::getControllerMotionInput(SDL_Event controllerEvent) const
{

    std::string code = "";

    if (controllerEvent.caxis.which == 0)
    {
        if (controllerEvent.caxis.axis == 0)
        {
            code = "WHICH_0_AXIS_0";
        }
        else if (controllerEvent.caxis.axis == 1)
        {
            code = "WHICH_1_AXIS_1";
        }
        else
        {
            code = "DEBUG_NO_LOG";
            // No change from center
        }
    }

    return Input{.device = Input::CONTROLLER, .x = -1, .y = -1, .keyMap = InputAction{.code = code}};
}

/**
 * Initialises a new controller device. The controller is assigned to *gameController within the SDLInputAdapter
 * 
 * @param int deviceId - The index of the new controller.
 */
void SDLInputEngineAdapter::openController(int deviceId) const
{
    if (SDL_IsGameController(deviceId))
    {
        gameController = NULL;
        gameController = SDL_GameControllerOpen(deviceId);
        std::cout << "Controller Connected: " << SDL_GameControllerName(gameController) << std::endl;
    }
    else
    {
        std::cout << "Unsupported Controller: " << SDL_GameControllerName(gameController) << std::endl;
    }
}

/**
 * Sets *gameController in SDLInputAdapter to NULL and calls SDL_GameControllerClose
 */
void SDLInputEngineAdapter::closeController() const
{
    std::cout << "Controller Disconnected" << std::endl;
    SDL_GameControllerClose(gameController);
    gameController == NULL;
}
