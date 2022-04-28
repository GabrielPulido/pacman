#ifndef GHOST_H
#define GHOST_H

#include "character.h"

class Ghost : public Character
{
public:
    Ghost();
    Ghost(float, float, float, float, float);
    void redDirection(Character pacman, Grid &grid);
};

#endif // GHOST_H
