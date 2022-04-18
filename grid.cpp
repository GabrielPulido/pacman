#include "grid.h"
Grid::Grid()
{
    columns = 28.0;
    rows = 31.0;
    marginBottom = 0.075;
    marginTop = 0.075;
    marginLeft = 0.075;
    marginRight = 0.075;
    height = 2.0 - marginBottom - marginTop;
    width = 2.0 - marginLeft - marginRight;
    left_border = -1.0 + marginLeft;
    bottom_border = -1.0 + marginBottom;
    right_border = 1.0 - marginRight;
    top_border = 1.0 - marginTop;
    squareWidth = width / columns;
    squareHeight = height / rows;

    Square squares[(int)columns][(int)rows];
}

// draws grid
void Grid::draw()
{

    float x = width / columns;
    float y = height / rows;

    // Draw vertical lines
    float current_left = left_border;
    for (int i = 0; i <= columns; i++)
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
    for (int i = 0; i <= rows; i++)
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
//ex) an input of (1,1) will draw a square on the bottom left corner of the grid
void Grid::drawSquare(float desiredColumn, float desiredRow, float r, float g, float b)
{

    float left = left_border + (squareWidth * (desiredColumn - 1));
    float top = bottom_border + (squareHeight * desiredRow);

    float bottom = top - squareHeight;
    float right = left + squareWidth;

    // draw square
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(left, top);
    glVertex2f(left, bottom);
    glVertex2f(right, bottom);
    glVertex2f(right, top);
    glEnd();
}

 void Grid::drawSquareBlue(float desiredColumn, float desiredRow)
{
     float left = left_border + (squareWidth * (desiredColumn - 1));
     float top = bottom_border + (squareHeight * desiredRow);

     float bottom = top - squareHeight;
     float right = left + squareWidth;

     // draw square
     glBegin(GL_QUADS);
     glColor3f(0.0f, 0.0f, 1.0f);
     glVertex2f(left, top);
     glVertex2f(left, bottom);
     glVertex2f(right, bottom);
     glVertex2f(right, top);
     glEnd();
 }

 //This function uses fixed values so if you change the size of the grid, it'll mess up the map
 void Grid::drawMap()
 {   
//     //draw upside down T on the bottom right (blue)
//     for(int i = columns-2; i >= 16; i--) {
//         drawSquare(i, 3, 0.0f, 0.0f, 1.0f);
//     }

//     //draw upside down T on the bottom left (blue)
//     for(int i = 3; i <= 12; i++) {
//         drawSquare(i, 3, 0.0f, 0.0f, 1.0f);
//     }

//     //draw bottom & top strip of blue squares
//     for(int i = 1; i <= columns; i++) {
//         drawSquare(i, 1, 0.0f, 0.0f, 1.0f);
//         drawSquare(i, rows, 0.0f, 0.0f, 1.0f);
//     }

//     //draw left & right strips of blue squares
//     for(int i = 1; i <= rows; i++) {
//         drawSquare(1, i, 0.0f, 0.0f, 1.0f);
//         drawSquare(columns, i, 0.0f, 0.0f, 1.0f);
//     }

//    //draw bottom strip of white squares
//    for(int i = 2; i < columns; i++) {
//        drawSquare(i, 2, 1.0f, 1.0f, 1.0f);
//    }
 }
