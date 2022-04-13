#include "grid.h"

double Grid::columns = 26.0;
double Grid::rows = 29.0;
double Grid::marginBottom = 0.075;
double Grid::marginTop = 0.075;
double Grid::height = 2.0 - marginBottom - marginTop;
double Grid::width = 2.0;
double Grid::left_border = -1.0;
double Grid::bottom_border = -1.0 + marginBottom;
double Grid::right_border = 1.0;
double Grid::top_border = 1.0 - marginTop;

//pacman grid is 26x29
//draws grid
void Grid::draw() {

    double x = width/columns;
    double y = height/rows;

    double current_left = left_border;
    double current_bottom = top_border - y;
    double current_right = left_border + x;
    double current_top = top_border;

    //Draw vertical lines
    for(int i = 0; i <= Grid::columns; i++) {
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(current_left, top_border);
        glVertex2d(current_left, bottom_border);
        glEnd();
        current_left += x;
    }

    //Draw Horizontal lines
    for(int i = 0; i <= Grid::rows; i++) {
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(left_border, current_top);
        glVertex2d(right_border, current_top);
        glEnd();
        current_top -= y;
    }
    glEnd();
}

//returns the center of a specific coordinate on the grid so that you can draw it with opengl
void Grid::drawSquare(double desiredColumn, double desiredRow) {
    double xIncrement = width / columns;
    double left = left_border + (xIncrement * desiredColumn); //left side of square

    double yIncrement = height / rows;
    double top = top_border - (yIncrement * desiredRow); //topside of square

    double bottom = top - yIncrement;
    double right = left + xIncrement;

    //draw square
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2d(left, top);
    glVertex2d(left, bottom);
    glVertex2d(right, bottom);
    glVertex2d(right, top);
    glEnd();
}
