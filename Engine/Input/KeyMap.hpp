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
        {SDL_CONTROLLER_BUTTON_A, "CONTROLLER_BUTTON_A"},
        {SDL_CONTROLLER_BUTTON_B, "CONTROLLER_BUTTON_B"},
        {SDL_CONTROLLER_BUTTON_X, "CONTROLLER_BUTTON_X"},
        {SDL_CONTROLLER_BUTTON_Y, "CONTROLLER_BUTTON_Y"},

        {SDL_CONTROLLER_BUTTON_LEFTSHOULDER, "CONTROLLER_BUTTON_LB"},
        {SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, "CONTROLLER_BUTTON_RB"},

        // {SDL_CONTROLLER_AXIS_TRIGGERLEFT, "CONTROLLER_BUTTON_LT"},
        // {SDL_CONTROLLER_AXIS_TRIGGERRIGHT, "CONTOLLER_BUTTON_RT"},

        {SDL_CONTROLLER_BUTTON_BACK, "CONTROLLER_BUTTON_SELECT"},
        {SDL_CONTROLLER_BUTTON_START, "CONTROLLER_BUTTON_START"},

        {SDL_CONTROLLER_BUTTON_LEFTSTICK, "CONTROLLER_BUTTON_L3"},
        {SDL_CONTROLLER_BUTTON_RIGHTSTICK, "CONTROLLER_BUTTON_R3"},

        {SDL_CONTROLLER_BUTTON_DPAD_UP, "CONTOLLER_DPAD_UP"},
        {SDL_CONTROLLER_BUTTON_DPAD_DOWN, "CONTROLLER_DPAD_DOWN"},
        {SDL_CONTROLLER_BUTTON_DPAD_LEFT, "CONTROLLER_DPAD_LEFT"},
        {SDL_CONTROLLER_BUTTON_DPAD_RIGHT, "CONTROLLER_DPAD_RIGHT"},
    };
};