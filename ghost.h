#ifndef GHOST_H
#define GHOST_H

#include "character.h"
#include "grid.h"

class Ghost : public Character
{
public:

    Ghost();
    Ghost(float, float, float, float, float);
    void redDirection(Character pacman, Grid &grid);
    void pinkDirection(Character pacman, Grid &grid);
    void blueDirection(Character pacman, Grid &grid);
    void orangeDirection(Character pacman, Grid &grid);

};

#endif // GHOST_H
