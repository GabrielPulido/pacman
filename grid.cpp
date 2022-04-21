#include "grid.h"
Grid::Grid()
{
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

    // initialize squares
    for (int i = 1; i <= columns; i++)
    {
        for (int j = 1; j <= rows; j++)
        {
            squares[i][j] = Square(i, j, false); // by default they aren't boundaries
        }
    }
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
// ex) an input of (1,1) will draw a square on the bottom left corner of the grid
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

//draws a blue square in a specific place and it sets that value in the squares[][] array to be a boundary
void Grid::drawBoundary(float desiredColumn, float desiredRow)
{
    float left = left_border + (squareWidth * (desiredColumn - 1));
    float top = bottom_border + (squareHeight * desiredRow);

    float bottom = top - squareHeight;
    float right = left + squareWidth;

    // register it as a boundary in our squares[][] array so that pacman or the ghosts don't go through it
    int x = (int)desiredColumn;
    int y = (int)desiredRow;

    squares[x][y].setBoundary(true); // lets the squares array know that this is a boundary

    // draw square
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(left, top);
    glVertex2f(left, bottom);
    glVertex2f(right, bottom);
    glVertex2f(right, top);
    glEnd();
}

// This function uses fixed values so if you change the size of the grid, it'll mess up the map
void Grid::drawMap()
{
    // draw horizontal strips
    for (int i = 9; i <= 18; i++)
    {
        drawBoundary(i, rows - 1); // top
        drawBoundary(i, 2);        // bottom
    }


    // draw upper right curl
    for (int i = rows - 1; i >= 23; i--)
    {
        drawBoundary(columns - 2, i); // draws vertical strip on the left
    }
    for (int i = rows; i >= 21; i--)
    {
        drawBoundary(columns, i); // draws vertical strip on the right
    }
    for (int i = columns - 1; i >= 21; i--)
    {
        drawBoundary(i, 21); // draws bottom horizontal strip
    }
    for (int i = columns - 2; i >= 21; i--)
    {
        drawBoundary(i, 23); // top horizontal strip
    }
    drawBoundary(21, 22); // square that connects the 2 above strips


    // draw upper left curl
    for (int i = rows; i >= 21; i--)
    {
        drawBoundary(1, i); // left vertical strip
    }
    for (int i = rows - 1; i >= 23; i--)
    {
        drawBoundary(3, i); // right vertical strip
    }
    for (int i = 2; i <= 5; i++)
    {
        drawBoundary(i, 21); // draws bottom horizontal strip
    }
    for (int i = 4; i <= 5; i++)
    {
        drawBoundary(i, 23); // top horizontal strip
    }
    drawBoundary(5, 22);


    // bottom left curl
    for (int i = 1; i <= 5; i++)
    {
        drawBoundary(1, i); // left strip
    }
    for (int i = 2; i <= 3; i++)
    {
        drawBoundary(3, i); // right strip
    }
    for (int i = 1; i <= 5; i++)
    {
        drawBoundary(i, 5); // top horizontal strip
    }
    for (int i = 3; i <= 5; i++)
    {
        drawBoundary(i, 3); // bottom horizontal strip
    }
    drawBoundary(5, 4);


    // draw bottom right curl
    for (int i = 1; i <= 5; i++)
    {
        drawBoundary(columns, i); // right vertical strip
    }
    for (int i = 2; i <= 3; i++)
    {
        drawBoundary(columns - 2, i); // left vertical strip
    }
    for (int i = columns-1; i >= 21; i--)
    {
        drawBoundary(i, 5); // top horizontal strip
    }
    for (int i = columns - 2; i >= 21; i--)
    {
        drawBoundary(i, 3); // bottom horizontal strip
    }
    drawBoundary(21, 4);

    // draw ghost box
    for (int i = 10; i <= 17; i++)
    {
        drawBoundary(i, 11);
        if (i != 13 && i != 14)
        {
            drawBoundary(i, 14);
        }
    }
    for(int i = 11; i <= 14; i++) {
        drawBoundary(10, i);
        drawBoundary(17, i);
    }
}

void Grid::drawDot(float desiredColumn, float desiredRow)
{
    float leftOfSquare = left_border + (squareWidth * (desiredColumn - 1));
    float topOfSquare = bottom_border + (squareHeight * desiredRow);
    float bottomOfSquare = topOfSquare - squareHeight;
    float rightOfSquare = leftOfSquare + squareWidth;

    float val = 0.4; // this value is what controls how big the dot is
    float left = leftOfSquare + (squareWidth * val);
    float right = rightOfSquare - (squareWidth * val);
    float top = topOfSquare - (squareWidth * val);
    float bottom = bottomOfSquare + (squareWidth * val);

    // draw square
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(left, top);
    glVertex2f(left, bottom);
    glVertex2f(right, bottom);
    glVertex2f(right, top);
    glEnd();
}

//draws dots based on squares[][] array
void Grid::drawAllDots()
{
    // Iterate through squares array
    for (int i = 1; i <= columns; i++)
    {
        for (int j = 1; j <= rows; j++)
        {
            if (squares[i][j].getBoundary() == false && squares[i][j].dot == true)
            {
                drawDot(i, j);  // draw dots where there isn't boundaries
            }
        }
    }
}

void Grid::eraseDot(float x, float y)
{
    squares[(int)x][(int)y].dot = false;
}

bool Grid::allDotsGone()
{
    for(int i = 1; i <= columns; i++) {
        for(int j = 1; j <= rows; j++) {
            if(squares[i][j].dot = true) {
                return false;
            }
        }
    }
    return true;
}
