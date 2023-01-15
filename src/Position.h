//---------------------------------------------------------
// Fichier        : Position.h
// Auteur(s)      : Valentin Ricard & Arthur Menétrey
// Classe         : PRG1-E
// Date           : 2023.01.15
// But            : Position class used for storing simple discrete points
//
// Modifications  : -
// Remarque(s)    : -
//---------------------------------------------------------

#ifndef LABO_SDL_POSITION_H
#define LABO_SDL_POSITION_H

/**
 * A position is coordinates in a 2D environment.
 * It implements a lot of operators, taken from mathematical vectors to facilitate work.
 */
class Position {
public:
    /**
     * The x coordinate of this position
     */
    int x;

    /**
     * The y coordinate of this position
     */
    int y;

    /**
     * Creates a new random position within the given bounds (not inclusive)
     * @param maxX The maximum x value (not included)
     * @param maxY The maximum y value (not included)
     * @return A new instance of position with the randomized coordinates
     */
    static Position random(int maxX, int maxY);

    /**
     * Creates a default position.
     * The fact that they are assigned to -1, -1 is useful in order
     * to differentiate wanted points from default constructor ones.
     */
    Position() : x(-1), y(-1) {}

    /**
     * Creates a position with the given coordinates
     * @param x The x coordinate
     * @param y The y coordinate
     */
    Position(int x, int y) : x(x), y(y) {}

    /**
     * Subtracts a position with another one.
     * @param other The other element
     * @return A new element, representing the result of the subtraction
     */
    Position operator-(const Position &other) const;

    /**
     * Adds a position with another one.
     * @param other The other element
     * @return A new element, representing the result of the addition
     */
    Position operator+(const Position &other) const;

    /**
     * Checks if two positions are the same
     * @param other The position to compare it to
     * @return true if the positions are the same, false otherwise
     */
    bool operator==(const Position &other) const;

    /**
     * Checks if two positions are different
     * @param other The position to compare it to
     * @return true if the positions are different, false otherwise
     */
    bool operator!=(const Position &other) const;
};


#endif //LABO_SDL_POSITION_H
