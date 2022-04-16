#ifndef PACMAN_H
#define PACMAN_H

#include <string.h>

class Pacman
{
public:

    Pacman();
    Pacman(double, double);

    //pacman's location
    double x;
    double y;

    //the direction pacman is going to
    enum Direction {right = 1, up = 2, left = 3, down = 4};
    Direction direction;
};

#endif // PACMAN_H
