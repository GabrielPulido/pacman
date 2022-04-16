#include "grid.h"

double Grid::columns = 26.0;
double Grid::rows = 29.0;
double Grid::marginBottom = 0.075;
double Grid::marginTop = 0.075;
double Grid::marginLeft = 0.075;
double Grid::marginRight = 0.075;
double Grid::height = 2.0 - marginBottom - marginTop;
double Grid::width = 2.0 - marginLeft - marginRight;
double Grid::left_border = -1.0 + marginLeft;
double Grid::bottom_border = -1.0 + marginBottom;
double Grid::right_border = 1.0 - marginRight;
double Grid::top_border = 1.0 - marginTop;
double Grid::xIncrement = width / columns;
double Grid::yIncrement = height / rows;

//pacman grid is 26x29
//draws grid
void Grid::draw() {

    double x = width/columns;
    double y = height/rows;

    //Draw vertical lines
    double current_left = left_border;
    for(int i = 0; i <= Grid::columns; i++) {
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(current_left, top_border);
        glVertex2d(current_left, bottom_border);
        glEnd();
        current_left += x;
    }

    //Draw Horizontal lines
    double current_top = top_border;
    for(int i = 0; i <= Grid::rows; i++) {
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(left_border, current_top);
        glVertex2d(right_border, current_top);
        glEnd();
        current_top -= y;
    }
}

//draws a square in the specific column & row you specify
void Grid::drawSquare(double desiredColumn, double desiredRow) {
    double xIncrement = width / columns;
    double left = left_border + (xIncrement * desiredColumn); //left side of square

    double yIncrement = height / rows;
    double top = top_border - (yIncrement * desiredRow); //topside of square

    double bottom = top - yIncrement;
    double right = left + xIncrement;

    //draw square
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2d(left, top);
    glVertex2d(left, bottom);
    glVertex2d(right, bottom);
    glVertex2d(right, top);
    glEnd();
}
