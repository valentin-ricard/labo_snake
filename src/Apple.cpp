//
// Created by ValentinRicard on 13.01.2023.
//

#include "Apple.h"
#include "utils.h"

const Position &Apple::getPosition() const {
    return position;
}

int Apple::getValue() const {
    return value;
}

void Apple::reset(int arenaWidth, int arenaHeight) {
    // Set new positions:
    position = Position::random(arenaWidth, arenaHeight);
    value = APPLE_VALUE_MIN + randomNumber(APPLE_VALUE_MAX - APPLE_VALUE_MIN);
}

void Apple::render(Screen &screen) const {
    screen.drawPixel(position.x, position.y, RED);
}
