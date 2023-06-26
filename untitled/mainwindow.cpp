#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_result_value->setText("");
    ui->label_error->setText("");
    ui->label_result_ost->setText("");
    ui->label_ost_text->setText("");
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_do_clicked()
{
    QString op1_text = ui->lineEdit_op1_value->text();
    QString op2_text = ui->lineEdit_op2_value->text();

    bool ok1;
    bool ok2;
    int op1 = op1_text.toInt(&ok1, 10);
    int op2 = op2_text.toInt(&ok2, 10);

    if(ok1)
    {
        if(ui->radioButton_sum->isChecked())
        {
            int result = op1 + op2;

            QString result_text;
            result_text.setNum(result, 10);

            ui->label_result_value->setText(result_text);
            ui->label_error->setText("");
            ui->label_result_ost->setText("");
            ui->label_ost_text->setText("");


        }
        else if (ui->radioButton_sub->isChecked())
        {
            int result = op1 - op2;

            QString result_text;
            result_text.setNum(result, 10);

            ui->label_result_value->setText(result_text);
            ui->label_error->setText("");
            ui->label_result_ost->setText("");
            ui->label_ost_text->setText("");
        }

        else if (ui->radioButton_mul->isChecked())
        {
            int result = op1 * op2;

            QString result_text;
            result_text.setNum(result, 10);

            ui->label_result_value->setText(result_text);
            ui->label_error->setText("");
            ui->label_result_ost->setText("");
            ui->label_ost_text->setText("");
        }

        else if (ui->radioButton_div->isChecked())
        {

            if(op2 == 0)
            {
                ui->label_error->setText("Неопределённость");
                ui->label_result_value->setText("");
                ui->label_ost_text->setText("");
                ui->label_result_ost->setText("");
            }
            else
            {
                int result = op1 / op2;
                int ostat = op1 % op2;

                QString result_text;
                QString result_ost;
                result_text.setNum(result, 10);
                result_ost.setNum(ostat, 10);

                ;

                ui->label_result_value->setText(result_text);
                ui->label_result_ost->setText(result_ost);
                ui->label_error->setText("");
                ui->label_ost_text->setText("Остаток:");
            }
        }

        else
        {
            ui->label_error->setText("Не выбрано действие");
            ui->label_result_value->setText("");
        }
    }

    else
    {
        ui->label_error->setText("Ошибка операнды");
        ui->label_result_value->setText("");
        ui->label_result_ost->setText("");
        ui->label_ost_text->setText("");
    }

    if(ok2)
    {
    }
    else
    {
        ui->label_error->setText("Ошибка операнды");
        ui->label_result_value->setText("");
        ui->label_result_ost->setText("");
        ui->label_ost_text->setText("");
    }
}
