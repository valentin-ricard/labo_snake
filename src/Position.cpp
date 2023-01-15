//---------------------------------------------------------
// Fichier        : Position.cpp
// Auteur(s)      : Valentin Ricard & Arthur Menétrey
// Classe         : PRG1-E
// Date           : 2023.01.15
// But            : Position class used for storing simple discrete points
//
// Modifications  : -
// Remarque(s)    : -
//---------------------------------------------------------

#include "Position.h"   //Position definition
#include "utils.h"      //Random integer generator

Position Position::operator-(const Position &other) const {
    return {this->x - other.x, this->y - other.y};
}

Position Position::operator+(const Position &other) const {
    return {this->x + other.x, this->y + other.y};
}

bool Position::operator==(const Position &other) const {
    return x == other.x && y == other.y;
}

bool Position::operator!=(const Position &other) const {
    return !(*this == other);
}

Position Position::random(int maxX, int maxY) {
    return {randomNumber(maxX), randomNumber(maxY)};
}
