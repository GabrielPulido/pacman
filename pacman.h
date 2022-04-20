#ifndef PACMAN_H
#define PACMAN_H

#include <string.h>
#include "character.h"

class Pacman : public Character
{

public:

    Pacman();
    Pacman(float, float);
    int lives = 3;
};

#endif // PACMAN_H
