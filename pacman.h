#ifndef PACMAN_H
#define PACMAN_H

#include <string.h>

class Pacman
{
    //pacman's location
    float x;
    float y;

public:

    Pacman();
    Pacman(float, float);

    void setx(float);
    void sety(float);
    float getx();
    float gety();


    //the direction pacman is going to
    enum Direction {right = 1, up = 2, left = 3, down = 4};
    Direction direction;
};

#endif // PACMAN_H
