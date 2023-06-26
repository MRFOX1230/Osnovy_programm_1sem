#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_result_value->setText("");
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, Qt::red);
    this->setPalette(palette); //устанавливаем измененную палитру
    ui->label_result_value->setText("Ложь");

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow:: on_comboBox_do_currentIndexChanged(int index)
{


    bool op1;
    bool op2;

    int indexOp1 = ui->comboBox_op1->currentIndex(); //получаем номер выбранного элемента в списке op1

    op1 = indexOp1;

    int indexOp2 = ui->comboBox_op2->currentIndex(); //в op2
    op2 = indexOp2; //получаем значение 2-ого операнда

    // 0 - конъюнкция
    // 1 - дизъюнкция
    // ...

    bool result; // результат выполнения операции
    if(index == 5)
    {
        ui->comboBox_op2->setEnabled(false); // частично убрать список (сделать прозрачным и нерабочим)
        //ui->comboBox_op2->setVisible(false); //полностью убрать список
        ui->label_op2text->setEnabled(false);
    }
    else
    {
        ui->comboBox_op2->setEnabled(true);
        ui->label_op2text->setEnabled(true);
    }
    switch(index) //сравниваем значение переменной
    {
    case 0:
    {
        result = (op1 and op2); //выполняем логическое сложение
        break; //завершаем блок
    }
    case 1:
    {
        result = (op1 or op2); //выполняем логическое умножение
        break; //завершаем блок
    }
    case 2:
    {
        result = (op1 == op2); //выполняем эквиваленцию
        break; //завершаем блок
    }
    case 3:
    {
        result = (op1 ^ op2); //выполняем исключающее или
        break; //завершаем блок
    }
    case 4:
    {
        result = (op1 <= op2); //выполняем импликацию
        break; //завершаем блок
    }
    case 5:
    {
        result = (not op1); //выполняем инверсию
        break; //завершаем блок
    }
    case 6:
    {
        result = not (op1 and op2); //выполняем штрих Шеффера
        break; //завершаем блок
    }
    case 7:
    {
        result = not (op1 or op2); //выполняем стрелку Пирса
        break; //завершаем блок
    }
    }

    //вывод результата
    if (result)
    {
        QPalette palette = this->palette();
        palette.setColor(QPalette::Window, Qt::green);
        this->setPalette(palette); //устанавливаем измененную палитру
        ui->label_result_value->setText("Истина");
    }
    else
    {
        QPalette palette = this->palette();
        palette.setColor(QPalette::Window, Qt::red);
        this->setPalette(palette); //устанавливаем измененную палитру
        ui->label_result_value->setText("Ложь");
    }
}



void MainWindow::on_comboBox_op1_currentIndexChanged(int index)
{
    int sdo;
    bool op2;

    bool op1 = index;

    int indexSdo = ui->comboBox_do->currentIndex(); //получаем номер выбранного элемента в списке op1

    sdo = indexSdo;

    int indexOp2 = ui->comboBox_op2->currentIndex(); //в op2
    op2 = indexOp2; //получаем значение 2-ого операнда

    bool result; // результат выполнения операции

    switch(indexSdo) //сравниваем значение переменной
    {
    case 0:
    {
        result = (op1 and op2); //выполняем логическое сложение
        break; //завершаем блок
    }
    case 1:
    {
        result = (op1 or op2); //выполняем логическое умножение
        break; //завершаем блок
    }
    case 2:
    {
        result = (op1 == op2); //выполняем эквиваленцию
        break; //завершаем блок
    }
    case 3:
    {
        result = (op1 ^ op2); //выполняем исключающее или
        break; //завершаем блок
    }
    case 4:
    {
        result = (op1 <= op2); //выполняем импликацию
        break; //завершаем блок
    }
    case 5:
    {
        result = (not op1); //выполняем инверсию
        break; //завершаем блок
    }
    case 6:
    {
        result = not (op1 and op2); //выполняем штрих Шеффера
        break; //завершаем блок
    }
    case 7:
    {
        result = not (op1 or op2); //выполняем стрелку Пирса
        break; //завершаем блок
    }
    }

    //вывод результата
    if (result)
    {
        QPalette palette = this->palette();
        palette.setColor(QPalette::Window, Qt::green);
        this->setPalette(palette); //устанавливаем измененную палитру
        ui->label_result_value->setText("Истина");
    }
    else
    {
        QPalette palette = this->palette();
        palette.setColor(QPalette::Window, Qt::red);
        this->setPalette(palette); //устанавливаем измененную палитру
        ui->label_result_value->setText("Ложь");
    }
}



void MainWindow::on_comboBox_op2_currentIndexChanged(int index)
{
    int sdo;
    bool op1;

    bool op2 = index;

    int indexSdo = ui->comboBox_do->currentIndex(); //получаем номер выбранного элемента в списке op1

    sdo = indexSdo;

    int indexOp1 = ui->comboBox_op1->currentIndex(); //в op2
    op1 = indexOp1; //получаем значение 2-ого операнда

    bool result; // результат выполнения операции

    switch(indexSdo) //сравниваем значение переменной
    {
    case 0:
    {
        result = (op1 and op2); //выполняем логическое сложение
        break; //завершаем блок
    }
    case 1:
    {
        result = (op1 or op2); //выполняем логическое умножение
        break; //завершаем блок
    }
    case 2:
    {
        result = (op1 == op2); //выполняем эквиваленцию
        break; //завершаем блок
    }
    case 3:
    {
        result = (op1 ^ op2); //выполняем исключающее или
        break; //завершаем блок
    }
    case 4:
    {
        result = (op1 <= op2); //выполняем импликацию
        break; //завершаем блок
    }
    case 5:
    {
        result = (not op1); //выполняем инверсию
        break; //завершаем блок
    }
    case 6:
    {
        result = not (op1 and op2); //выполняем штрих Шеффера
        break; //завершаем блок
    }
    case 7:
    {
        result = not (op1 or op2); //выполняем стрелку Пирса
        break; //завершаем блок
    }
    }

    //вывод результата
    if (result)
    {
        QPalette palette = this->palette();
        palette.setColor(QPalette::Window, Qt::green);
        this->setPalette(palette); //устанавливаем измененную палитру
        ui->label_result_value->setText("Истина");
    }
    else
    {
        QPalette palette = this->palette();
        palette.setColor(QPalette::Window, Qt::red);
        this->setPalette(palette); //устанавливаем измененную палитру
        ui->label_result_value->setText("Ложь");
    }
}
