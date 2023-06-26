#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>//подключаем библиотеку с окошками сообщений

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
    void on_pushButton_clear_clicked();

    void on_pushButton_creat_clicked();

    void on_lineEdit_str_textChanged(const QString &arg1);

    void on_lineEdit_dex_textChanged(const QString &arg2);

    void on_lineEdit_int_textChanged(const QString &arg3);

    void on_lineEdit_luck_textChanged(const QString &arg4);

    void on_radioButton_sex_m_clicked(bool checked);

    void on_radioButton_sex_f_clicked(bool checked);

private:
    Ui::MainWindow *ui;

    //глобальные переменные для первичных характеристик
    int str = 0;
    int dex = 0;
    int intel = 0;
    int luck = 0;
};
#endif // MAINWINDOW_H
