#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_result_value->setText("");
    ui->label_error->setText("");

}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButton_sum_clicked()
{
    ui->label_op1_text->setText("Слагаемое 1");
    ui->label_op2_text->setText("Слагаемое 2");
    ui->lineEdit_op2_value->setEnabled(true);
}

void MainWindow::on_radioButton_sub_clicked()
{
    ui->label_op1_text->setText("Уменьшаемое");
    ui->label_op2_text->setText("Вычитаемое");
    ui->lineEdit_op2_value->setEnabled(true);
}

void MainWindow::on_radioButton_mul_clicked()
{
    ui->label_op1_text->setText("Множитель 1");
    ui->label_op2_text->setText("Множитель 2");
    ui->lineEdit_op2_value->setEnabled(true);
}

void MainWindow::on_radioButton_div_clicked()
{
    ui->label_op1_text->setText("Делимое");
    ui->label_op2_text->setText("Делитель");
    ui->lineEdit_op2_value->setEnabled(true);
}

void MainWindow::on_radioButton_sin_clicked()
{
    ui->label_op1_text->setText("Угол");
    ui->label_op2_text->setText("");
    ui->lineEdit_op2_value->setEnabled(false);
}

void MainWindow::on_radioButton_cos_clicked()
{
    ui->label_op1_text->setText("Угол");
    ui->label_op2_text->setText("");
    ui->lineEdit_op2_value->setEnabled(false);
}

void MainWindow::on_radioButton_tg_clicked()
{
    ui->label_op1_text->setText("Угол");
    ui->label_op2_text->setText("");
    ui->lineEdit_op2_value->setEnabled(false);
}

void MainWindow::on_radioButton_ctg_clicked()
{
    ui->label_op1_text->setText("Угол");
    ui->label_op2_text->setText("");
    ui->lineEdit_op2_value->setEnabled(false);

}

void MainWindow::on_radioButton_arcsin_clicked()
{
    ui->label_op1_text->setText("Синус");
    ui->label_op2_text->setText("");
    ui->lineEdit_op2_value->setEnabled(false);
}

void MainWindow::on_radioButton_arccos_clicked()
{
    ui->label_op1_text->setText("Косинус");
    ui->label_op2_text->setText("");
    ui->lineEdit_op2_value->setEnabled(false);
}

void MainWindow::on_radioButton_deg_clicked()
{
    ui->label_op1_text->setText("Число");
    ui->label_op2_text->setText("Степень");
    ui->lineEdit_op2_value->setEnabled(true);
}

void MainWindow::on_radioButton_sqrt_clicked()
{
    ui->label_op1_text->setText("Число");
    ui->label_op2_text->setText("Корень");
    ui->lineEdit_op2_value->setEnabled(true);
}


