//
// Created by ValentinRicard on 10.01.2023.
//

#include "Position.h"
#include "utils.h"

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
