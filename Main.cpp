#include <iostream>

// Dependencies
#include "./Game/Game.hpp"
#include "Engine/Resources/XML/Generated/wall.hxx"


// Variables
const int width = 640;
const int height = 480;

int main(int argc, char *args[]) {
    std::cout << "Hello, Night Byte" << std::endl;

    auto bruh = walls("C:\\Users\\Martijn\\Documents\\Avans\\Minor\\Engine\\Engine\\Resources\\XML\\Definition\\Walls.xml");
    std::cout << bruh.className() << std::endl;


    Game::gameLoop();

    return 0;
}