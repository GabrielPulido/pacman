#include "square.h"

Square::Square()
{
    x = 1.0f;
    y = 1.0f;
    boundary = false;
    dot = false;
}

Square::Square(bool boundary)
{
    x = 1.0f;
    y = 1.0f;
    this->boundary = boundary;
    dot = true;
}

Square::Square(float x, float y, bool boundary)
{
    this->x = x;
    this->y = y;
    this->boundary = boundary;
    dot = true;
}

void Square::setBoundary(bool val)
{
    boundary = val;
    if(boundary == true) {
        dot = false;
    }

}

bool Square::getBoundary()
{
    return boundary;
}
