#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "math.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->centerOn(0,0);
    int res = 1e5;
    scene->addLine(0, res, 0, -res); //высота к.о.
    scene->addLine(res, 0, -res, 0); //длина к.о.
//    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->lineEdit_p->setReadOnly(true);
    ui->lineEdit_s->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

//    QTableWidgetItem *item = ui->tableWidget->item(0, 0);
//    if(item == nullptr) // если указатель пустой
//    {
//        item = new QTableWidgetItem; // создаем ячейку
//        ui->tableWidget->setItem(0, 0, item); //сообщаем таблицеб что мы создали ячейку
//    }

//    QString str = item->text();
//    QMessageBox::information(this, "", str);

    int count = ui->spinBox->value(); //получаем количество вершин

    double mas_x[15]; // создаем массив из 15 элементов для x
    double mas_y[15]; // создаем массив из 15 элементов для y
    double masdlina[15];

    bool error = false; //наличие ошибок в данных
    bool errorinf = false;//проверка на величину координаты
    for(int i=0; i<count; i++) //цикл, который проходит по всем строчкам
    {
        QTableWidgetItem *item_x = ui->tableWidget->item(i, 0); //ячейка x
        QTableWidgetItem *item_y = ui->tableWidget->item(i, 1); //ячейка y

        if(item_x == nullptr)
        {
            item_x = new QTableWidgetItem;
            ui->tableWidget->setItem(i, 0, item_x);
        }
        if(item_y == nullptr)
        {
            item_y = new QTableWidgetItem;
            ui->tableWidget->setItem(i, 1, item_y);
        }

        QString text_x = item_x->text();
        QString text_y = item_y->text();

        bool ok_x = false;
        bool ok_y = false;

        double x = text_x.toDouble(&ok_x);
        double y = text_y.toDouble(&ok_y);

        if(ok_x) // если в x введено корректное значение
        {
            item_x->setBackground(Qt::white);
        }
        else // если в x введено корректное значение
        {
            item_x->setBackground(Qt::red);
            error = true;
        }

        if(ok_y) // если в y введено корректное значение
        {
            item_y->setBackground(Qt::white);
        }
        else // если в y введено корректное значение
        {
            item_y->setBackground(Qt::red);
            error = true;
        }

        //записываем считанные значения в массив
        mas_x[i] = x;
        mas_y[i] = y;
    }




    if(error)
    {
        QMessageBox::information(this, "Ошибка", "Ошибка вводимых данных");
        ui->lineEdit_p->setText("");
        ui->lineEdit_s->setText("");
    }
    else if(count==0)
    {
        ui->lineEdit_p->setText("");
        ui->lineEdit_s->setText("");
        QMessageBox::information(this, "Ошибка", "Нет координат");
        scene->clear();
        int res = 1e5;
        scene->addLine(0, res, 0, -res); //высота к.о.
        scene->addLine(res, 0, -res, 0); //длина к.о.
    }
    else
    {
        double p = 0;
        for(int i=1; i<count; i++)
        {
            double dist = sqrt(pow(mas_x[i] - mas_x[i-1], 2) + pow(mas_y[i] - mas_y[i-1], 2));
            masdlina[i-1] = dist;
            p += dist;
        }
        double dist = sqrt(pow(mas_x[count-1] - mas_x[0], 2) + pow(mas_y[count-1] - mas_y[0], 2));
        masdlina[count-1] = dist;
        p += dist;

        if(p==INFINITY or qIsNaN(p))
        {
            errorinf=true;
        }

        scene->clear();
        int res = 1e5;
        scene->addLine(0, res, 0, -res); //высота к.о.
        scene->addLine(res, 0, -res, 0); //длина к.о.
        for(int i=1; i<count; i++)
        {
            scene->addLine(mas_x[i - 1], -mas_y[i - 1], mas_x[i], -mas_y[i]);

        }
        scene->addLine(mas_x[0], -mas_y[0], mas_x[count-1], -mas_y[count-1]);
        ui->graphicsView->centerOn(0,0);



        bool samoper = false;//самопересечения - есть или нет
        for(int i=1; i<count; i++)
        {
            for(int j=1; j<count; j++)
            {
                if(i==j)
                {
                    continue;
                }

                else if(((mas_x[i-1] - mas_x[i])*(mas_y[j-1] - mas_y[j]))==((mas_y[i-1] - mas_y[i])*(mas_x[j-1] - mas_x[j])))
                {
                    if((min(mas_x[i], mas_x[i-1])<=min(mas_x[j], mas_x[j-1]) and max(mas_x[i], mas_x[i-1])>=max(mas_x[j], mas_x[j-1])) and (min(mas_y[i], mas_y[i-1])<=min(mas_y[j], mas_y[j-1]) and max(mas_y[i], mas_y[i-1])>=max(mas_y[j], mas_y[j-1])))
                    {
                        samoper=true;
                        break;
                    }
                    else if((min(mas_x[i], mas_x[i-1])>=min(mas_x[j], mas_x[j-1]) and max(mas_x[i], mas_x[i-1])<=max(mas_x[j], mas_x[j-1])) and (min(mas_y[i], mas_y[i-1])>=min(mas_y[j], mas_y[j-1]) and max(mas_y[i], mas_y[i-1])<=max(mas_y[j], mas_y[j-1])))
                    {
                        samoper=true;
                        break;
                    }
                    else
                        continue;
                }

                else if(mas_x[i] == mas_x[i-1] and mas_y[j] == mas_y[j-1])
                {
                    double x = mas_x[i];
                    double y = mas_y[j];
                    if(((min(mas_y[i-1], mas_y[i])<y and y<max(mas_y[i-1], mas_y[i]))) and ((min(mas_x[j-1], mas_x[j])<x and x<max(mas_x[j-1], mas_x[j]))))
                    {
                        samoper = true;
                        break;
                    }
                }
                else if(mas_x[j] == mas_x[j-1] and mas_y[i] == mas_y[i-1])
                {
                    double x = mas_x[j];
                    double y = mas_y[i];
                    if(((min(mas_x[i-1], mas_x[i])<x and x<max(mas_x[i-1], mas_x[i]))) and ((min(mas_y[j-1], mas_y[j])<y and y<max(mas_y[j-1], mas_y[j]))))
                    {
                        samoper = true;
                        break;
                    }
                }
                else if(mas_x[i] == mas_x[i-1])
                {
                    double x = mas_x[i];
                    double y = (((x - mas_x[j-1])*(mas_y[j] - mas_y[j-1]))/(mas_x[j] - mas_x[j - 1])) + mas_y[j-1];
                    if(((min(mas_y[i-1], mas_y[i])<y and y<max(mas_y[i-1], mas_y[i]))) and ((min(mas_x[j-1], mas_x[j])<x and x<max(mas_x[j-1], mas_x[j])) and (min(mas_y[j-1], mas_y[j])<y and y<max(mas_y[j-1], mas_y[j]))))
                    {
                        samoper = true;
                        break;
                    }
                }
                else if(mas_x[j] == mas_x[j-1])
                {
                    double x = mas_x[j];
                    double y = (((x - mas_x[i-1])*(mas_y[i] - mas_y[i-1]))/(mas_x[i] - mas_x[i - 1])) + mas_y[i-1];
                    if(((min(mas_x[i-1], mas_x[i])<x and x<max(mas_x[i-1], mas_x[i])) and (min(mas_y[i-1], mas_y[i])<y and y<max(mas_y[i-1], mas_y[i]))) and ((min(mas_y[j-1], mas_y[j])<y and y<max(mas_y[j-1], mas_y[j]))))
                    {
                        samoper = true;
                        break;
                    }
                }

                else if(mas_y[i] == mas_y[i-1])
                {
                    double y = mas_y[i];
                    double x = (((y - mas_y[j-1])*(mas_x[j] - mas_x[j-1]))/(mas_y[j] - mas_y[j - 1])) + mas_x[j-1];
                    if(((min(mas_x[i-1], mas_x[i])<x and x<max(mas_x[i-1], mas_x[i]))) and ((min(mas_x[j-1], mas_x[j])<x and x<max(mas_x[j-1], mas_x[j])) and (min(mas_y[j-1], mas_y[j])<y and y<max(mas_y[j-1], mas_y[j]))))
                    {
                        samoper = true;
                        break;
                    }
                }
                else if(mas_y[j] == mas_y[j-1])
                {
                    double y = mas_y[j];
                    double x = (((y - mas_y[i-1])*(mas_x[i] - mas_x[i-1]))/(mas_y[i] - mas_y[i - 1])) + mas_x[i-1];
                    if(((min(mas_x[i-1], mas_x[i])<x and x<max(mas_x[i-1], mas_x[i])) and (min(mas_y[i-1], mas_y[i])<y and y<max(mas_y[i-1], mas_y[i]))) and ((min(mas_x[j-1], mas_x[j])<x and x<max(mas_x[j-1], mas_x[j]))))
                    {
                        samoper = true;
                        break;
                    }
                }
                else
                {
                    double y = ((mas_x[i-1]*mas_y[i] - mas_x[i]*mas_y[i-1])*(mas_y[j-1] - mas_y[j]) - (mas_x[j-1]*mas_y[j] - mas_x[j]*mas_y[j-1])*(mas_y[i-1] - mas_y[i])) / ((mas_x[i-1] - mas_x[i])*(mas_y[j-1] - mas_y[j]) - (mas_y[i-1] - mas_y[i])*(mas_x[j-1] - mas_x[j]));
                    double x = ((mas_x[i-1]*mas_y[i] - mas_x[i]*mas_y[i-1])*(mas_x[j-1] - mas_x[j]) - (mas_x[j-1]*mas_y[j] - mas_x[j]*mas_y[j-1])*(mas_x[i-1] - mas_x[i])) / ((mas_x[i-1] - mas_x[i])*(mas_y[j-1] - mas_y[j]) - (mas_y[i-1] - mas_y[i])*(mas_x[j-1] - mas_x[j]));
                    if(((min(mas_x[i-1], mas_x[i])<x and x<max(mas_x[i-1], mas_x[i])) and (min(mas_y[i-1], mas_y[i])<y and y<max(mas_y[i-1], mas_y[i]))) and ((min(mas_x[j-1], mas_x[j])<x and x<max(mas_x[j-1], mas_x[j])) and (min(mas_y[j-1], mas_y[j])<y and y<max(mas_y[j-1], mas_y[j]))))
                    {
                        samoper = true;
                        break;
                    }

                }
            }
        }
        for(int j=1; j<count; j++)
        {
            if(samoper)
                break;
            int i = 0;
            if(((mas_x[count-1] - mas_x[i])*(mas_y[j-1] - mas_y[j]))==((mas_y[count-1] - mas_y[i])*(mas_x[j-1] - mas_x[j])))
            {
                if((min(mas_x[i], mas_x[count-1])<=min(mas_x[j], mas_x[j-1]) and max(mas_x[i], mas_x[count-1])>=max(mas_x[j], mas_x[j-1])) and (min(mas_y[i], mas_y[count-1])<=min(mas_y[j], mas_y[j-1]) and max(mas_y[i], mas_y[count-1])>=max(mas_y[j], mas_y[j-1])))
                {
                    samoper=true;
                    break;
                }
                else if((min(mas_x[i], mas_x[count-1])>=min(mas_x[j], mas_x[j-1]) and max(mas_x[i], mas_x[count-1])<=max(mas_x[j], mas_x[j-1])) and (min(mas_y[i], mas_y[count-1])>=min(mas_y[j], mas_y[j-1]) and max(mas_y[i], mas_y[count-1])<=max(mas_y[j], mas_y[j-1])))
                {
                    samoper=true;
                    break;
                }
                else
                    continue;
            }

            if(mas_x[i] == mas_x[count-1] and mas_y[j] == mas_y[j-1])
            {
                double x = mas_x[i];
                double y = mas_y[j];
                if(((min(mas_y[count-1], mas_y[i])<y and y<max(mas_y[count-1], mas_y[i]))) and ((min(mas_x[j-1], mas_x[j])<x and x<max(mas_x[j-1], mas_x[j]))))
                {
                    samoper = true;
                    break;
                }
            }
            else if(mas_x[j] == mas_x[j-1] and mas_y[i] == mas_y[count-1])
            {
                double x = mas_x[j];
                double y = mas_y[i];
                if(((min(mas_x[count-1], mas_x[i])<x and x<max(mas_x[count-1], mas_x[i]))) and ((min(mas_y[j-1], mas_y[j])<y and y<max(mas_y[j-1], mas_y[j]))))
                {
                    samoper = true;
                    break;
                }
            }
            else if(mas_x[i] == mas_x[count-1])
            {
                double x = mas_x[i];
                double y = (((x - mas_x[j-1])*(mas_y[j] - mas_y[j-1]))/(mas_x[j] - mas_x[j - 1])) + mas_y[j-1];
                if(((min(mas_y[count-1], mas_y[i])<y and y<max(mas_y[count-1], mas_y[i]))) and ((min(mas_x[j-1], mas_x[j])<x and x<max(mas_x[j-1], mas_x[j])) and (min(mas_y[j-1], mas_y[j])<y and y<max(mas_y[j-1], mas_y[j]))))
                {
                    samoper = true;
                    break;
                }
            }
            else if(mas_x[j] == mas_x[j-1])
            {
                double x = mas_x[j];
                double y = (((x - mas_x[count-1])*(mas_y[i] - mas_y[count-1]))/(mas_x[i] - mas_x[count - 1])) + mas_y[count-1];
                if(((min(mas_x[count-1], mas_x[i])<x and x<max(mas_x[count-1], mas_x[i])) and (min(mas_y[count-1], mas_y[i])<y and y<max(mas_y[count-1], mas_y[i]))) and ((min(mas_y[j-1], mas_y[j])<y and y<max(mas_y[j-1], mas_y[j]))))
                {
                    samoper = true;
                    break;
                }
            }

            else if(mas_y[i] == mas_y[count-1])
            {
                double y = mas_y[i];
                double x = (((y - mas_y[j-1])*(mas_x[j] - mas_x[j-1]))/(mas_y[j] - mas_y[j - 1])) + mas_x[j-1];
                if(((min(mas_x[count-1], mas_x[i])<x and x<max(mas_x[count-1], mas_x[i]))) and ((min(mas_x[j-1], mas_x[j])<x and x<max(mas_x[j-1], mas_x[j])) and (min(mas_y[j-1], mas_y[j])<y and y<max(mas_y[j-1], mas_y[j]))))
                {
                    samoper = true;
                    break;
                }
            }
            else if(mas_y[j] == mas_y[j-1])
            {
                double y = mas_y[j];
                double x = (((y - mas_y[count-1])*(mas_x[i] - mas_x[count-1]))/(mas_y[i] - mas_y[count - 1])) + mas_x[count-1];
                if(((min(mas_x[count-1], mas_x[i])<x and x<max(mas_x[count-1], mas_x[i])) and (min(mas_y[count-1], mas_y[i])<y and y<max(mas_y[count-1], mas_y[i]))) and ((min(mas_x[j-1], mas_x[j])<x and x<max(mas_x[j-1], mas_x[j]))))
                {
                    samoper = true;
                    break;
                }
            }

            else
            {
                double y = ((mas_x[count-1]*mas_y[i] - mas_x[i]*mas_y[count-1])*(mas_y[j-1] - mas_y[j]) - (mas_x[j-1]*mas_y[j] - mas_x[j]*mas_y[j-1])*(mas_y[count-1] - mas_y[i])) / ((mas_x[count-1] - mas_x[i])*(mas_y[j-1] - mas_y[j]) - (mas_y[count-1] - mas_y[i])*(mas_x[j-1] - mas_x[j]));
                double x = ((mas_x[count-1]*mas_y[i] - mas_x[i]*mas_y[count-1])*(mas_x[j-1] - mas_x[j]) - (mas_x[j-1]*mas_y[j] - mas_x[j]*mas_y[j-1])*(mas_x[count-1] - mas_x[i])) / ((mas_x[count-1] - mas_x[i])*(mas_y[j-1] - mas_y[j]) - (mas_y[count-1] - mas_y[i])*(mas_x[j-1] - mas_x[j]));
                if(((min(mas_x[count-1], mas_x[i])<x and x<max(mas_x[count-1], mas_x[i])) and (min(mas_y[count-1], mas_y[i])<y and y<max(mas_y[count-1], mas_y[i]))) and ((min(mas_x[j-1], mas_x[j])<x and x<max(mas_x[j-1], mas_x[j])) and (min(mas_y[j-1], mas_y[j])<y and y<max(mas_y[j-1], mas_y[j]))))
                {
                    samoper = true;
                    break;
                }
            }
        }




        if(count==2)
        {
            ui->lineEdit_p->setText(QString::number(p));
            ui->lineEdit_s->setText("0");
        }
        else if(samoper)
        {
            QMessageBox::information(this, "Ошибка", "Фигура самопересекающаяся");
            ui->lineEdit_p->setText("");
            ui->lineEdit_s->setText("");
        }
        else
        {
            ui->lineEdit_p->setText(QString::number(p));

            double st = mas_x[count-1]*mas_y[0]-mas_y[count-1]*mas_x[0];
            for(int i=0; i<(count-1); i++)
            {
                st += mas_x[i]*mas_y[i+1] - mas_y[i]*mas_x[i+1];
            }
            double s = fabs(0.5*st);
            ui->lineEdit_s->setText(QString::number(s));
            if(s==INFINITY or qIsNaN(s))
            {
                errorinf=true;
            }
            if(errorinf)
            {
                ui->lineEdit_p->setText("");
                ui->lineEdit_s->setText("");
                scene->clear();
                int res = 1e5;
                scene->addLine(0, res, 0, -res); //высота к.о.
                scene->addLine(res, 0, -res, 0); //длина к.о.
                QMessageBox::information(this, "Ошибка", "Слишком большое значение координат(ы)");
            }
        }



    }


}
void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->tableWidget->setRowCount(arg1); //задаем n строк
    ui->tableWidget->setColumnCount(2); //задаем 2 столбца
}

void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    QString text = item->text();

    bool ok;
    text.toDouble(&ok);

    if(ok)
    {
        item->setBackground(Qt::white);
    }
    else
    {
        item->setBackground(Qt::red);
    }
}

