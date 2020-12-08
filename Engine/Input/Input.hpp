#pragma once

#include "string"
#include <stdint.h>

/**
 * A structure to represent an input from the user.
 */
struct InputAction
{
    std::string code;   /**< Keycode returned form the Keymap */
    std::string action; /**< Action that is mapped to the keycode */
    uint32_t type;
};

/**
 * A structure to represent an input from the Engine.
 */
struct Input
{
    enum device /** Device the input was received from */
    {
        NONE = -1,      /**< Device -1: No Input */
        KEYBOARD = 0,   /**< Device 0: Keyboard */
        MOUSE = 1,      /**< Device 1: Mouse */
        CONTROLLER = 2, /**< Device 2: Controller */
        OTHER = 3       /**< Device 3: Other (e.g. the console) */
    } device;
    float x;              /**< X coordinate within the window */
    float y;              /**< Y coordinate within the window */
    InputAction keyMap; /**< InputAction struct containing code and action */
};
