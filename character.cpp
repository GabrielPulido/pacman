#include "character.h"
#include "grid.h"

//Default coordinates of a character are (13,7) if none are specified
Character::Character()
{
    x = 13.0f;
    y = 7.0f;
    startingX = 13.0f;
    startingY = 7.0f;
    Direction direction;
}

Character::Character(float x, float y)
{
    this->x = x;
    this->y = y;
    this->startingX = x;
    this->startingY = y;
    Direction direction;
}

//we have setx & sety functions bc it prevents the user from going outside of the grid
//be sure to change the 25 value if you resize the grid
void Character::setx(float x)
{
    if(x > 27) {
        x = 27;
    }
    if(x < 1) {
        x = 1;
    }
    this->x = x;
}

void Character::sety(float y)
{
    if(y > 26) {
        y = 26;
    }
    if(y < 1) {
        y = 1;
    }
    this->y = y;
}

float Character::getx()
{
    return x;
}

float Character::gety()
{
    return y;
}

float Character::getxStartingPosition()
{
    return startingX;
}

float Character::getyStartingPosition()
{
    return startingY;
}

void Character::resetCoordinates()
{
    x = startingX;
    y = startingY;
}


void Character::setColor(float r, float g, float b)
{
    color[0] = r;
    color[1] = g;
    color[2] = b;
}

float Character::getRed()
{
    return color[0];
}

float Character::getGreen()
{
    return color[1];
}

float Character::getBlue()
{
    return color[2];
}

//updates the xy coordinates/position of the character based on their direction property
void Character::updatePosition(Grid& grid)
{
    float num = 1.0f;
    int x = (int)this->x;
    int y = (int)this->y;

    // changes pacman's direction based on what key you clicked
    if (direction == up)
    {
        int newY = y + num;

        //these if statements prevents characters from going through the blue barriers
        if (grid.squares[x][newY].getBoundary() == false)
        {
            sety(newY);
        }
    }
    if (direction == down)
    {
        int newY = y - num;
        if (grid.squares[x][newY].getBoundary() == false)
        {
            sety(newY);
        }
    }
    if (direction == left)
    {
        int newX = x - num;
        if (grid.squares[newX][y].getBoundary() == false)
        {
            setx(newX);
        }
    }
    if (direction == right)
    {
        int newX = x + num;
        if (grid.squares[newX][y].getBoundary() == false)
        {
            setx(newX);
        }
    }
}

