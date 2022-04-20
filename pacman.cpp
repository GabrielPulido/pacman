#include "pacman.h"

Pacman::Pacman()
{
    x = 13.0;
    y = 7.0;
    Direction direction;
    Direction oldDirection;
}

Pacman::Pacman(float x, float y) {
    this->x = x;
    this->y = y;
    Direction direction;
}

void Pacman::setx(float x)
{
    if(x > 25) {
        x = 25;
    }
    if(x < 1) {
        x = 1;
    }
    this->x = x;
}

void Pacman::sety(float y)
{
    if(y > 25) {
        y = 25;
    }
    if(y < 1) {
        y = 1;
    }
    this->y = y;
}

float Pacman::getx()
{
    return x;
}

float Pacman::gety()
{
    return y;
}
