#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QString>
#include <QTextStream>




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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
