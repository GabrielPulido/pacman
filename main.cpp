#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setTitle("Pacman");
    w.resize(600, 600);
    w.show();
    return a.exec();
}
