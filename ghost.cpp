#include "ghost.h"

Ghost::Ghost() : Character()
{

}

Ghost::Ghost(float x, float y, float r, float g, float b) : Character(x,y)
{
    setColor(r,g,b);
}
