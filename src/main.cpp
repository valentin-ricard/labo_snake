#define named(blockname) goto blockname; \
                         blockname##_skip: if (0) \
                         blockname:

#define break(blockname) goto blockname##_skip

#include "SDL.h"
#include "Screen.h"
#include "Arena.h"
#include <iostream>
#include <cassert>

int main() {
    {
        Screen screen(50, 75);

        // Create the arena:
        Arena arena(50, 75, 10);

        arena.play(screen);
    }

    std::cout << "Finished!";

    return 0;
}