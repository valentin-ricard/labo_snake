#define named(blockname) goto blockname; \
                         blockname##_skip: if (0) \
                         blockname:

#define break(blockname) goto blockname##_skip

#include "SDL.h"
#include "Screen.h"
#include <iostream>

int main() {
    {
        Screen screen(50, 75);

        for (int x = 0; x < 50; ++x) {
            for (int y = 0; y < 75; ++y) {
                screen.drawPixel(x, y, Color(x, y, 255));
            }
        }

        screen.draw();

        SDL_Delay(9000);
    }

    std::cout << "Finished!";

    return 0;
}