//
// Created by ValentinRicard on 12.01.2023.
//

#include "Arena.h"
#include "utils.h"
#include <iostream>
#include <chrono>

Snake Arena::generateSnake(int id) const {
    // Get random position for it
    Position position = Position::random(width, height);
    Snake snake = {id, position, STARTING_SNAKE_SIZE};
    snake.getApple().reset(width, height);

    return snake;
}

Arena::Arena(int width, int height, int nbSnakes) : width(width), height(height) {
    // Initialize the snakes with random positions
    for (int i = 0; i < nbSnakes; ++i) {
        snakes.push_back(generateSnake(i + 1));
    }
}

void Arena::render(Screen &screen) {
    screen.clear();

    // Draw every snake with their apple
    for (const Snake &snake: snakes) {
        snake.render(screen);
    }

    screen.drawFrame();
}

void Arena::play(Screen &screen) {
    // play until there's a winner or the close button has been pressed

    while (snakes.size() > 1 && !screen.shouldQuit()) {
        for (size_t turn = 0; turn < snakes.size(); ++turn) {
            Snake &snake = snakes[turn];
            Position position = snake.move();
            // Check if you are on the tail of another snake:
            collisionCheck(snake, turn);
            // With the position, eat the apple if reached
            if (position == snake.getApplePosition()) {
                snake.resize(snake.size() + snake.getApple().getValue());
                // Generate a new apple
                snake.getApple().reset(width, height);
            }
        }
        // The turn's finished, draw the state:
        render(screen);
        // Delay a bit:
        SDL_Delay(20);
    }
}

void Arena::collisionCheck(Snake &snake, size_t &turn) {
    for (size_t otherIdx = 0; otherIdx < snakes.size(); ++otherIdx) {
        Snake &other = snakes[otherIdx];
        if (other != snake) {
            size_t tailIndex = other.getTailIndex(snake.getHeadPosition());
            if (tailIndex == NO_MATCH) {
                // NO-OP, no collision
            } else if (tailIndex == 0) {
                // Head fight!
                if (other.size() > snake.size()) {
                    kill(other, snake);
                    // Decrement to still process the previous snake
                    --turn;
                } else {
                    kill(snake, other);
                    // TODO: Si other > snake, sinon --snake...
                    if (otherIdx < turn) {
                        --turn;
                    }
                }
            } else {
                // Tail eaters!
                snake.resize(snake.size() + (int) (TAIL_RETENTION_RATE * (float) (other.size() - tailIndex)));
                other.resize(tailIndex);
            }
        }
    }
}

void Arena::kill(Snake &killer, Snake &killed) {
    // We show the message first, as the reference may change afterwards
    std::cout << killer.getId() << " a tué " << killed.getId() << std::endl;

    //We also resize the killer of 60% of the killed size
    killer.resize(killer.size() + (size_t) (KILL_RETENTION_RATE * (float) killed.size()));

    snakes.erase(std::remove(snakes.begin(), snakes.end(), killed), snakes.end());
}
