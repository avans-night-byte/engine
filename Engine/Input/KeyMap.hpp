#include <map>
#include <string>

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
  inline static std::map<SDL_Keycode, std::string> joystickMap = {};
};