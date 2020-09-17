//
// Created by husey on 29-8-2020.
//
#define SDL_MAIN_HANDLED

#include <iostream>
#include "SDL.h"

using namespace std;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
            "SDL2Test",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            0
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();

//    std::string name;
//
//    std::cout << "Please, enter your full name: ";
//    std::getline (std::cin,name);
//    std::cout << "Hello, " << name << "!\n";

    return 0;
}