#ifndef GRID_H
#define GRID_H

#include <QOpenGLFunctions>
#include "square.h"

class Grid
{
public:
    Grid();

    float columns = 25.0;
    float rows = 25.0;

    float marginBottom;
    float marginTop;
    float marginLeft;
    float marginRight;

    float height; // percentage of page in terms of opengl
    float width;  // in terms of opengl

    // The outside borders of the grid
    float top_border;
    float left_border;
    float bottom_border;
    float right_border;

    // Height/width of each square in the grid
    float squareWidth;
    float squareHeight;

    void draw();
    void drawSquare(float col, float row, float r, float g, float b); // Draws a square at a specific column & row
    void drawBoundary(float x, float y);                            // draws a square at a specific coordinate based on opengl coordinate system
    void drawMap();
    void drawDot(float, float);
    void drawAllDots();
    void eraseDot(float, float);

    Square squares[26][26];
};

#endif // GRID_H
