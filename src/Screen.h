//---------------------------------------------------------
// Fichier        : Screen.h
// Auteur(s)      : Valentin Ricard & Arthur Menétrey
// Classe         : PRG1-E
// Date           : 2023.01.15
// But            : Screen class managing graphic output in a windows using the SDL2 library
//                  This class contains methods to create and draw directly on a windows
//
// Modifications  : -
// Remarque(s)    : -
//---------------------------------------------------------

#ifndef LABO_SDL_SCREEN_H
#define LABO_SDL_SCREEN_H

#include "SDL.h"    //SDL Window, renderer and events
/**
 * An RGB color object (used for Screen)
 */
class Color {
public:
    Color(unsigned char red, unsigned char green, unsigned char blue) : red(red), green(green), blue(blue) {}

    /**
     * The red component of the color
     */
    unsigned char red;
    /**
     * The green component of the color
     */
    unsigned char green;

    /**
     * The blue component of the color
     */
    unsigned char blue;
};

// == Common colors ==
static const Color RED(255, 0, 0);
static const Color GREEN(0, 255, 0);
static const Color BLUE(0, 0, 255);
static const Color BLACK(0,0,0);

/**
 * The screen class is a simple wrapper around SDL for drawing arbitrary pixels into the frame buffer.
 */
class Screen {
public:
    /**
     * Creates and initializes a new screen.
     * Scaling is managed by the implementation to be within the bounds of the screen
     *
     * @param width  The width of the drawing zone
     * @param height The height of the drawing zone
     */
    Screen(int width, int height);

    /**
     * Draws a pixel at the wanted position
     *
     * @param x The x coordinate of the pixel to place
     * @param y The y coordinate of the pixel to place
     * @param color The color of the pixel
     * @return A reference to this screen, for chaining calls
     */
    Screen &drawPixel(int x, int y, const Color &color);

    /**
     * Draws to the screen the final frame (applies all pending changes)
     */
    void drawFrame();

    /**
     * Clears the window back to white.
     */
    void clear();

    /**
     * Polls the pending event loop of SDL to check if the user has attempted to clear the window.
     * @return true if the user has closed the window, false otherwise.
     */
    bool shouldQuit();

    /**
     * Frees and destroys the screen and internal tools.
     */
    ~Screen();

private:

    /**
     * A pointer to the SDL window.
     */
    SDL_Window *window;
    /**
     * A pointer to the SDL renderer (draw buffer)
     */
    SDL_Renderer *renderer;
    /**
     * An instance of event,
     * here to avoid allocating on the stack each time shouldQuit is called.
     */
    SDL_Event event;
};


#endif //LABO_SDL_SCREEN_H
