#include "mainwindow.h"
#include "service.h"
#include "ui_mainwindow.h"


#include <QFileDialog>

#include <chrono>
#include <algorithm>
#include <string.h>


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


void MainWindow::on_optionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C:\\Users\\123\\OneDrive\\Рабочий стол\\C++\\summer_practice\\TestAppSFML\\userFiles", "Text files (*.txt)");

}


void MainWindow::on_CompareButton_clicked()
{
    using namespace std::chrono;

    const int ARRAY_SIZE = 2000;

    int myArray[ARRAY_SIZE];
    int myArray2[ARRAY_SIZE];


    // Массив заполняется
    for(int i = 0; i < ARRAY_SIZE; i++){
        myArray[i] = std::rand() % 100;
    }

    std::copy(myArray, myArray + ARRAY_SIZE, myArray2);

    system_clock::time_point start = system_clock::now();
    ShellSort(myArray, ARRAY_SIZE);
    system_clock::time_point end = system_clock::now();

    duration<double> elapsed = duration_cast<duration<double>>(end - start);


    start = system_clock::now();
    GnomeSort(myArray, ARRAY_SIZE);
    end = system_clock::now();

    duration<double> elapsed2 = duration_cast<duration<double>>(end - start);


    ui->timeOfShell->setText(QString::fromStdString(std::to_string(elapsed.count())));
    ui->timeOfGnom->setText(QString::fromStdString(std::to_string(elapsed2.count())));

}

