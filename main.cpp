// tic-tac-toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}