#define SDL_MAIN_HANDLED

// Dependencies
#include "./Game/Game.hpp"


int main(int argc, char *args[]) {
    Game &game = *Game::getInstance();
    game.initialize();
    game.gameLoop();
    return 0;
}
