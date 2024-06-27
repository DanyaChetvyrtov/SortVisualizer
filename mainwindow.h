#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QApplication>
#include <QFileDialog>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QIcon>
#include <QFile>
#include <QDir>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ShellSortButton_clicked();

    void on_GnomSortButton_clicked();

    void on_optionOpen_triggered();

    void on_optionClose_triggered();

    void on_CompareButton_clicked();

    void on_ShellSortButtonInfo_clicked();

    void on_GnomSortButtonInfo_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
