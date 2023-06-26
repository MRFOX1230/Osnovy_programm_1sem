#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QVector<double> array;

    double EPS = 0.0000001;

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_spinBoxNumberOfElements_valueChanged(int arg1);

    void updateArray();

    void on_pushButtonRandom_clicked();

    void on_pushButtonSearch_clicked();

    int fact(int number);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
