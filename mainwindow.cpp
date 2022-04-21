#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QOpenGLWindow()
{
    // Tells qt that we're using opengl instead of qpainter
    setSurfaceType(QWindow::OpenGLSurface);

    // format
    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(2, 1);
    setFormat(format);

    // context
    context = new QOpenGLContext;
    context->setFormat(format);
    context->create();
    context->makeCurrent(this);
    openGLFunctions = context->functions();

    // start timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateAnimation()));
    timer->start(100);

    //set up ghost
    redGhost = Ghost(7.0f, 6.0f, 1.0f, 0.0f, 0.0f);
    blueGhost = Ghost(22.0f, 13.0f, 0.0f, 1.0f, 1.0f);
    orangeGhost = Ghost(5.0f, 13.0f, 1.0f, 0.5f, 0.0f);
    pinkGhost = Ghost(13.0f, 18.0f, 1.0f, 0.0f, 0.5f);

    allGhosts[0] = redGhost;
    allGhosts[1] = blueGhost;
    allGhosts[2] = orangeGhost;
    allGhosts[3] = pinkGhost;
}

MainWindow::~MainWindow()
{
}

void MainWindow::initializeGL()
{
    resizeGL(this->width(), this->height());
}

// Ignore this code, it just makes it look good when it resizes
void MainWindow::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);

    qreal aspectratio = qreal(w) / qreal(h);

    glOrtho(-1 * aspectratio, 1 * aspectratio, -1, 1, 1, -1);
}

void MainWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    grid.draw();
    grid.drawMap();

    //If pacman touches a ghost, decrement lives & reset coordinates
    if(pacman.isTouchingGhost(allGhosts) == true) {
        pacman.lives--;
        pacman.lost = true;
    }

    grid.drawAllDots();

    //draw pacman
    grid.drawSquare(pacman.getx(), pacman.gety(), pacman.getRed(), pacman.getGreen(), pacman.getBlue());

    //draw all 4 ghosts
    for(int i = 0; i < 4; i++) {
        grid.drawSquare(allGhosts[i].getx(), allGhosts[i].gety(), allGhosts[i].getRed(), allGhosts[i].getGreen(), allGhosts[i].getBlue());
    }

    //if pacman has no more lives
    if(pacman.lives < 0)  {
        pacman.lives = 3; //reset to 3 lives
        pacman.lost = true;

        //reset all the dots:
        for(int i = 1; i <= grid.columns; i++) {
            for(int j = 1; j <= grid.rows; j++) {
                    grid.squares[i][j].dot = true;
            }
        }
    }

    //If the user loses, give them 3 seconds to get ready to play again
    if(pacman.lost == true) {
        //reset coordinates for all characters
        pacman.resetCoordinates();
        for(int i = 0; i < 4; i++) {
            allGhosts[i].resetCoordinates();
        }

        QThread::sleep(2);
        pacman.lost = false;
    }

    // always call this after you're done drawing everything
    glFlush();
}

// Ignore this code, it just makes it look good when it resizes
void MainWindow::resizeEvent(QResizeEvent *event)
{
    resizeGL(this->width(), this->height());
    this->update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    paintGL();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up)
    {
        pacman.direction = pacman.up;
    }
    if (event->key() == Qt::Key_Down)
    {
        pacman.direction = pacman.down;
    }
    if (event->key() == Qt::Key_Left)
    {
        pacman.direction = pacman.left;
    }
    if (event->key() == Qt::Key_Right)
    {
        pacman.direction = pacman.right;
    }
}

void MainWindow::UpdateAnimation()
{
    pacman.updatePosition(grid);

    //randomize each ghost's direction then update their position on the grid
    for(int i = 0; i < 4; i++) {
        allGhosts[i].randomizeDirection();
        allGhosts[i].updatePosition(grid);
    }

    //erase the dot
    grid.eraseDot(pacman.getx(), pacman.gety());

    this->update();
}
