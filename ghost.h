#ifndef GHOST_H
#define GHOST_H

#include "character.h"

class Ghost : public Character
{
public:
    Ghost();
    Ghost(float, float, float, float, float);
    void randomizeDirection();
};

#endif // GHOST_H
