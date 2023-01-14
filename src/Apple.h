//
// Created by ValentinRicard on 13.01.2023.
//

#ifndef LABO_SDL_APPLE_H
#define LABO_SDL_APPLE_H

#include "Position.h"
#include "Screen.h"

const int APPLE_VALUE_MIN = 1;
const int APPLE_VALUE_MAX = 10;

class Apple {
private:
    Position position;
    int value;
public:
    const Position &getPosition() const;

    int getValue() const;

    void reset(int arenaWidth, int arenaHeight);

    void render(Screen &screen) const;
};


#endif //LABO_SDL_APPLE_H
