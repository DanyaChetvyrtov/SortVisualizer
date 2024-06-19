#include "mainwindow.h"
#include "service.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ShellSortButton_clicked()
{
   mainPart(1);
}


void MainWindow::on_GnomSortButton_clicked()
{
    mainPart(2);
}

