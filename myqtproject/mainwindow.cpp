#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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


void MainWindow::on_Button_ok_clicked()
{
    QString inputText;
    QString outputText;
    QString a;
    QString b;
    int chislo, op1, op2;

    inputText = ui->lineEdit->text();
    bool flag;
    a = ui->ss1->text();
    b = ui->ss2->text();
    op1 = a.toInt(&flag, 10);
    op2 = b.toInt(&flag, 10);
    chislo = inputText.toInt(&flag, op1);

    if(flag == true)
    {
        outputText.setNum(chislo, op2);
    }

    else
    {
        outputText = "Ошибка";
    }
    ui->label->setText(outputText);

}
