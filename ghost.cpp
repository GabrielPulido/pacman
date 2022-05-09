#include "ghost.h"
#include "stdlib.h"
#include "grid.h"
#include "math.h"

Ghost::Ghost() : Character()
{

}

Ghost::Ghost(float x, float y, float r, float g, float b) : Character(x,y)
{
    setColor(r,g,b);
}

//generates the magnitude of the vector to pacman & based on that random number, it decides the direction the ghost will go
//if we implement path-finding algorithm this will be deleted
void Ghost::redDirection(Character pacman, Grid &grid)
{
    /*int horz = pacman.getx();
    int vert = pacman.gety();

    double squaredX = pacX * pacX;
    double squaredY = pacY * pacY;

    int squared = sqrt(squaredX + squaredY);


    int horzRem = horz % 5 + 2;
    int vertRem = vert % 5 + 2;
    if(horzRem == 2) {
        direction = right;
    }
    if(vertRem == 3) {
        direction = up;
    }
    if(horzRem == 4) {
        direction = left;
    }
    if(vertRem == 5) {
        direction = down;
    }*/
    int pacX = pacman.getx();
    int pacY = pacman.gety();

    double squaredX = pacX * pacX;
    double squaredY = pacY * pacY;

    int squared = sqrt(squaredX + squaredY);

    int randomNumber = squared % 5;
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

void Ghost::pinkDirection(Character pacman, Grid &grid)
{
    int pacX = pacman.getx();
    int pacY = pacman.gety();

    double squaredX = pacX * pacX;
    double squaredY = pacY * pacY;

    int squared = sqrt(squaredX + squaredY) + 4;

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
void Ghost::blueDirection(Character pacman, Grid &grid)
{
    int pacX = pacman.getx();
    int pacY = pacman.gety();

    double squaredX = pacX * pacX;
    double squaredY = pacY * pacY;

    int squared = sqrt(squaredX + squaredY) + 65;

    int randomNumber = squared % 5;
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
void Ghost::orangeDirection(Character pacman, Grid &grid)
{
    int pacX = pacman.getx();
    int pacY = pacman.gety();
    if(pacX == pacman.getxStartingPosition() && pacY == pacman.getyStartingPosition()){
        direction = right;
    }
    if(pacX == 14){
        direction = up;
    }

    double squaredX = pacX * pacX;
    double squaredY = pacY * pacY;

    int squared = sqrt(squaredX + squaredY) + 75;

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
