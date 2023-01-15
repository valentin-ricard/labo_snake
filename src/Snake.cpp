//---------------------------------------------------------
// Fichier        : Snake.cpp
// Auteur(s)      : Valentin Ricard & Arthur Menétrey
// Classe         : PRG1-E
// Date           : 2023.01.15
// But            : Snake class that is used for basic snake movement, positioning
//                  and containing its own apple
//
// Modifications  : -
// Remarque(s)    : -
//---------------------------------------------------------

#include "Snake.h"  //Corresponding definition
#include "Screen.h" //Draw on screen
#include "utils.h"  //Random integer generator

Snake::Snake(int id, Position& position, size_t size) : id(id), snakeBuffer(size) {
    // Set the first position:
    setHead(position);
}

void Snake::resize(size_t size) {
    snakeBuffer.resize(size);
}

Position Snake::move() {

    // Get the difference between the x and y of the snake and the apple:
    Position diff = this->getApplePosition() - this->getHeadPosition();
    // We get the smallest direction between the two:
    Position move;
    if (abs(diff.x) > abs(diff.y)) {
        // The sign of x decides the direction:
        if (diff.x < 0) {
            move = Position(-1, 0);
        } else {
            move = Position(1, 0);
        }
    } else {
        // The sign of Y decides the direction
        if (diff.y < 0) {
            move = Position(0, -1);
        } else {
            move = Position(0, 1);
        }
    }
    setHead(this->getHeadPosition() + move);

    return getHeadPosition();
}

const Position &Snake::getHeadPosition() const {
    return snakeBuffer.at_head();
}

const Position &Snake::getApplePosition() const {
    return apple.getPosition();
}

void Snake::render(Screen &screen) const {
    // Draw the apple
    apple.render(screen);

    // Draw every case of the snake, if it is not buffered (-1, -1)
    for (int i = 0; i < snakeBuffer.size(); ++i) {
        const Position &pos = snakeBuffer.at(i);
        if (pos != Position(-1, -1)) {
            screen.drawPixel(pos.x, pos.y, Color(id * 128, id * 128, 255));
        }
    }
}

void Snake::setHead(const Position &position) {
    // We append the new element:
    snakeBuffer.push_front(position);
}

int Snake::size() const {
    return snakeBuffer.size();
}

Apple &Snake::getApple() {
    return apple;
}

int Snake::getId() const {
    return id;
}

size_t Snake::getTailIndex(const Position &position) {
    return snakeBuffer.find(position);
}

bool Snake::operator==(const Snake &other) const {
    return id == other.id;
}

bool Snake::operator!=(const Snake &other) const {
    return !(*this == other);
}
