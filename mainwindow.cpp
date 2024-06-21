#include "build/Desktop_Qt_6_7_1_MinGW_64_bit-Release/ui_mainwindow.h"
#include "mainwindow.h"
#include "service.h"
#include "ui_mainwindow.h"


QFile activeFile;
int *activeRange;
int amountOfNums;
bool fileIsActive = false;


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

// Визуализация Шелла
void MainWindow::on_ShellSortButton_clicked()
{
   mainPart(1, activeRange, amountOfNums);
}

// Визуализация Гнома
void MainWindow::on_GnomSortButton_clicked()
{
    mainPart(2, activeRange, amountOfNums);
}

// Открыть файл
void MainWindow::on_optionOpen_triggered()
{

    if (fileIsActive){
        ui->feedbackData->append("Невозможно открыть новый файл, пока не закрыт текущий.\n");
        return;
    }
    else{

        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C:\\Users\\123\\OneDrive\\Рабочий стол\\C++\\summer_practice\\TestAppSFML\\userFiles", "Text files (*.txt)");

        activeFile.setFileName(fileName);

        if(activeFile.open(QIODevice::ReadOnly)){
            QTextStream stream(&activeFile);
            QString fileData;
            while(stream.atEnd() == false){
                fileData += stream.readLine() + " ";
            }

            ui->fileTitle->setText("Файл: " + fileName.split( "/" ).value( fileName.split( "/" ).length() - 1 ));
            ui->fileData->setText(fileData);
            ui->feedbackData->append("Файл был успешно открыт\n");

            amountOfNums = countIntegers(fileData.toStdString());
            activeRange = extractNumbers(fileData.toStdString(), amountOfNums);

        }
        fileIsActive = true;
    }
}

// Сортировать/сравнить время
void MainWindow::on_CompareButton_clicked()
{
    if(!fileIsActive){
        ui->feedbackData->append("Нечего сортировать. Откройте файл\n");
        return;
    }
    if(!ui->alteredFileData->text().isEmpty()){
        ui->feedbackData->append("Данные уже отсортированы\n");
        return;
    }

    using namespace std::chrono;


    int *myArray = new int[amountOfNums];
    int *myArray2 = new int[amountOfNums];

    myArray = activeRange;

    std::copy(myArray, myArray + amountOfNums, myArray2);


    system_clock::time_point start = system_clock::now();
    ShellSort(myArray, amountOfNums);
    system_clock::time_point end = system_clock::now();
    duration<double> elapsed = duration_cast<duration<double>>(end - start);

    start = system_clock::now();
    GnomeSort(myArray2, amountOfNums);
    end = system_clock::now();
    duration<double> elapsed2 = duration_cast<duration<double>>(end - start);


    ui->timeOfShell->setText(QString::fromStdString(std::to_string(elapsed.count())));
    ui->timeOfGnom->setText(QString::fromStdString(std::to_string(elapsed2.count())));
    ui->alteredFileData->setText(QString::fromStdString(arrayToString(myArray, amountOfNums)));

    delete[] myArray;
    delete[] myArray2;
    myArray = nullptr;
    myArray2 = nullptr;
}

// Закрыть файл
void MainWindow::on_optionClose_triggered()
{
    if(fileIsActive){

        activeFile.close();
        activeFile.setFileName("");

        ui->fileTitle->setText("");
        ui->fileData->setText("");
        ui->alteredFileData->setText("");
        ui->feedbackData->append("Файл был успешно закрыт\n");


        fileIsActive = false;
    }else{
        ui->feedbackData->append("В настоящий момент нет подключённого файла\n");
    }
}

