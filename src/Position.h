//
// Created by ValentinRicard on 10.01.2023.
//

#ifndef LABO_SDL_POSITION_H
#define LABO_SDL_POSITION_H


class Position {
public:
    Position(): x(-1), y(-1) {}
    Position(int x, int y): x(x), y(y) {}

    int x;
    int y;
};


#endif //LABO_SDL_POSITION_H
