#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void readMassive(double *mas, int *size, bool *error); //функция для считывания массива

    void writeMassive(double *mas, int size); //функция для вывода массива в таблицу


private slots:
    void on_spinBox_count_valueChanged(int arg1);

    void on_pushButton_random_clicked();


    void on_pushButton_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

    void on_pushButton_ok_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
