//
// Created by ValentinRicard on 10.01.2023.
//

#ifndef LABO_SDL_SNAKE_H
#define LABO_SDL_SNAKE_H

#include <vector>
#include "Position.h"
#include "SnakeBuffer.hpp"
#include "Screen.h"
#include "utils.h"
#include "Apple.h"

class Snake {

private:
    int id;
    SnakeBuffer<Position> snakeBuffer;
    Apple apple;

public:
    bool operator==(const Snake& other) const;
    bool operator!=(const Snake& other) const;


    Snake(int id, Position& position, size_t size);
    void resize(size_t size);
    Position move();
    int size() const;
    const Position& getHeadPosition() const;
    const Position& getApplePosition() const;
    void render(Screen &screen) const;
    Apple &getApple();

    int getId() const;
    size_t getTailIndex(const Position &position);

private:
    void setHead(const Position &position);
};


#endif //LABO_SDL_SNAKE_H
