#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QOpenGLWindow()
{
    //Tells qt that we're using opengl instead of qpainter
    setSurfaceType(QWindow::OpenGLSurface);

    //format
    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(2,1);
    setFormat(format);

    //context
    context = new QOpenGLContext;
    context->setFormat(format);
    context->create();
    context->makeCurrent(this);
    openGLFunctions = context->functions();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initializeGL()
{
    resizeGL(this->width(), this->height());
}

//Ignore this code, it just makes it look good when it resizes
void MainWindow::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0,0,w,h);

    qreal aspectratio = qreal(w)/qreal(h);

    glOrtho(-1 * aspectratio, 1 * aspectratio, -1,1,1,-1);
}

void MainWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    Grid::draw();
    Grid::drawSquare(pacman.x, pacman.y);

    //always call this after you're done drawing everything
    glFlush();
}

//Ignore this code, it just makes it look good when it resizes
void MainWindow::resizeEvent(QResizeEvent *event)
{
    resizeGL(this->width(), this->height());
    this->update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    paintGL();
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    float increment = 0.01f;

    if (event->key() == Qt::Key_Up) {
        pacman.y--;
    }
    if (event->key() == Qt::Key_Down) {
        pacman.y++;
    }
    if (event->key() == Qt::Key_Left) {
        pacman.x--;
    }
    if (event->key() == Qt::Key_Right) {
        pacman.x++;
    }

    this->update();
}

