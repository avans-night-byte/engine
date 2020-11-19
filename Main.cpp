#define SDL_MAIN_HANDLED
#include <iostream>

// Dependencies
#include "./Game/Game.hpp"

// Variables
const int width = 640;
const int height = 480;

int main(int argc, char *args[]) {
    std::cout << "Hello, Night Byte" << std::endl;

    Game* game = Game::getInstance();
    game->initialize();
    game->gameLoop();

    return 0;
}