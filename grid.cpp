#include "grid.h"

float Grid::columns = 26.0;
float Grid::rows = 29.0;
float Grid::marginBottom = 0.075;
float Grid::marginTop = 0.075;
float Grid::marginLeft = 0.075;
float Grid::marginRight = 0.075;
float Grid::height = 2.0 - marginBottom - marginTop;
float Grid::width = 2.0 - marginLeft - marginRight;
float Grid::left_border = -1.0 + marginLeft;
float Grid::bottom_border = -1.0 + marginBottom;
float Grid::right_border = 1.0 - marginRight;
float Grid::top_border = 1.0 - marginTop;
float Grid::xIncrement = width / columns;
float Grid::yIncrement = height / rows;

// pacman grid is 26x29
// draws grid
void Grid::draw()
{

    float x = width / columns;
    float y = height / rows;

    // Draw vertical lines
    float current_left = left_border;
    for (int i = 0; i <= Grid::columns; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(current_left, top_border);
        glVertex2f(current_left, bottom_border);
        glEnd();
        current_left += x;
    }

    // Draw Horizontal lines
    double current_top = top_border;
    for (int i = 0; i <= Grid::rows; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(left_border, current_top);
        glVertex2f(right_border, current_top);
        glEnd();
        current_top -= y;
    }
}

// draws a square in the specific column & row you specify
void Grid::drawSquare(float desiredColumn, float desiredRow)
{
    float xIncrement = width / columns;
    float yIncrement = height / rows;

    float left = left_border + (xIncrement * (desiredColumn - 1));
    float top = bottom_border + (yIncrement * desiredRow);

    float bottom = top - yIncrement;
    float right = left + xIncrement;

    // draw square
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(left, top);
    glVertex2f(left, bottom);
    glVertex2f(right, bottom);
    glVertex2f(right, top);
    glEnd();
}

// void Grid::drawSquareV2(float x, float y)
//{
//     //draw square
//     glBegin(GL_QUADS);
//     glColor3f(1.0f, 1.0f, 0.0f);
//     glVertex2f(x, -y);
//     glVertex2f(left, bottom);
//     glVertex2f(right, bottom);
//     glVertex2f(right, top);
//     glEnd();
// }
