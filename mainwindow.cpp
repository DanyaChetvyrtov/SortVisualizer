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
    if(!fileIsActive){
        ui->feedbackData->append("Нужно открыть файл.");
        return;
    }

    mainPart(1, activeRange, amountOfNums);
}

// Визуализация Гнома
void MainWindow::on_GnomSortButton_clicked()
{
    if(!fileIsActive){
        ui->feedbackData->append("Нужно открыть файл.");
        return;
    }

    mainPart(2, activeRange, amountOfNums);
}

// Открыть файл
void MainWindow::on_optionOpen_triggered()
{
    if (fileIsActive){
        ui->feedbackData->append("Невозможно открыть новый файл, пока не закрыт текущий.");
        return;
    }

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "C:\\Users\\123\\OneDrive\\Рабочий стол\\C++\\summer_practice\\TestAppSFML\\userFiles",
                                                    "Text files (*.txt)");
    activeFile.setFileName(fileName);

    QString fileData;
    if(activeFile.open(QIODevice::ReadOnly)){
        QTextStream stream(&activeFile);

        while(stream.atEnd() == false){
            fileData += stream.readLine() + " ";
        }
    }

    ui->fileTitle->setText("Файл: " + fileName.split( "/" ).value(fileName.split( "/" ).length() - 1 ));
    ui->fileData->setText(fileData);
    ui->feedbackData->append("Файл был успешно открыт.");

    amountOfNums = countIntegers(fileData.toStdString());
    activeRange = new int[amountOfNums];
    activeRange = extractNumbers(fileData.toStdString());
    fileIsActive = true;
}

// Закрыть файл
void MainWindow::on_optionClose_triggered()
{
    if(fileIsActive){

        activeFile.close();
        activeFile.setFileName("");

        ui->fileTitle->setText("");
        ui->fileData->setText("");
        ui->timeOfShell->setText("");
        ui->timeOfGnom->setText("");
        ui->alteredFileData->setText("");
        ui->feedbackData->append("Файл был успешно закрыт");

        fileIsActive = false;

    }else{
        ui->feedbackData->append("В настоящий момент нет подключённого файла");
    }
}

// Сортировать/сравнить время
void MainWindow::on_CompareButton_clicked()
{
    if(!fileIsActive){
        ui->feedbackData->append("Нечего сортировать. Откройте файл");
        return;
    }
    if(!ui->alteredFileData->text().isEmpty()){
        ui->feedbackData->append("Данные уже отсортированы");
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


    // Создание нового файла
    QFile sortedFile("C:\\Users\\123\\OneDrive\\Рабочий стол\\C++\\summer_practice\\TestAppSFML\\userFiles\\sorted_" +
                     activeFile.fileName().split( "/" ).value(activeFile.fileName().split( "/" ).length() - 1 ));
    sortedFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&sortedFile);
    out << QString::fromStdString(arrayToString(myArray, amountOfNums));


    ui->timeOfShell->setText(QString::fromStdString(std::to_string(elapsed.count())));
    ui->timeOfGnom->setText(QString::fromStdString(std::to_string(elapsed2.count())));
    ui->alteredFileData->setText(QString::fromStdString(arrayToString(myArray, amountOfNums)));
    ui->feedbackData->append("Сортировка была выполнена успешно.");


    delete[] myArray2;
    myArray = nullptr;
    myArray2 = nullptr;
}

