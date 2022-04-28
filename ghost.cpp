#include "ghost.h"
#include "stdlib.h"

Ghost::Ghost() : Character()
{

}

Ghost::Ghost(float x, float y, float r, float g, float b) : Character(x,y)
{
    setColor(r,g,b);
}

//setting up a ghost that follows pacman
void Ghost::redDirection(Character pacman, Grid &grid)
{
   int newX = pacman.getx();
   int newY = pacman.gety();
  // int oldX, oldY;
   int hitwall = 0;

   for(int i = 0; i <= newY; i++){
       if (grid.squares[int(this->getx())][newY].getBoundary() == false)
       {
           this->sety(i);
           hitwall++;

       }

   }
}

