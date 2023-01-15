//---------------------------------------------------------
// Fichier        : main.cpp
// Auteur(s)      : Valentin Ricard & Arthur Menétrey
// Classe         : PRG1-E
// Date           : 2023.01.15
// But            : This programme is inspired from the game "Snake". In it, snakes move and try to get apples
//                  from the arena. When a snake eats an apple, it grows but in the other hand, it can be
//                  sliced by other snakes passing by.
//
// Modifications  : -
// Remarque(s)    : -
//---------------------------------------------------------

#include "Screen.h" //Create window and drawing
#include "Arena.h"  //Start new game
#include "utils.h"  //User inputs

// NOTE: To avoid un-necessary memory usage, the min for screen size is shared.
//       Also, I cannot think of a reason where it would be different.
const static int MIN_SCREEN_SIZE = 50;
const static int MAX_SCREEN_WIDTH = 1200;
const static int MAX_SCREEN_HEIGHT = 800;
const static int MIN_SNAKES = 2;
const static int MAX_SNAKES = 1000;

// The rest of the screen constraints are defined in Screen.cpp

int main(int argc, char *argv[]) {
    int screenWidth = input("Largeur", "La largeur est invalide.", MIN_SCREEN_SIZE, MAX_SCREEN_WIDTH);
    int screenHeight = input("Hauteur", "La hauteur est invalide.", MIN_SCREEN_SIZE, MAX_SCREEN_HEIGHT);
    int nbSnakes = input("Nbre snakes", "Le nombre de serpents est invalide", MIN_SNAKES, MAX_SNAKES);

    {
        Screen screen(screenWidth, screenHeight);

        Arena arena(screenWidth, screenHeight, nbSnakes);

        arena.play(screen);
    }

    std::cout << "Finished!";

    return 0;
}