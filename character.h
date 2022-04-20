#ifndef CHARACTER_H
#define CHARACTER_H


class Character
{
public:
    Character();
    Character(float, float);

    void setx(float);
    void sety(float);
    float getx();
    float gety();

    //the direction pacman is going to
    enum Direction {right = 1, up = 2, left = 3, down = 4};
    Direction direction;

protected:
    float x;
    float y;

};

#endif // CHARACTER_H
