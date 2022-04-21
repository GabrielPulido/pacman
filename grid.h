#ifndef GRID_H
#define GRID_H

#include <QOpenGLFunctions>
#include "square.h"

class Grid
{
public:
    Grid();

    float columns = 27.0;
    float rows = 26.0;

    //These margins relative to the percentage of the screen (ie 0.05 marginBottom = 5% margin on the bottom)
    //Can be changed without messing up the grid
    float marginBottom;
    float marginTop;
    float marginLeft;
    float marginRight;

    //height/width of the window in terms of opengl's coordinate system
    float height;
    float width;

    // The outside borders/edges of the grid
    float top_border;
    float left_border;
    float bottom_border;
    float right_border;

    // Height/width of each square in the grid (opengl coordinates)
    float squareWidth;
    float squareHeight;

    void draw(); //draws the grid
    void drawSquare(float col, float row, float r, float g, float b); // Draws a square at a specific column & row, takes in rgb values for color
    void drawBoundary(float x, float y); // same as above but it registers it as a boundary
    void drawMap();
    void drawDot(float, float);
    void drawAllDots();
    void eraseDot(float, float);
    bool allDotsGone(); //checks if all dots are gone

    Square squares[28][27]; //a 2d array that represents each square in the grid,
                            //(their values should follow this formula: squares[columns+1][rows+1]
                            //Don't forget to change these values if the grid size changes
};

#endif // GRID_H
