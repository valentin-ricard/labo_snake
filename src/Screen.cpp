//---------------------------------------------------------
// Fichier        : Screen.cpp
// Auteur(s)      : Valentin Ricard & Arthur Menétrey
// Classe         : PRG1-E
// Date           : 2023.01.15
// But            : Screen class managing graphic output in a windows using the SDL2 library
//                  This class contains methods to create and draw directly on a windows
//
// Modifications  : -
// Remarque(s)    : -
//---------------------------------------------------------

#include "Screen.h" //Corresponding definition
#include <cmath>    //Absolute values

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
    // Set the background to white before clearing
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderClear(renderer);
}

void Screen::drawFrame() {
    SDL_RenderPresent(renderer);
}

bool Screen::shouldQuit() {
    // Get all the elements from the queue
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                return true;
        }
    }
    return false;
}

Screen &Screen::drawPixel(int x, int y, const Color &color) {
    SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, SDL_ALPHA_OPAQUE);

    SDL_RenderDrawPoint(renderer, x, y);

    return *this;
}

Screen::~Screen() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    // As we destroyed the SDL instance, we have to initialize it back again afterwards.
    isInitialized = false;
}



