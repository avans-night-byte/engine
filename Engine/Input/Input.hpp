#pragma once

/**
 * A structure to represent an input from the user.
 */
struct InputAction
{
    std::string code;   /** Keycode returned form the Keymap */
    std::string action; /** Action that is mapped to the keycode */
};

/**
 * A structure to represent an input from the Engine.
 */
struct Input
{
    enum device         /** Device the input was received from */
    {
        KEYBOARD = 0,   /** Device 0: Keyboard */
        MOUSE = 1,      /** Device 1: Mouse */
        CONTROLLER = 2  /** Device 2: Controller */
    } device;
    int x;              /** X coordinate within the window */
    int y;              /** Y coordinate within the window */
    InputAction keyMap; /** InputAction struct containing code and action */
};
