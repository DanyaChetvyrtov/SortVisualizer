#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Ставим иконку
    QIcon icon(":/icons/sort.ico");
    a.setWindowIcon(icon);

    MainWindow mainWindow;
    mainWindow.show();
    return a.exec();
}

