#include <iostream>

// Dependencies
#include "./Engine/Engine.hpp"
#include "./Game/Game.hpp"

int main(int argc, char *args[])
{
    std::cout << "Hello, Night Byte" << std::endl;

    
    Game::gameLoop();

    return 0;
}
