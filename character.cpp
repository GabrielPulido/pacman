#include "character.h"

Character::Character()
{
    x = 13.0;
    y = 7.0;
    Direction direction;
}

Character::Character(float x, float y)
{
    this->x = x;
    this->y = y;
    Direction direction;
}

void Character::setx(float x)
{
    if(x > 25) {
        x = 25;
    }
    if(x < 1) {
        x = 1;
    }
    this->x = x;
}

void Character::sety(float y)
{
    if(y > 25) {
        y = 25;
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

