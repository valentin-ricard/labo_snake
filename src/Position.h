//
// Created by ValentinRicard on 10.01.2023.
//

#ifndef LABO_SDL_POSITION_H
#define LABO_SDL_POSITION_H


class Position {
public:
    Position operator-(const Position &other) const;
    Position operator+(const Position &other) const;
    bool operator==(const Position &other) const;
    bool operator!=(const Position &other) const;

    Position(): x(-1), y(-1) {}
    Position(int x, int y): x(x), y(y) {}

    static Position random(int maxX, int maxY);

    int x;
    int y;
};


#endif //LABO_SDL_POSITION_H
