#include "SDL.h"
#include "Screen.h"
#include "Arena.h"
#include <iostream>
#include <cassert>

int main() {
    {
        Screen screen(200, 200);

        // Create the arena:
        Arena arena(200, 200, 25);

        arena.play(screen);
    }

    std::cout << "Finished!";

    return 0;
}