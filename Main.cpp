#include <iostream>

// Dependencies
#include "./Engine/Engine.hpp"
#include "./game/Game.hpp"

// Variables
const int width = 640;
const int height = 480;

// TODO: This should be moved to the engine
int main(int argc, char *args[])
{
    std::cout << "Hello, Main.cpp" << std::endl;

    Engine::initWindow(width, height);
    Game::gameLoop();

    return 0;
}
