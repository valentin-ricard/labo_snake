//
// Created by ValentinRicard on 10.01.2023.
//

#ifndef LABO_SDL_SNAKE_H
#define LABO_SDL_SNAKE_H

#include <vector>
#include "Position.h"
#include "RingBuffer.h"

class Snake {

private:
    RingBuffer<Position> snakeBuffer;
    Position applePos;
    int snake_size;

public:
    Snake(Position& position, size_t size);
    void resize(size_t size);
    void move(std::vector<Position> availableMoves);

    int getLength() const;

    Position getPosition();
    Position getApple();
};


#endif //LABO_SDL_SNAKE_H
