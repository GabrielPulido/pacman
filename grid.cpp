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
    //ghost box
    for (int i = 11; i <= 17; i++)
    {
        drawBoundary(i, 11);//bottom bar
        if (!(i >12)||!(i<16))
        {
            drawBoundary(i, 14);//top bar
        }
    }
    for(int i = 11; i <= 14; i++) {
        drawBoundary(11, i);//left side
        drawBoundary(17, i);//right side
    }

    //vertical lines next to ghost box
    for(int i = 10; i <= 12; i++) {
        drawBoundary(8, i);//left side
        drawBoundary(20, i);//right side
    }

    //top center stacked row
    for(int i = 13; i <= 15; i++)
    {
        drawBoundary(i, 25);
    }
    drawBoundary(14, 24);

    //horz lines at top
    for(int i = 3; i <= 25; i++)
    {
        if((i > 2 && i < 5)||(i > 23 && i < 26)){
            drawBoundary(i, 24);
            drawBoundary(i, 23);
            drawBoundary(i, 20);

        }

        if((i > 6 && i < 10) || (i > 18 && i < 22)){
            drawBoundary(i, 24);
            drawBoundary(i, 23);
        }
    }

    //symmetric top Ts
    for(int i = 8; i <= 20; i++)
    {
        if((i > 7 && i < 12) || (i > 16 && i < 21)){
            drawBoundary(i, 17);
        }
    }
    for(int i = 15; i <= 19; i++){
        drawBoundary(8, i);
        drawBoundary(20, i);
    }

    //middle top T
    for(int i = 12; i <= 16; i++){
        drawBoundary(i, 22);
    }
    for(int i = 18; i <= 22; i++){
        drawBoundary(14, i);
    }

    //T below ghost box
    for (int i = 11; i <= 17; i++)
    {
        drawBoundary(i, 8);//horizontal

    }
    for (int i = 5; i <=8; i++)
    {
        drawBoundary(14,i);//vertical
    }

    //horz lines next to bottom T
    for (int i = 8; i <= 20; i++){
        if (i==8||i==9||i==19||i==20){
            drawBoundary(i, 6);
        }
    }

    //cup under T
    for (int i = 11; i <= 17; i++)
    {
        drawBoundary(i, 3);//horizontal

    }
    drawBoundary(11, 4);
    drawBoundary(17,4);

    //parts on same row as cup
    //horz
    for(int i = 3; i <= 25; i++)
    {
        if(i > 2 && i < 9){
            drawBoundary(i, 3);
        }
        if(i > 18 && i < 25){
            drawBoundary(i, 3);
        }
    }
    //vert
    drawBoundary(6, 4);
    drawBoundary(21, 4);

    //right angles
    //horz
    for(int i = 3; i <= 25; i++)
    {
        if(i > 2 && i < 6){
            drawBoundary(i, 8);
        }
        if(i < 26 && i > 22){
            drawBoundary(i, 8);
        }
    }
    //vert
    for(int i = 6; i <= 8; i++){
        drawBoundary(5,i);
        drawBoundary(23, i);
    }

    //lines by right angle corner
    for(int i = 1; i <=27; i++)
    {
        if(i < 4){
            drawBoundary(i,5);
        }
        if(i > 24){
            drawBoundary(i,5);
        }
    }

    //boundaries
    //bottom boxes next to vertical lines
        //vertical part
    for(int i = 10; i <= 12; i++) {
        drawBoundary(4, i);//left side
        drawBoundary(24, i);//right side
    }

        //horizontal part
    for (int i = 1; i <= 27; i++)
    {
        if (!(i >4)||!(i<24))
        {
            drawBoundary(i, 12);//top bar
            drawBoundary(i, 11);//fill bar
            drawBoundary(i, 10);//bottom bar
        }
    }

    //bottom boundaries
        //vertical boundaries
    for(int i = 1; i <= 12; i++) {
        drawBoundary(1, i);//left side
        drawBoundary(27, i);//right side
    }
        //horizontal boundaries
    for (int i = 1; i <= 27; i++)
    {
        drawBoundary(i, 1);//bottom line
    }

    //top boxes next to vertical lines
        //vertical part
    for(int i = 15; i <= 17; i++) {
        drawBoundary(4, i);//left side
        drawBoundary(24, i);//right side
    }

        //horizontal part
    for (int i = 1; i <= 27; i++)
    {
        if (!(i >4)||!(i<24))
        {
            drawBoundary(i, 15);//top bar
            drawBoundary(i, 16);//fill bar
            drawBoundary(i, 17);//bottom bar
        }
    }

    //top boundaries
        //vertical boundaries
    for(int i = 15; i <= 26; i++) {
        drawBoundary(1, i);//left side
        drawBoundary(27, i);//right side
    }
        //horizontal boundaries
    for (int i = 1; i <= 27; i++)
    {
        drawBoundary(i, 26);//bottom line
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
                if(!(i > 11 && j >= 12) || !(i < 17 && j <= 14)){
                drawDot(i, j);  // draw dots where there isn't boundaries
                }
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
