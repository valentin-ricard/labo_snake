//---------------------------------------------------------
// Fichier        : Apple.cpp
// Auteur(s)      : Valentin Ricard & Arthur Menétrey
// Classe         : PRG1-E
// Date           : 2023.01.15
// But            : Classe defining the apples that will be eaten by the snakes
//                  Contains the random positioning and render methods
//
// Modifications  : -
// Remarque(s)    : -
//---------------------------------------------------------

#include "Apple.h"  //Corresponding definition
#include "utils.h"  //Random integer value

const Position &Apple::getPosition() const {
    return position;
}

int Apple::getValue() const {
    return value;
}

void Apple::reset(int arenaWidth, int arenaHeight) {
    position = Position::random(arenaWidth, arenaHeight);

    value = APPLE_VALUE_MIN + randomNumber(APPLE_VALUE_MAX - APPLE_VALUE_MIN);
}

void Apple::render(Screen &screen) const {
    screen.drawPixel(position.x, position.y, RED);
}
