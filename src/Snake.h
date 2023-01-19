//---------------------------------------------------------
// Fichier        : Snake.h
// Auteur(s)      : Valentin Ricard & Arthur Menétrey
// Classe         : PRG1-E
// Date           : 2023.01.15
// But            : Snake class that is used for basic snake movement, positioning
//                  and containing its own apple
//
// Modifications  : -
// Remarque(s)    : -
//---------------------------------------------------------

#ifndef LABO_SDL_SNAKE_H
#define LABO_SDL_SNAKE_H

#include "Position.h"           //Position definition
#include "CircularVector.hpp"   //CircularVector data structure
#include "Screen.h"             //Draw on screen
#include "Apple.h"              //Apple management

/**
 * A snake game element
 * Represents a snake in the game, in addition to their apple.
 */
class Snake {
public:
    /**
     * Checks if other is the same as this instance by comparing their IDs
     * @param other The other snake to check against
     * @return true if this->id == other.id, false otherwise
     */
    bool operator==(const Snake &other) const;

    /**
     * Checks if other is different as this instance by comparing their IDs
     * @param other The other snake to check against
     * @return true if this->id != other.id, false otherwise
     */
    bool operator!=(const Snake &other) const;

    /**
     * Creates a new instance of Snake with a given id, initial position, and size
     * @param id The ID of the newly created snake
     * @param position The initial position of the newly created snake
     * @param size The initial size of the snake
     */
    Snake(int id, Position &position, size_t size);

    /**
     * Resizes the snake
     * @param size the new wanted size
     */
    void resize(size_t size);

    /**
     * Let the snake move
     * @return The new snake's head position
     */
    Position move();

    /**
     * The size of the snake
     * @return The new size
     */
    size_t size() const;

    /**
     * Gets the position of the head
     * @return A const reference to the head position
     */
    const Position &getHeadPosition() const;

    /**
     * Gets the position of this snake's apple
     * @return A const reference to position of the apple
     */
    const Position &getApplePosition() const;

    /**
     * Renders to the screen the snake and its accompanying apple.
     * @param screen The screen to render it into
     */
    void render(Screen &screen) const;

    /**
     * Gets the apple
     * @return a mutable reference to the apple
     */
    Apple &getApple();

    /**
     * Gets the id of the Snake
     * @return the Id of the snake (not a reference, as it is the same cost)
     */
    int getId() const;

    /**
     * Gets the tail index of the given position
     * @param position The position to check
     * @return Returns the index of the position, CircularVector<T>::NO_MATCH otherwise
     */
    size_t getTailIndex(const Position &position);

private:
    /**
     * The id of the snake.
     * ! Should not be changed unless assigned !
     */
    // The value was not set as const to avoid doing weird and unsafe things with pointers to change the value.
    int id;

    /**
     * The CircularVector holding all the snake's tail sections.
     */
    CircularVector<Position> snakeBuffer;

    /**
     * The apple this snake will go towards.
     */
    Apple apple;

    /**
     * Sets the head to the given position
     * @param position the new position of the head
     */
    void setHead(const Position &position);
};


#endif //LABO_SDL_SNAKE_H
