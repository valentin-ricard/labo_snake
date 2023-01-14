//
// Created by ValentinRicard on 12.01.2023.
//

#ifndef LABO_SDL_ARENA_H
#define LABO_SDL_ARENA_H


#include <vector>
#include "Snake.h"

const std::size_t STARTING_SNAKE_SIZE = 10;

class Arena {
private:
    int width;
    int height;
    std::vector<Snake> snakes;
public:
    Arena(int width, int height, int nbSnakes);

    void render(Screen &screen);

    void play(Screen &screen);

    Snake generateSnake(int id) const;

private:
    void kill(Snake &killer, Snake &killed);
};


#endif //LABO_SDL_ARENA_H
