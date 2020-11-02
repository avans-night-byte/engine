#include <iostream>


// Dependencies
#include "./Engine/Engine.hpp"
#include "./Game/Game.hpp"

#include "SDL_mixer.h"

// Variables
const int width = 640;
const int height = 480;

//The music that will be played
Mix_Music *gMusic = nullptr;

//The sound effects that will be used
Mix_Chunk *gScratch = nullptr;
Mix_Chunk *gHigh = nullptr;
Mix_Chunk *gMedium = nullptr;
Mix_Chunk *gLow = nullptr;


int main(int argc, char *args[])
{
    std::cout << "Hello, Night Byte" << std::endl;

    Engine::initWindow(width, height);


    // TODO: Try higher frequency
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }

    if(Mix_Init(MIX_INIT_MP3) < 0)
    {
        printf( "Failed to init Mix: %s\n", Mix_GetError() );
    }


    gMusic = Mix_LoadMUS("Welcome_To_The_Cum_Zone_Official_Music_Video.wav");
    if( gMusic == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    else
    {
        Mix_PlayMusic(gMusic, -1);
    }

    Game::gameLoop();

    return 0;
}
