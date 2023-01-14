//
// Created by ValentinRicard on 09.01.2023.
//

#ifndef LABO_SDL_SCREEN_H
#define LABO_SDL_SCREEN_H

#include "SDL.h"

class Color {
public:
    Color(short red, short green, short blue) : red(red), green(green), blue(blue) {}

    short red;
    short green;
    short blue;
};

// == Common colors ==
static const Color RED(255, 0, 0);
static const Color GREEN(0, 255, 0);
static const Color BLUE(0, 0, 255);
static const Color BLACK(0,0,0);

class Screen {
public:
    Screen(int width, int height);

    Screen &drawPixel(int x, int y, const Color &color);

    void drawFrame();

    void clear();

    bool shouldQuit();

    ~Screen();

private:

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
};


#endif //LABO_SDL_SCREEN_H
