#include "mainwindow.h"

#include <QApplication>
#include <QIcon>
#include <SFML/Graphics.hpp>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Ставим иконку
    QIcon icon(":/icons/sort.ico");
    a.setWindowIcon(icon);

    MainWindow w;
    w.show();
    return a.exec();
}

