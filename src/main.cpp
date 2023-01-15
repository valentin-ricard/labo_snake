#include "SDL.h"
#include "Screen.h"
#include "Arena.h"
#include <iostream>
#include <cassert>

int main() {
    {
        Screen screen(1200, 800);

        // Create the arena:
        Arena arena(1200, 800, 1000);

        arena.play(screen);
    }

    std::cout << "Finished!";

    return 0;
}