//
// Created by ValentinRicard on 09.01.2023.
//

#ifndef LABO_SDL_SCREEN_H
#define LABO_SDL_SCREEN_H

#include "SDL.h"

class Screen {
public:
    Screen(int width, int height);

    Screen &drawPixel(Screen &screen);
    
    void clear(Screen &screen);

private:

    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif //LABO_SDL_SCREEN_H
