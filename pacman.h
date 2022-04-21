#ifndef PACMAN_H
#define PACMAN_H

#include <string.h>
#include "character.h"
#include "ghost.h"

class Pacman : public Character
{

public:

    Pacman();
    bool isTouchingGhost(Ghost ghosts[4]); //checks if he's touching any of the ghosts
    int lives = 3;
};

#endif // PACMAN_H
