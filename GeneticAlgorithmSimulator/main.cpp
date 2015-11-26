#include "mainwindow.h"
#include <QApplication>
#include "chromosomepopulation.h"
#include "uniformintgenerator.h"
#include "gasimulator.h"
#include <vector>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
