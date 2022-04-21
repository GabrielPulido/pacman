#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWindow>
#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <QThread>
#include <QtOpenGL>
#include "glfw3.h"
#include "grid.h"
#include "pacman.h"
#include "square.h"
#include "ghost.h"
#include "game.h"


class MainWindow : public QOpenGLWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *);

public slots:
    void UpdateAnimation();

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    QOpenGLContext* context;
    QOpenGLFunctions* openGLFunctions;
    Pacman pacman;

    Ghost redGhost;
    Ghost blueGhost;
    Ghost orangeGhost;
    Ghost pinkGhost;
    Ghost allGhosts[4];

    Grid grid;
    Game game;

    QTimer* timer;
};
#endif // MAINWINDOW_H
