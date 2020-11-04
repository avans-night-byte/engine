#include <iostream>
// Dependencies
#include "./Engine/Engine.hpp"
#include "./Game/Game.hpp"

#include "SDL_mixer.h"

// Variables
const int width = 640;
const int height = 480;




int main(int argc, char *args[])
{
    std::cout << "Hello, Night Byte" << std::endl;

    //Engine::initWindow(width, height);
    

    Game::gameLoop();

    return 0;
}
