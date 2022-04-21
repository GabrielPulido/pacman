#include "ghost.h"
#include "stdlib.h"

Ghost::Ghost() : Character()
{

}

Ghost::Ghost(float x, float y, float r, float g, float b) : Character(x,y)
{
    setColor(r,g,b);
}

//generates a random number & based on that random number, it decides the direction the ghost will go
//if we implement path-finding algorithm this will be deleted
void Ghost::randomizeDirection()
{
    int randomNumber = rand() % 5 + 2;
    if(randomNumber == 2) {
        direction = right;
    }
    if(randomNumber == 3) {
        direction = up;
    }
    if(randomNumber == 4) {
        direction = left;
    }
    if(randomNumber == 5) {
        direction = down;
    }
}
