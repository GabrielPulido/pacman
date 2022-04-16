#ifndef GRID_H
#define GRID_H

#include <QOpenGLFunctions>

class Grid
{
public:
    // numbering for columns & rows starts at 0
    //  ex) there's 16 columns but to access the last one you'd say you want index 15
    static float columns;
    static float rows;

    static float marginBottom;
    static float marginTop;
    static float marginLeft;
    static float marginRight;

    static float height; // percentage of page in terms of opengl
    static float width;  // in terms of opengl

    // The outside borders of the grid
    static float top_border;
    static float left_border;
    static float bottom_border;
    static float right_border;

    // How much to increment
    static float xIncrement;
    static float yIncrement;

    static void draw();
    static void drawSquare(float col, float row); // Draws a square at a specific column & row
    static void drawSquareV2(float x, float y);   // draws a square at a specific coordinate based on opengl coordinate system
};

#endif // GRID_H
