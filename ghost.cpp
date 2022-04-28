#include "ghost.h"
#include "stdlib.h"

Ghost::Ghost() : Character()
{

}

Ghost::Ghost(float x, float y, float r, float g, float b) : Character(x,y)
{
    setColor(r,g,b);
}

//generates the magnitude of the vector to pacman & based on that random number, it decides the direction the red ghost will go
void Ghost::redDirection(Character pacman, Grid &grid)
{
    int pacX = pacman.getx();
    int pacY = pacman.gety();

    double squaredX = pacX * pacX;
    double squaredY = pacY * pacY;

    int squared = sqrt(squaredX + squaredY);

    int randomNumber = squared % 5 + 2;
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

