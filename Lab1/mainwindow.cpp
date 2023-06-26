#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>  // подключаем библотеку

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


void MainWindow::on_pushButton_do_clicked()
{
    QString inputText;  // сюда зппишем то, что пользователь вводит
    QString outputText; // сюда зпишем то, что будет выведено
    int chislo;     // промежуточное число в 10й ссч

    inputText = ui->lineEdit_input->text(); //  считываем введённую строку
    bool flag;  // флаг корректности перевода (true - успешно, false - не успешно)
    chislo = inputText.toInt(&flag, 10);    // переводим из 16й в 10ю ссч

    if(flag == true)    // если перевод успешный
    {
        outputText.setNum(chislo, 2);   // выполняем перевод в 2ю ссч
    }
    else    // если перевод не успешный
    {
        outputText = "Ошибка!";
    }

    ui->label_output->setText(outputText);  // выводим результат
}

