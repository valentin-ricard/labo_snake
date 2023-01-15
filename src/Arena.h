//---------------------------------------------------------
// Fichier        : Arena.h
// Auteur(s)      : Valentin Ricard & Arthur Menétrey
// Classe         : PRG1-E
// Date           : 2023.01.15
// But            : Class defining the arena in which will be fighting the snakes
//                  Contains the core logic of the game and the game loop
//
// Modifications  : -
// Remarque(s)    : -
//---------------------------------------------------------

#ifndef LABO_SDL_ARENA_H
#define LABO_SDL_ARENA_H

#include "Snake.h"  //Snake definition
#include <vector>   //Vector definition

const static std::size_t STARTING_SNAKE_SIZE = 10;
const static float TAIL_RETENTION_RATE = 0.4f;
const static float KILL_RETENTION_RATE = 0.6f;

/**
 * The arena is the playing ground for snakes.
 * It manages the rules of the game.
 */
class Arena {
private:
    /**
     * The width of the arena
     */
    int width;
    /**
     * The height of the arena
     */
    int height;
    /**
     * A vector of all the snakes evolving around the arena
     */
    std::vector<Snake> snakes;
public:
    /**
     * Creates a new instance of the arena,
     * also initializing the snakes with random positions
     *
     * @param width The width of the arena
     * @param height The height of the arena
     * @param nbSnakes The number of snakes present in the arena
     */
    Arena(int width, int height, int nbSnakes);

    /**
     * Plays the game
     * @param screen
     */
    void play(Screen &screen);

    /**
     * Moves every snake by a single case (ticks the arena).
     */
    void tick();

    /**
     * Renders the arena
     *
     * @param screen The screen to render the arena into.
     */
    void render(Screen &screen);

private:
    /**
     * Kills a snake, removing it from the game, and adds a fixed percentage (
     * of the other's size to the killer.
     * @param killer
     * @param killed
     *
     * @internal This function is meant for internal usage only.
     */
    void kill(Snake &killer, Snake &killed);

    /**
     * Checks if the new position of the snake touches another one.
     * In that case, either eat the tail, or do a deathmatch
     * @see Arena::kill(Snake&, Snake&)
     *
     * @param newSnakeHead
     * @param turn
     * @param snake
     */
    void collisionCheck(Snake &snake, size_t &turn);

    /**
     * Generate a new snake with the provided ID and a random position
     * @param id The ID of the snake to create
     * @return The newly created snake instance
     *
     * @warning The consistency of the IDs are not checked (make sure the Ids provided are unique)
     */
    Snake generateSnake(int id) const;
};


#endif //LABO_SDL_ARENA_H