void MainWindow::on_pushButton_do_clicked()
{
    QString op1_text = ui->lineEdit_op1_value->text();
    QString op2_text = ui->lineEdit_op2_value->text();

    bool ok1;
    bool ok2;
    double op1 = op1_text.toDouble(&ok1);
    double op2 = op2_text.toDouble(&ok2);

    if(ok1)
    {
        if(ui->radioButton_sum->isChecked())
        {
            double result = op1 + op2;

            QString result_text;
            result_text.setNum(result);

            ui->label_result_value->setText(result_text);
            ui->label_error->setText("");


        }
        else if (ui->radioButton_sub->isChecked())
        {
            double result = op1 - op2;

            QString result_text;
            result_text.setNum(result);

            ui->label_result_value->setText(result_text);
            ui->label_error->setText("");
        }

        else if (ui->radioButton_mul->isChecked())
        {
            double result = op1 * op2;

            QString result_text;
            result_text.setNum(result);

            ui->label_result_value->setText(result_text);
            ui->label_error->setText("");
        }

        else if (ui->radioButton_div->isChecked())
        {

            if(op2 == 0 || (op1 == INFINITY && op2 == INFINITY))
            {
                ui->label_error->setText("Неопределённость");
                ui->label_result_value->setText("");
            }

            else
            {
                double result = op1 / op2;

                QString result_text;
                QString result_ost;
                result_text.setNum(result);


                ui->label_result_value->setText(result_text);
                ui->label_error->setText("");
            }


        }

        else if (ui->radioButton_sin->isChecked())
        {
            double result = round(sin(op1*M_PI/180)*1000000000000000)/1000000000000000;

            QString result_text;
            result_text.setNum(result);

            ui->label_result_value->setText(result_text);
            ui->label_error->setText("");
        }

        else if (ui->radioButton_cos->isChecked())
        {
            double result = round(cos(op1*M_PI/180)*1000000000000000)/1000000000000000;

            QString result_text;
            result_text.setNum(result);

            ui->label_result_value->setText(result_text);
            ui->label_error->setText("");
        }

        else if (ui->radioButton_tg->isChecked())
        {
            double result = (round(sin(op1*M_PI/180)*1000000000000000)/1000000000000000)/(round(cos(op1*M_PI/180)*1000000000000000)/1000000000000000);

            QString result_text;
            result_text.setNum(result);

            ui->label_result_value->setText(result_text);
            ui->label_error->setText("");
        }

        else if (ui->radioButton_ctg->isChecked())
        {
            double result = (round(cos(op1*M_PI/180)*1000000000000000)/1000000000000000)/(round(sin(op1*M_PI/180)*1000000000000000)/1000000000000000);

            QString result_text;
            result_text.setNum(result);

            ui->label_result_value->setText(result_text);
            ui->label_error->setText("");
        }

        else if (ui->radioButton_arcsin->isChecked())
        {
            double result = asin(op1)*180/M_PI;

            QString result_text;
            result_text.setNum(result);
            if (op1 > 1 or op1 < -1)
            {
                ui->label_error->setText("Неверный синус");
                ui->label_result_value->setText("");
            }
            else
            {
                ui->label_result_value->setText(result_text);
                ui->label_error->setText("");
            }
        }

        else if (ui->radioButton_arccos->isChecked())
        {
            double result = acos(op1)*180/M_PI;

            QString result_text;
            result_text.setNum(result);

            if (op1 > 1 or op1 < -1)
            {
                ui->label_error->setText("Неверный косинус");
                ui->label_result_value->setText("");
            }
            else
            {
                ui->label_result_value->setText(result_text);
                ui->label_error->setText("");
            }
        }

        else if (ui->radioButton_deg->isChecked())
        {
            double result = pow(op1, op2);


            QString result_text;
            result_text.setNum(result);

            ui->label_result_value->setText(result_text);
            ui->label_error->setText("");
        }

        else if (ui->radioButton_sqrt->isChecked())
        {
            double result;
            if (op1 < 0 && int (op2) % 2 != 0)
            {
                result = -pow(-op1, 1/op2);

                QString result_text;
                result_text.setNum(result);

                ui->label_result_value->setText(result_text);
                ui->label_error->setText("");
            }

            else if (op1 > 0)
            {
                result = pow(op1, 1/op2);

                QString result_text;
                result_text.setNum(result);

                ui->label_result_value->setText(result_text);
                ui->label_error->setText("");
            }

            else
            {
                ui->label_result_value->setText("");
                ui->label_error->setText("Мнимое число");
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
    }

    if(ok2
    || (ui->radioButton_sin->isChecked() && !ok2)
    || (ui->radioButton_cos->isChecked() && !ok2)
    || (ui->radioButton_tg->isChecked() && !ok2)
    || (ui->radioButton_ctg->isChecked() && !ok2)
    || (ui->radioButton_arcsin->isChecked() && !ok2)
    || (ui->radioButton_arccos->isChecked() && !ok2))
    {
    }
    else
    {
        ui->label_error->setText("Ошибка операнды");
        ui->label_result_value->setText("");
    }
}




void MainWindow::on_pushButton_clear_clicked()
{
    ui->label_result_value->setText("");
    ui->label_error->setText("");
    ui->lineEdit_op1_value->setText("");
    ui->lineEdit_op2_value->setText("");
}
