//
// Created by ValentinRicard on 09.01.2023.
//

#include <string>
#include "Screen.h"
#include <cmath>
const char *const WINDOW_NAME = "Snakkey!";
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;


bool isInitialized = false;

Screen::Screen(int width, int height) {

    if (isInitialized) {
        isInitialized = true;
        SDL_Init(SDL_INIT_VIDEO);
    }

    // Get the target screen width.
    // The objective is for every pixel to be squared while the window stays within:
    // - [0, SCREEN_WIDTH] for width
    // - [0, SCREEN_HEIGHT] for height
    int targetScale = std::min(SCREEN_WIDTH / width, SCREEN_HEIGHT / height);

    window = SDL_CreateWindow(
            WINDOW_NAME,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width * targetScale,
            height * targetScale,
            0
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetScale(renderer, (float) targetScale, (float) targetScale);

    // Set the background to white:
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    // Clear the screen
    clear();
}

void Screen::clear() {
    SDL_RenderClear(renderer);
}

void Screen::draw() {
    SDL_RenderPresent(renderer);
}

Screen &Screen::drawPixel(int x, int y, const Color &color) {
    SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(renderer, x, y);

    return *this;
}

Screen::~Screen() {
    SDL_DestroyWindow(window);
    SDL_Quit();
    // As we destroyed the SDL instance, we have to initialize it back again afterwards.
    isInitialized = false;
}


