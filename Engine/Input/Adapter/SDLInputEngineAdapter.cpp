#include "SDLInputEngineAdapter.hpp"

#include <iostream>
#include <imgui_impl_opengl3.h>
#include <SDL_opengl.h>
#include <imgui_impl_sdl.h>

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
Input SDLInputEngineAdapter::getInput() {
    SDL_Event e;
    Input i = Input{.device = Input::NONE, .x = -1, .y = -1, .keyMap = InputAction{.code = "", .action = ""}};
    while (SDL_PollEvent(&e))
    {
        ImGui_ImplSDL2_ProcessEvent(&e);

        switch (e.type)
        {
        case SDL_KEYDOWN:
            i = getKeyInput(e.key.keysym.sym, e.type);
            _inputEvent(i);
            return i;
        case SDL_KEYUP:
            i = getKeyInput(e.key.keysym.sym, e.type);
            _inputEvent(i);
            return i;
        case SDL_CONTROLLERBUTTONDOWN:
            i = getControllerInput(e);
            _inputEvent(i);
            return i;
        case SDL_CONTROLLERAXISMOTION:
            i = getControllerMotionInput(e);
            _inputEvent(i);
            return i;
        case SDL_MOUSEBUTTONDOWN:
            i = getMouseInput(e);
            _inputEvent(i);
            return i;
        case SDL_CONTROLLERDEVICEADDED:
            openController(e.cdevice.which);
            i = Input{
                    .device = Input::CONTROLLER, .x = -1, .y = -1, .keyMap = InputAction{.code = "CONTROLLER_DEVICE_ADDED", .action = ""}};
            _inputEvent(i);
            return i;
        case SDL_CONTROLLERDEVICEREMOVED:
            closeController();
            i = Input{ .device = Input::CONTROLLER, .x = -1, .y = -1, .keyMap = InputAction{.code = "CONTROLLER_DEVICE_REMOVED", .action = ""}};
            _inputEvent(i);
            return i;
        case SDL_QUIT:
            i = Input{.device = Input::OTHER, .x = -1, .y = -1, .keyMap = InputAction{.code = "QUIT", .action = "QUIT"}};
            _inputEvent(i);
            return i;
        }
    }


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    return i;
}

/**
 * Handles Keymapping for device 0: KEYBOARD.
 * 
 * @param SDL_Keycode keyEvent - SDL KeyEvent that was received.
 * @returns Input{device, x, y, keyMap}
 */
Input SDLInputEngineAdapter::getKeyInput(SDL_Keycode keyEvent, Uint32 type) const
{
    InputAction keyMap = KeyMap::keyboardMap[keyEvent];
    keyMap.type = type;
    return Input{
        .device = Input::KEYBOARD, .x = -1, .y = -1, .keyMap = keyMap};
}

/**
 * Handles Keymapping for device 1: MOUSE.
 * 
 * @param SDL_Event mouseEvent - SDL Event that was received.
 * @returns Input{device, x, y, keyMap}
 */
Input SDLInputEngineAdapter::getMouseInput(SDL_Event mouseEvent)
{
    InputAction keyMap = KeyMap::mouseMap[mouseEvent.button.button];
    float mouseX = mouseEvent.button.x;
    float mouseY = mouseEvent.button.y;

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
    int deadZone = 16000;
    
    float x = 0;
    float y = 0;
    std::string code = "";
    std::string action = "";

    if (controllerEvent.caxis.which == 0) 
    {
        /** Left Joystick */
        if (controllerEvent.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX) /** Left/Right axis */
        {
            if (controllerEvent.caxis.value < -deadZone) /** Left direction */
            {
                x = -1;
                code = "CONTROLLER_LEFT_JOYSTICK_LEFT";
                action = "LEFT";
            }
            else if (controllerEvent.caxis.value > deadZone) /** Right direction */
            {
                x = 1;
                code = "CONTROLLER_LEFT_JOYSTICK_RIGHT";
                action = "RIGHT";
            }
        }
        else if (controllerEvent.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY) /** Up/Down axis */
        {
            if (controllerEvent.caxis.value < -deadZone) /** Up direction */
            {
                y = 1;
                code = "CONTROLLER_LEFT_JOYSTICK_UP";
                action = "UP";
            }
            else if (controllerEvent.caxis.value > deadZone) /** Down direction */
            {
                y = -1;
                code = "CONTROLLER_LEFT_JOYSTICK_DOWN";
                action = "DOWN";
            }
        }

        /** Right Joystick */
        else if (controllerEvent.caxis.axis == SDL_CONTROLLER_AXIS_RIGHTX) /** Left/Right axis */
        {
            if (controllerEvent.caxis.value < -deadZone) /** Left direction */
            {
                x = -1;
                code = "CONTROLLER_RIGHT_JOYSTICK_LEFT";
                action = "CAMERA_LEFT";
            }
            else if (controllerEvent.caxis.value > deadZone) /** Right direction */
            {
                x = 1;
                code = "CONTROLLER_RIGHT_JOYSTICK_RIGHT";
                action = "CAMERA_RIGHT";
            }
        }
        else if (controllerEvent.caxis.axis == SDL_CONTROLLER_AXIS_RIGHTY) /** Up/Down axis */
        {
            if (controllerEvent.caxis.value < -deadZone) /** Up direction */
            {
                y = 1;
                code = "CONTROLLER_RIGHT_JOYSTICK_UP";
                action = "CAMERA_UP";
            }
            else if (controllerEvent.caxis.value > deadZone) /** Down direction */
            {
                y = -1;
                code = "CONTROLLER_RIGHT_JOYSTICK_DOWN";
                action = "CAMERA_DOWN";
            }
        }
        else
        {
            code = "DEBUG_NO_LOG";
            // No change from center
        }
    }

    return Input{.device = Input::CONTROLLER, .x = x, .y = y, .keyMap = InputAction{.code = code, .action = action}};
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

Event<Input>& SDLInputEngineAdapter::getInputEvent() {
    return _inputEvent;
}

void SDLInputEngineAdapter::getMousePosition(int &x, int &y) const {
    SDL_GetMouseState(&x, &y);
}
