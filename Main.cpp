#define SDL_MAIN_HANDLED
#include <iostream>

// Dependencies
#include "./Game/Game.hpp"
#include "./Engine/Level1.hpp"

// Variables
const int width = 640;
const int height = 480;

int main(int argc, char *args[]) {
    std::cout << "Hello, Night Byte" << std::endl;

    Game::initialize();
    Game::gameLoop();


    return 0;
}
