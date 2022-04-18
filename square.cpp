#include "square.h"

Square::Square()
{
    x = 1.0f;
    y = 1.0f;
    boundary = false;
}

Square::Square(bool boundary)
{
    x = 1.0f;
    y = 1.0f;
    this->boundary = boundary;
}

Square::Square(float x, float y, bool boundary)
{
    this->x = x;
    this->y = y;
    this->boundary = boundary;
}
