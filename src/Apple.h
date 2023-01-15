//---------------------------------------------------------
// Fichier        : Apple.h
// Auteur(s)      : Valentin Ricard & Arthur Menétrey
// Classe         : PRG1-E
// Date           : 2023.01.15
// But            : Classe defining the apples that will be eaten by the snakes
//                  Contains the random positioning and render methods
//
// Modifications  : -
// Remarque(s)    : -
//---------------------------------------------------------

#ifndef LABO_SDL_APPLE_H
#define LABO_SDL_APPLE_H

#include "Position.h"   //Position class
#include "Screen.h"     //Drawing on screen
/**
 * The lowest value an apple can have
 */
const int APPLE_VALUE_MIN = 1;
/**
 * The highest value an apple can have
 */
const int APPLE_VALUE_MAX = 10;

/**
 * The apple is a game object for each snake.
 * This is the target for every snake move.
 * When eaten, it adds its value to the snake's length.
 */
class Apple {
private:
    /**
     * The position of the apple
     */
    Position position;
    /**
     * The value of the apple.
     *
     * @note The value is initialized at 0 to remove a warning.
     *  The objective is to not set any value to have a parameterless constructor,
     *  and call reset() to initialize it
     */
    int value = 0;
public:
    /**
     * Gets the current position of the apple
     * @return a constant pointer to the position of the apple
     */
    const Position &getPosition() const;

    /**
     * Gets the current value of the apple
     * @return a copy of the value of the apple
     */
    int getValue() const;

    /**
     * Resets (or initialize) the position and value of the apple.
     *
     * @param arenaWidth The width of the arena the apple is placed into
     * @param arenaHeight The height of the arena the apple is placed into
     *
     * @note Modifies the parameters of the Apple internally.
     */
    void reset(int arenaWidth, int arenaHeight);

    /**
     * Renders the apple.
     *
     * @param screen The screen to render the apple into
     */
    void render(Screen &screen) const;
};


#endif //LABO_SDL_APPLE_H
