#include "ghost.h"
#include "stdlib.h"

Ghost::Ghost() : Character()
{

}

Ghost::Ghost(float x, float y, float r, float g, float b) : Character(x,y)
{
    setColor(r,g,b);
}

void Ghost::randomizeDirection()
{
    int randomNumber = rand() % 4 + 1;
    if(randomNumber == 1) {
        direction = right;
    }
    if(randomNumber == 2) {
        direction = up;
    }
    if(randomNumber == 3) {
        direction = left;
    }
    if(randomNumber == 4) {
        direction = down;
    }
}
