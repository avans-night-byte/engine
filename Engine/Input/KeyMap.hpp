#include <map>
#include <string>

#include "../../SDL/include/SDL_events.h"

class KeyMap
{
public:
    inline static std::map<SDL_Keycode, std::string> keyboardMap = {
        {SDLK_UP, "UP"},
        {SDLK_DOWN, "DOWN"},
        {SDLK_LEFT, "LEFT"},
        {SDLK_RIGHT, "RIGHT"},
        {SDLK_w, "UP"},
        {SDLK_s, "DOWN"},
        {SDLK_a, "LEFT"},
        {SDLK_d, "RIGHT"},
        {SDLK_SPACE, "SPACE"},
        {SDLK_e, "E"},
        {SDLK_q, "Q"},
    };
    inline static std::map<SDL_Keycode, std::string> mouseMap = {
        {SDL_BUTTON_LEFT, "MOUSE_BUTTON_LEFT"},
        {SDL_BUTTON_RIGHT, "MOUSE_BUTTON_RIGHT"},
    };
    inline static std::map<Uint8, std::string> controllerMap = {
        {0, "CONTROLLER_BUTTON_A"},
        {1, "CONTOLLER_BUTTON_B"},
        {3, "CONTROLLER_BUTTON_X"},
        {4, "CONTROLLER_BUTTON_Y"},

        {6, "CONTROLLER_BUTTON_LB"},
        {7, "CONTROLLER_BUTTON_RB"},

        {8, "CONTROLLER_BUTTON_LT"},
        {9, "CONTOLLER_BUTTON_RT"},

        {10, "CONTROLLER_BUTTON_SELECT"},
        {11, "CONTROLLER_BUTTON_START"},

        {13, "CONTROLLER_BUTTON_L3"},
        {14, "CONTROLLER_BUTTON_R3"},
        
        {12, "CONTOLLER_DPAD_UP"},
        {13, "CONTROLLER_DPAD_DOWN"},
        {14, "CONTROLLER_DPAD_LEFT"},
        {15, "CONTROLLER_DPAD_RIGHT"},
    };
};