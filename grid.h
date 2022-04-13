#ifndef GRID_H
#define GRID_H

#include <QOpenGLFunctions>

class Grid
{
public:

    //numbering for columns & rows starts at 0
    // ex) there's 16 columns but to access the last one you'd say you want index 15
    static double columns;
    static double rows;

    static double marginBottom;
    static double marginTop;

    static double height; //percentage of page in terms of opengl
    static double width; //in terms of opengl

    //The outside borders of the grid
    static double top_border;
    static double left_border;
    static double bottom_border;
    static double right_border;

    static void draw();
    static void drawSquare(double col, double row); //Draws a square at a specific column & row

};

#endif // GRID_H
