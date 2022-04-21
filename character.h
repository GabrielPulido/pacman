#ifndef CHARACTER_H
#define CHARACTER_H

#include "grid.h"

class Character
{
public:
    Character();
    Character(float, float);

    //get/set current x & y coordinates
    void setx(float);
    void sety(float);
    float getx();
    float gety();

    //get starting position x & y coordinates
    float getxStartingPosition();
    float getyStartingPosition();

    //reset character to their starting coordinates
    void resetCoordinates();


    void setColor(float, float, float);

    //gets rgb color values of character
    float getRed();
    float getGreen();
    float getBlue();

    void updatePosition(Grid& grid);

    float color[3]; //every character as a color array of 3 elements where they set the r, g, and b values

    //the direction the character is going to (none by default)
    enum Direction {none = 1, right = 2, up = 3, left = 4, down = 5};
    Direction direction;

protected:

    //every character has an x & y coordinate on the grid
    //pacman & ghosts inherit from character
    float x;
    float y;

    //starting position
    float startingX;
    float startingY;

};

#endif // CHARACTER_H
