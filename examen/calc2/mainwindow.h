#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_do_clicked();

    void on_radioButton_sum_clicked();

    void on_radioButton_sub_clicked();

    void on_radioButton_mul_clicked();

    void on_radioButton_div_clicked();

    void on_radioButton_sin_clicked();

    void on_radioButton_cos_clicked();

    void on_radioButton_tg_clicked();

    void on_radioButton_ctg_clicked();

    void on_radioButton_arcsin_clicked();

    void on_radioButton_arccos_clicked();

    void on_radioButton_deg_clicked();

    void on_radioButton_sqrt_clicked();

    void on_pushButton_clear_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
