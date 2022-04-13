#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
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
    //we call these functions to remove the previously rendered buffer
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Grid::draw();
    Grid::drawSquare(1.0, 1.0);
    Grid::drawSquare(25.0, 28.0);

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

