#include "pacman.h"

Pacman::Pacman() : Character()
{
    setColor(1.0f, 1.0f, 0.0f);
}

//Takes in 4 ghosts and checks if pacman is touching them, if he is, then take away a life
bool Pacman::isTouchingGhost(Ghost ghosts[4])
{
    for(int i = 0; i < 4; i++) {
        float ghostX = ghosts[i].getx();
        float ghostY = ghosts[i].gety();
        if(x == ghostX && y == ghostY) {
            return true;
        }
    }
    return false;
}
