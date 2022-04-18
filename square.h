#ifndef SQUARE_H
#define SQUARE_H


class Square
{
public:
    Square();
    Square(bool boundary);
    Square(float x, float y, bool boundary);

    bool boundary;

    //x and y coordinates of this square
    float x;
    float y;

};

#endif // SQUARE_H
