//
// Created by ValentinRicard on 09.01.2023.
//

#include <string>
#include "screen.h"

const char *const WINDOW_NAME = "Snakkey!";
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;


Screen::Screen(int width, int height) {

    // Get the target screen width.
    // The objective is for every pixel to be squared while the window stays within:
    // - [0, SCREEN_WIDTH] for width
    // - [0, SCREEN_HEIGHT] for height
    int targetScale =

    window = SDL_CreateWindow(
            WINDOW_NAME,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH + (SCREEN_WIDTH % width),
            SCREEN_HEIGHT + (SCREEN_HEIGHT % height),
            0
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Now we compute the scale:


}
