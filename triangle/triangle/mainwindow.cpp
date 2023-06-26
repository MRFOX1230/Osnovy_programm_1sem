#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_s->setReadOnly(true);
    ui->lineEdit_p->setReadOnly(true);

    ui->lineEdit_s->setStyleSheet("color: blue");
    ui->lineEdit_p->setStyleSheet("color: blue");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ok_clicked()
{
    float stor1 = ui->lineEdit_stor1->text().toFloat();
    float stor2 = ui->lineEdit_stor2->text().toFloat();
    float angle = ui->lineEdit_angle->text().toFloat();
    if(stor1>0 and stor2>0 and angle>0 and angle<180 and (stor1 != INFINITY and stor2 != INFINITY))
    {
        ui->lineEdit_s->setText(QString::number(0.5*stor1*stor2*round(sin(angle*M_PI/180)*1000000000000000)/1000000000000000));
        ui->lineEdit_p->setText(QString::number(stor1 + stor2 + sqrt(stor1*stor1 + stor2*stor2 - 2 * stor1*stor2*round(cos(angle*M_PI/180)*1000000000000000)/1000000000000000)));
    }
    else
    {
        ui->lineEdit_s->setText("");
        ui->lineEdit_p->setText("");
        QMessageBox::information(this, "Ошибка", "Введено некорректное значение параметра", QMessageBox::Ok);
    }
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->lineEdit_s->setText("");
    ui->lineEdit_p->setText("");
    ui->lineEdit_stor1->setText("");
    ui->lineEdit_stor2->setText("");
    ui->lineEdit_angle->setText("");
}
