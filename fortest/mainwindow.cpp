#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <iostream>

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

//чтение таблицы
void MainWindow::readMassive(double *mas, int *size, bool *error)
{
    *size = ui->tableWidget->rowCount(); //получаем кол-во элементов(строк)
    *error = false;
    for(int i = 0; i<*size; i++) //делаем перебор всех строк таблицы
    {
        QTableWidgetItem *item = ui->tableWidget->item(i, 0); //получаем указатель на ячейку

        if(item==nullptr) //если ячейка пустая
        {
            item = new QTableWidgetItem; //выделять память под ячейку
            ui->tableWidget->setItem(i, 0, item); //задаем ячейку в таблицу
        }

        QString text = item->text(); // получаем текстовое значение ячейки

        bool ok  = false; //флаг перевода в число
        mas[i] = text.toDouble(&ok); //переводим текстовое значение ячейки в число

        if(!ok) //если число было не успешно
        {
            *error = true; //ставим флаг, что есть ошибка
            //break; //прерываем цикл
        }
    }
}
//запись таблицы в массив
void MainWindow::writeMassive(double *mas, int size)
{
    for(int i=0; i<size; i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i, 0);

        if(item == nullptr)
        {
            item = new QTableWidgetItem;
            ui->tableWidget->setItem(i, 0, item);
        }

        QString text;
        text.setNum(mas[i]); //делаем перевод числа в строку


        item->setText(text);
    }
}

//выявление размера массива
void MainWindow::on_spinBox_count_valueChanged(int arg1)
{
    ui->tableWidget->setRowCount(arg1); // задаем кол-во строк
    ui->tableWidget->setColumnCount(1); // задаем кол-во столбцов
}

//Рандомайзер
void MainWindow::on_pushButton_random_clicked()
{
    int size = ui->tableWidget->rowCount();
    for(int i = 0; i < size; i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(QRandomGenerator::global()->bounded(-200, 200))));
        ui->tableWidget->item(i,0)->setBackground(Qt::white);
    }
}


//выявление изменения таблицы
void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    QString str = item->text(); // получаем текстовое значение ячейки

    bool ok = false;
    double d = str.toDouble(&ok); //переводим текстовое значение ячейки
    if(str.toDouble()==INFINITY or qIsNaN(str.toDouble()) or str.toDouble()>1e10)
    {
        ok = false;
    }

    if(!ok) //если перевод неудачный
    {
        item->setBackground(Qt::red); // задаем красный цвет
    }
    else // если перевод удачный
    {
        item->setBackground(Qt::white); // задаем белый цвет
    }
}

//основной код
void MainWindow::on_pushButton_ok_clicked()
{
    int size = ui->tableWidget->rowCount();
    double *mas = new double[size]; // массив таблицы
    bool error;
    readMassive(mas, &size, &error); //считываем массив
    if(error)
    {
        ui->label->setText("Неккоректное значение");
    }
    else if(size==0)
    {
        ui->label->setText("Таблица пустая");
    }
    else
    {
        int answer=0;

        for(int l=0;l<size;l++)
        {
            if(mas[l]>0 and mas[l]<100)
            {
                answer+=1;
            }
        }
        ui->label->setText(QString::number(answer));

    }
    delete [] mas;
    mas = NULL;
}
