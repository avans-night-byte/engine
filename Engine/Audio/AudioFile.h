//
// Created by Storm on 05/10/2020.
//

#ifndef NIGHTBYTE_AUDIOFILE_H
#define NIGHTBYTE_AUDIOFILE_H


#include <SDL_types.h>

//https://gist.github.com/armornick/3447121 for more info

class AudioFile {
private:
    const Uint8 *audioPos;
    const Uint32 audioLength;
};


#endif //NIGHTBYTE_AUDIOFILE_H
