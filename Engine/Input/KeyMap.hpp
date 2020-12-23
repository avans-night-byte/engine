#include <map>
#include <string>

#include "SDL_events.h"

/**
 *  Contains mappings for mouse, controller and keyboard.
 *  A map contains a SDL_KeyCode and an InputAction struct.
 */
class KeyMap {
public:
    /** Keymap for device 1: mouse */
    inline static std::map<SDL_Keycode, InputAction> mouseMap = {
            {SDL_BUTTON_LEFT,  InputAction{.code = "MOUSE_BUTTON_LEFT", .action = "CLICK_LEFT"}},
            {SDL_BUTTON_RIGHT, InputAction{.code = "MOUSE_BUTTON_RIGHT", .action = "CLICK_RIGHT"}},
    };

    /** Keymap for device 2: controller */
    inline static std::map<SDL_Keycode, InputAction> controllerMap = {
            {SDL_CONTROLLER_BUTTON_A,             InputAction{.code = "CONTROLLER_BUTTON_A", .action = "JUMP"}},
            {SDL_CONTROLLER_BUTTON_B,             InputAction{.code = "CONTROLLER_BUTTON_B", .action = ""}},
            {SDL_CONTROLLER_BUTTON_X,             InputAction{.code = "CONTROLLER_BUTTON_X", .action = ""}},
            {SDL_CONTROLLER_BUTTON_Y,             InputAction{.code = "CONTROLLER_BUTTON_Y", .action = ""}},
            {SDL_CONTROLLER_BUTTON_LEFTSHOULDER,  InputAction{.code = "CONTROLLER_BUTTON_LB", .action = ""}},
            {SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, InputAction{.code = "CONTROLLER_BUTTON_RB", .action = ""}},
            {SDL_CONTROLLER_BUTTON_BACK,          InputAction{.code = "CONTROLLER_BUTTON_SELECT", .action = "QUIT"}},
            {SDL_CONTROLLER_BUTTON_START,         InputAction{.code = "CONTROLLER_BUTTON_START", .action = ""}},
            {SDL_CONTROLLER_BUTTON_LEFTSTICK,     InputAction{.code = "CONTROLLER_BUTTON_L3", .action = ""}},
            {SDL_CONTROLLER_BUTTON_RIGHTSTICK,    InputAction{.code = "CONTROLLER_BUTTON_R3", .action = ""}},
            {SDL_CONTROLLER_BUTTON_DPAD_UP,       InputAction{.code = "CONTOLLER_DPAD_UP", .action = "UP"}},
            {SDL_CONTROLLER_BUTTON_DPAD_DOWN,     InputAction{.code = "CONTOLLER_DPAD_DOWN", .action = "DOWN"}},
            {SDL_CONTROLLER_BUTTON_DPAD_LEFT,     InputAction{.code = "CONTOLLER_DPAD_LEFT", .action = "LEFT"}},
            {SDL_CONTROLLER_BUTTON_DPAD_RIGHT,    InputAction{.code = "CONTOLLER_DPAD_RIGHT", .action = "RIGHT"}},
    };

    /** Keymap for device 0: keyboard */
    inline static std::map<SDL_Keycode, InputAction> keyboardMap = {
            {SDLK_1,            InputAction{.code = "1", .action = "1"}},
            {SDLK_2,            InputAction{.code = "2", .action = "2"}},
            {SDLK_3,            InputAction{.code = "3", .action = "3"}},
            {SDLK_UP,           InputAction{.code = "UP", .action = "UP"}},
            {SDLK_DOWN,         InputAction{.code = "DOWN", .action = "DOWN"}},
            {SDLK_LEFT,         InputAction{.code = "LEFT", .action = "LEFT"}},
            {SDLK_RIGHT,        InputAction{.code = "RIGHT", .action = "RIGHT"}},
            {SDLK_w,            InputAction{.code = "W", .action = "UP"}},
            {SDLK_s,            InputAction{.code = "S", .action = "DOWN"}},
            {SDLK_a,            InputAction{.code = "A", .action = "LEFT"}},
            {SDLK_d,            InputAction{.code = "D", .action = "RIGHT"}},
            {SDLK_e,            InputAction{.code = "E", .action = "INTERACT"}},
            {SDLK_SPACE,        InputAction{.code = "SPACE", .action = "JUMP"}},
            {SDLK_i,            InputAction{.code = "I", .action = "INVENTORY"}},
            {SDLK_q,            InputAction{.code = "Q", .action = "QUIT"}},
            {SDLK_BACKSLASH,    InputAction{.code = "\\", .action = "BACKSLASH"}},
            {SDLK_RIGHTBRACKET, InputAction{.code = "]", .action = "RIGHTBRACKET"}},
            {SDLK_ESCAPE,       InputAction{.code = "ESC", .action = "ESCAPE"}},
            {SDLK_g,            InputAction{.code = "G", .action = "G"}},
    };
};