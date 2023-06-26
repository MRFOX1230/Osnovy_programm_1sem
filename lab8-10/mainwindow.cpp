#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textEdit_searchRows->setReadOnly(true);
    ui->spinBox_count->setMaximum(mascount);
}
MainWindow::~MainWindow()
{
    delete ui;
}

//Считывание таблицы
void MainWindow::readMassive(double *mas, int *size, bool *error)
{
    if(!random)
    {
        *size = ui->tableWidget->rowCount(); //получаем кол-во элементов(строк)
        *error = false;
        for(int i = 0; i<*size; i++) //делаем перебор всех строк таблицы
        {
            QTableWidgetItem *item = ui->tableWidget->item(i, 0); //получаем указатель на ячейку

            if(item==nullptr) //если ячейки до этого не существовало
            {
                if(buttonturn or dubl)
                {
                    cellempty = true;
                    item = new QTableWidgetItem; //выделять память под ячейку
                    ui->tableWidget->setItem(i, 0, item); //задаем ячейку в таблицу
                    item->setBackground(Qt::red); // задаем красный цвет
                    *error = true; //ставим флаг, что есть ошибка
                }
                else
                {
                    item = new QTableWidgetItem; //выделять память под ячейку
                    ui->tableWidget->setItem(i, 0, item); //задаем ячейку в таблицу
                }
            }

            if(!cellempty)
            {
                QString text = item->text(); // получаем текстовое значение ячейки

                bool ok  = false; //флаг перевода в число
                mas[i] = text.toDouble(&ok); //переводим текстовое значение ячейки в число

                if(!ok) //если число было не успешно
                {
                    *error = true; //ставим флаг, что есть ошибка
                }
            }
        }
    }
}
//Запись массива
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
//Считывание SpinBox-а
void MainWindow::on_spinBox_count_valueChanged(int arg1)
{
    if(color)
    {
        //Обеление всей таблицы
        whiteMassive(&size);
    }

    ui->label_min->setText("-");
    ui->label_avg->setText("-");
    ui->label_max->setText("-");
    ui->textEdit_searchRows->setText("");
    ui->label_searchCount->setText("");

    size=arg1; //получаем кол-во элементов(строк)
    ui->tableWidget->setRowCount(arg1); // задаем кол-во строк
    ui->tableWidget->setColumnCount(1); // задаем кол-во столбцов

}
//Проверка ячейки таблицы при ее изменении
void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    if(!random and !searchchange and !cellempty and !sort)
    {
        if(!searchbutton)
        {
            ui->label_min->setText("-");
            ui->label_avg->setText("-");
            ui->label_max->setText("-");
        }

        ui->textEdit_searchRows->setText("");
        ui->label_searchCount->setText("");



        QString str = item->text(); // получаем текстовое значение ячейки
        bool ok = false;

        str.toDouble(&ok); //переводим текстовое значение ячейки
        if(str.toDouble()==INFINITY or qIsNaN(str.toDouble()) or str.toDouble()>1e10)
        {
            ok = false;
        }

        if(!ok) //если перевод неудачный
        {
            whiteMassive(&size);
            item->setBackground(Qt::red); // задаем красный цвет
        }
        else if(colorgreen)
        {
            // задаем зеленый цвет
            color=true;
            colorgreen=false;
        }
        else if(searchturn)
        {
            searchturn = false;
            whiteMassive(&size);

        }
        else // если перевод удачный
        {
            item->setBackground(Qt::white); // задаем белый цвет
        }
    }

}


//Обеление зеленых ячеек таблицы
void MainWindow::whiteMassive(int *size)
{
    if(green)
    {
        for(int i=0; i<*size;i++)
        {
            if(masgreen[i]==true)
            {
                QTableWidgetItem *item = ui->tableWidget->item(i, 0); //получаем указатель на ячейку
                item->setBackground(Qt::white);
                masgreen[i]=false;
            }
        }

        green = false;
    }
    color=false;
}

//Функция вызова ошибки
void MainWindow::errorf(bool error, int size, bool bignumber)
{
    //проверяем на ошибки
    if(error)
    {
        QMessageBox::information(this, "Ошибка", "В массиве некорректное значение");
    }
    else if(size==0)
    {
        ui->label_min->setText("-");
        ui->label_avg->setText("-");
        ui->label_max->setText("-");
        ui->textEdit_searchRows->setText("");
        ui->label_searchCount->setText("");
        QMessageBox::information(this, "Ошибка", "В массиве некорректное значение");
    }
    else if(bignumber)
    {
        ui->label_min->setText("-");
        ui->label_avg->setText("-");
        ui->label_max->setText("-");
        ui->textEdit_searchRows->setText("");
        ui->label_searchCount->setText("");
        QMessageBox::information(this, "Ошибка", "Слишком большое число в массиве");
    }
}

//Проверка отсортированности массива
void sortturnf(double mas[], int size, bool &sortturn)
{
    for(int i=1;i<size;i++)
    {
        if(mas[i-1]>mas[i])
        {
           sortturn=false;
           break;
        }
        else
        {
            sortturn=true;
        }
    }
}

//Проверка на большое число
void bignumberf(double mas[], int size, bool &bignumber)
{
    for(int i=0;i<size;i++)
    {
        if(mas[i]==INFINITY or qIsNaN(mas[i]) or mas[i]>1e10)
        {
           bignumber=true;
           break;
        }
        else
        {
            bignumber=false;
        }
    }
}



//Кнопка расчета минимального значения
void MainWindow::on_pushButton_min_clicked()
{
    size = ui->tableWidget->rowCount();
    double *mas = new double[size]; // массив таблицы
    bool error;

    buttonturn=true;
    readMassive(mas, &size, &error); //считываем массив
    buttonturn=false;
    cellempty=false;

    bignumberf(mas, size,bignumber);

    errorf(error, size, bignumber);//вызов ошибки при необходимости
    if(!error and size>0 and !bignumber)
    {
        // ищем минимальное значение
        min = mas[0];

        for(int i = 1; i<size; i++)
        {
            if(mas[i] < min)
            {
                min = mas[i];
            }
        }

        //вывод результата
        ui->label_min->setNum(min);
    }
    delete [] mas;
    mas = NULL;
}

//Кнопка расчета максимального значения
void MainWindow::on_pushButton_max_clicked()
{
    size = ui->tableWidget->rowCount();
    double *mas = new double[size]; // массив таблицы
    bool error;

    buttonturn=true;
    readMassive(mas, &size, &error); //считываем массив
    buttonturn=false;
    cellempty=false;

    bignumberf(mas, size,bignumber);
    errorf(error, size, bignumber);//вызов ошибки при необходимости
    if(!error and size>0 and !bignumber)
    {
        // ищем максимальное значение
        max = mas[0];

        for(int i = 1; i<size; i++)
        {
            if(mas[i] > max)
            {
                max = mas[i];
            }
        }

        //вывод результата
        ui->label_max->setNum(max);
    }
    delete [] mas;
    mas = NULL;
}

//Кнопка расчета среднего значения
void MainWindow::on_pushButton_avg_clicked()
{
    size = ui->tableWidget->rowCount();
    double *mas = new double[size]; // массив таблицы
    bool error;

    buttonturn=true;
    readMassive(mas, &size, &error); //считываем массив
    buttonturn=false;
    cellempty=false;

    bignumberf(mas, size, bignumber);

    //проверяем на ошибки
    errorf(error, size, bignumber);//вызов ошибки при необходимости
    if(!error and size>0 and !bignumber)
    {
        // ищем среднее значение
        avg = 0;
        for(int i = 0; i<size; i++)
        {
            avg += mas[i];
        }
        avg = avg/size;

        //вывод результата
        ui->label_avg->setNum(avg);
    }
    delete [] mas;
    mas = NULL;
}



//Сортировки

//Сортировка расческой
void MainWindow::on_pushButton_comb_clicked()
{
    size = ui->tableWidget->rowCount();
    double *mas = new double[size]; // массив таблицы
    bool error;

    if(randomturn)
    {
        sort = true;
    }
    buttonturn=true;
    readMassive(mas, &size, &error); //считываем массив
    buttonturn=false;
    cellempty=false;

    sortturnf(mas, size, sortturn);
    bignumberf(mas, size,bignumber);

    errorf(error, size, bignumber);//вызов ошибки при необходимости
    if(sortturn == false and !error and size>0 and !bignumber)
    {
        if(size>700000)
        {
            QMessageBox::information(this, "Предупреждение!", "Процесс может занять больше 3 секунд");
        }
        //Обеление всей таблицы
        whiteMassive(&size);

        // сортировка
        double factor = 1.2473309; // фактор уменьшения
        int step = size - 1; // шаг сортировки

        //Последняя итерация цикла, когда step==1 эквивалентна одному проходу сортировки пузырьком
        while (step >= 1)
        {
            for (int i = 0; i + step < size; i++)
            {
                if (mas[i] > mas[i + step])
                {
                    std::swap(mas[i], mas[i + step]);
                }
            }
            step /= factor;
        }
        // вывод массива
        writeMassive(mas, size);
        if(qIsNaN(min))
        {
            ui->label_min->setText("-");
        }
        else
        {
            ui->label_min->setText(QString::number(min));
        }
        if(qIsNaN(max))
        {
            ui->label_max->setText("-");
        }
        else
        {
            ui->label_max->setText(QString::number(max));
        }
        if(qIsNaN(avg))
        {
            ui->label_avg->setText("-");
        }
        else
        {
            ui->label_avg->setText(QString::number(avg));
        }
        min=NAN;
        max=NAN;
        avg=NAN;
    }
    sort = false;

    ui->textEdit_searchRows->setText("");
    ui->label_searchCount->setText("");
    delete [] mas;
    mas = NULL;
}

//Гномья сортировка
void MainWindow::on_pushButton_gnom_clicked()
{
    size = ui->tableWidget->rowCount();
    double *mas = new double[size]; // массив таблицы
    bool error;

    buttonturn=true;
    readMassive(mas, &size, &error); //считываем массив
    buttonturn=false;
    cellempty=false;

    sortturnf(mas, size, sortturn);
    bignumberf(mas, size,bignumber);

    if(sortturn or error or size == 0 or bignumber)
    {
        errorf(error, size, bignumber);//вызов ошибки при необходимости
    }
    else if(size>100000)
    {
        QMessageBox::information(this, "Предупреждение!", "Слишком большое значение для гномьей сортировки");
    }
    else
    {
        if(size>30000)
        {
            QMessageBox::information(this, "Предупреждение!", "Процесс может занять больше 3 секунд");
        }
        //Обеление всей таблицы
        whiteMassive(&size);

        int i = 0;
        while(i<size)
        {
            if((i==0) or (mas[i-1]<=mas[i]))
            {
                i += 1;
            }
            else
            {
                int j = i - 1;
                double timen = mas[i];
                mas[i] = mas[j];
                mas[j] = timen;
                i=j;
            }
        }
        // вывод массива
        writeMassive(mas, size);
        if(qIsNaN(min))
        {
            ui->label_min->setText("-");
        }
        else
        {
            ui->label_min->setText(QString::number(min));
        }
        if(qIsNaN(max))
        {
            ui->label_max->setText("-");
        }
        else
        {
            ui->label_max->setText(QString::number(max));
        }
        if(qIsNaN(avg))
        {
            ui->label_avg->setText("-");
        }
        else
        {
            ui->label_avg->setText(QString::number(avg));
        }
        min=NAN;
        max=NAN;
        avg=NAN;
    }

    ui->textEdit_searchRows->setText("");
    ui->label_searchCount->setText("");
    delete [] mas;
    mas = NULL;
}

//Сортировка пузырьком
void MainWindow::on_pushButton_bubble_clicked()
{
    size = ui->tableWidget->rowCount();
    double *mas = new double[size]; // массив таблицы
    bool error;

    buttonturn=true;
    readMassive(mas, &size, &error); //считываем массив
    buttonturn=false;
    cellempty=false;

    sortturnf(mas, size, sortturn);
    bignumberf(mas, size,bignumber);

    if(sortturn or error or size == 0 or bignumber)
    {
        errorf(error, size, bignumber);//вызов ошибки при необходимости
    }
    else if(size>100000)
    {
        QMessageBox::information(this, "Предупреждение!", "Слишком большое значение для сортировки пузырьком");
    }
    else
    {
        if(size>30000)
        {
            QMessageBox::information(this, "Предупреждение!", "Процесс может занять больше 3 секунд");
        }
        //Обеление всей таблицы
        whiteMassive(&size);

        int i = 0;
        while(i<size-1)
        {
            int j = i + 1;
            while(j<size)
            {
                if(mas[i]>mas[j])
                {
                    double timen = mas[i];
                    mas[i] = mas[j];
                    mas[j] = timen;
                }
            j += 1;
            }
        i += 1;
        }
        // вывод массива
        writeMassive(mas, size);
        if(qIsNaN(min))
        {
            ui->label_min->setText("-");
        }
        else
        {
            ui->label_min->setText(QString::number(min));
        }
        if(qIsNaN(max))
        {
            ui->label_max->setText("-");
        }
        else
        {
            ui->label_max->setText(QString::number(max));
        }
        if(qIsNaN(avg))
        {
            ui->label_avg->setText("-");
        }
        else
        {
            ui->label_avg->setText(QString::number(avg));
        }
        min=NAN;
        max=NAN;
        avg=NAN;
    }

    ui->textEdit_searchRows->setText("");
    ui->label_searchCount->setText("");
    delete [] mas;
    mas = NULL;
}

//Быстрая сортировка
//Функция
void quickSort(double mas[], int left, int right)
{
    int i = left, j = right;
    double pivot = mas[(left + right) / 2];

    //разделение массива
    while (i <= j)
    {
        while (mas[i] < pivot)
            i++;
        while (mas[j] > pivot)
            j--;
        if (i <= j)
        {
            double timen = mas[i];
            mas[i] = mas[j];
            mas[j] = timen;
            i++;
            j--;
        }
    }
    //рекурсия
    if (left < j)
        quickSort(mas, left, j);
    if (i < right)
        quickSort(mas, i, right);
}
//Сортировка по кнопке
void MainWindow::on_pushButton_quick_clicked()
{
    size = ui->tableWidget->rowCount();
    double *mas = new double[size]; // массив таблицы
    bool error;

    if(randomturn)
    {
        sort = true;
    }
    buttonturn=true;
    readMassive(mas, &size, &error); //считываем массив
    buttonturn=false;
    cellempty=false;

    sortturnf(mas, size, sortturn);
    bignumberf(mas, size,bignumber);

    errorf(error, size, bignumber);//вызов ошибки при необходимости
    if(sortturn == false and !error and size>0 and !bignumber)
    {
        if(size>700000)
        {
            QMessageBox::information(this, "Предупреждение!", "Процесс может занять больше 3 секунд");
        }
        //Обеление всей таблицы
        whiteMassive(&size);

        quickSort(mas, 0, size-1);
        // вывод массива
        writeMassive(mas, size);
        if(qIsNaN(min))
        {
            ui->label_min->setText("-");
        }
        else
        {
            ui->label_min->setText(QString::number(min));
        }
        if(qIsNaN(max))
        {
            ui->label_max->setText("-");
        }
        else
        {
            ui->label_max->setText(QString::number(max));
        }
        if(qIsNaN(avg))
        {
            ui->label_avg->setText("-");
        }
        else
        {
            ui->label_avg->setText(QString::number(avg));
        }
        min=NAN;
        max=NAN;
        avg=NAN;
    }
    sort = false;

    ui->textEdit_searchRows->setText("");
    ui->label_searchCount->setText("");
    delete [] mas;
    mas = NULL;
}

//Обезъянья сортировка (bogosort)
//Функция
void monkeysort(double mas[], int size)
{
    bool neots = false;
    for(int i = 1; i<size; i++)
    {
        if(mas[i] < mas[i-1])
        {
            neots = true;
            break;
        }
    }


    if(neots == true)
    {
        for(int i=0;i<size;i++)
        {
            int j = i + rand() % (size - i);
            double timen = mas[i];
            mas[i] = mas[j];
            mas[j] = timen;
        }
        monkeysort(mas, size);
    }

}
//Сортировка по кнопке
void MainWindow::on_pushButton_monkey_clicked()
{
    size = ui->tableWidget->rowCount();
    double *mas = new double[size]; // массив таблицы
    bool error;

    buttonturn=true;
    readMassive(mas, &size, &error); //считываем массив
    buttonturn=false;
    cellempty=false;

    sortturnf(mas, size, sortturn);
    bignumberf(mas, size,bignumber);

    errorf(error, size, bignumber);//вызов ошибки при необходимости
    if(sortturn == false and !error and size>0 and !bignumber)
    {
        if(size>5)
        {
            QMessageBox::information(this, "Ошибка", "Для обезъяньей сортировки максимальное количество элементов в массиве равно 5");
            return;
        }
        else
        {
            //Обеление всей таблицы
            whiteMassive(&size);

            monkeysort(mas, size);
            // вывод массива
            writeMassive(mas, size);
            if(qIsNaN(min))
            {
                ui->label_min->setText("-");
            }
            else
            {
                ui->label_min->setText(QString::number(min));
            }
            if(qIsNaN(max))
            {
                ui->label_max->setText("-");
            }
            else
            {
                ui->label_max->setText(QString::number(max));
            }
            if(qIsNaN(avg))
            {
                ui->label_avg->setText("-");
            }
            else
            {
                ui->label_avg->setText(QString::number(avg));
            }
            min=NAN;
            max=NAN;
            avg=NAN;
        }
    }

    ui->textEdit_searchRows->setText("");
    ui->label_searchCount->setText("");
    delete [] mas;
    mas = NULL;
}



//Поиск

//Функция бинарного поиска
void binarysearch(double mas[], int size, int &k, double searchn, int &left, int &right)
{
    if (right >= left)
        {
            int middle = left + (right - left) / 2;

            if(mas[middle] == searchn)
            {
                right = middle;
                k++;
            }
            else if(mas[middle] > searchn)
            {
                right = middle - 1;
                binarysearch(mas, size, k, searchn, left, right);
            }
            else
            {
                left = middle + 1;
                binarysearch(mas, size, k, searchn, left, right);
            }
        }
}
//Начать поиск по кнопке
void MainWindow::on_search_clicked()
{
    size = ui->tableWidget->rowCount();
    double *mas = new double[size]; // массив таблицы
    bool error;

    buttonturn = true;

    searchbutton = true;
    readMassive(mas, &size, &error); //считываем массив
    buttonturn = false;
    cellempty = false;

    bignumberf(mas, size, bignumber);
    sortturnf(mas, size, sortturn);

    if(ui->lineEdit_searchValue->displayText().isEmpty())
    {
        ui->textEdit_searchRows->setText("");
        ui->label_searchCount->setText("");
        QMessageBox::information(this, "Ошибка", "Введите число для поиска");
    }
    else if(!error and size>0 and !bignumber)
    {
        double searchn = ui->lineEdit_searchValue->text().toDouble();
        QString searchRows;

        //Бинарный поиск
        if(sortturn == true)
        {
            int k = 0; //кол-во поискового числа
            int left = 0;
            int right = size-1;
            binarysearch(mas, size, k, searchn, left, right);
            if(k==0)
            {
                ui->textEdit_searchRows->setText("");
                ui->label_searchCount->setText("");
                QMessageBox::information(this, "Ошибка", "Нет поискового элемента");
            }
            else
            {
                k--;
                int j = right;
                while(mas[j] == searchn)
                {
                    j--;
                }
                j++;
                while(mas[j] == searchn)
                {
                    searchRows = searchRows + QString::number(j+1) + " ";
                    colorgreen=true;
                    ui->tableWidget->item(j, 0)->setBackground(Qt::green);
                    masgreen[j] = true;
                    green = true;
                    j++;
                    k++;
                }

                ui->textEdit_searchRows->setText(searchRows);
                ui->label_searchCount->setText(QString::number(k));
                searchturn = true;
            }
        }


        //Поиск перебором
        else
        {
            int k = 0; //кол-во поискового числа
            for(int i=0;i<size;i++)
            {
                if(mas[i]==searchn)
                {
                    k++;
                    searchRows = searchRows + QString::number(i+1) + " ";
                    colorgreen=true;
                    ui->tableWidget->item(i, 0)->setBackground(Qt::green);
                    masgreen[i] = true;
                    green = true;

                }
            }
            if(k==0)
            {
                ui->textEdit_searchRows->setText("");
                ui->label_searchCount->setText("");
                QMessageBox::information(this, "Ошибка", "Нет поискового элемента");
            }
            else
            {
                ui->textEdit_searchRows->setText(searchRows);
                ui->label_searchCount->setText(QString::number(k));
                searchturn = true;
            }
        }
    }
    else
    {
        errorf(error, size, bignumber);//вызов ошибки при необходимости
    }
    delete [] mas;
    mas = NULL;
    searchbutton = false;
}



//Заполнитель ячеек случайными числами
void MainWindow::on_pushButton_random_clicked()
{
    ui->label_min->setText("-");
    ui->label_avg->setText("-");
    ui->label_max->setText("-");
    ui->textEdit_searchRows->setText("");
    ui->label_searchCount->setText("");
    random=true;
    size = ui->tableWidget->rowCount();
    if(size>500000)
    {
        QMessageBox::information(this, "Предупреждение!", "Процесс может занять больше 3 секунд");
    }
    for(int i = 0; i < size; i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(QRandomGenerator::global()->bounded(-1000, 1000))));
        ui->tableWidget->item(i,0)->setBackground(Qt::white);
    }
    random=false;
    randomturn = true;

    min=NAN;
    max=NAN;
    avg=NAN;
}

//Удаление дубликатов
void MainWindow::on_pushButton_deleteDublicate_clicked()
{
    size = ui->tableWidget->rowCount();
    double *mas = new double[size]; // массив таблицы
    bool error;

    dubl = true;
    readMassive(mas, &size, &error); //считываем массив
    dubl = false;
    cellempty = false;

    sortturnf(mas, size, sortturn);
    bignumberf(mas, size,bignumber);
    //проверяем на ошибки
    if(error)
    {
        QMessageBox::information(this, "Ошибка", "В массиве некорректное значение");
        return;
    }
    else if(sortturn)
    {
        if(size==0)
        {
            ui->label_min->setText("-");
            ui->label_avg->setText("-");
            ui->label_max->setText("-");
            ui->textEdit_searchRows->setText("");
            ui->label_searchCount->setText("");
            QMessageBox::information(this, "Ошибка", "В массиве некорректное значение");
        }
        else if(bignumber)
        {
            ui->label_min->setText("-");
            ui->label_avg->setText("-");
            ui->label_max->setText("-");
            ui->textEdit_searchRows->setText("");
            ui->label_searchCount->setText("");
            QMessageBox::information(this, "Ошибка", "Слишком большое число в массиве");
        }
        else if(size>100000)
        {
            QMessageBox::information(this, "Предупреждение!", "Процесс может занять больше 3 секунд");
        }
        bool sovpad = true;
        for(int i = 0; i < size-1; i++)
        {
            if(mas[i] > mas[i+1])
            {
                sovpad = false;
                break;
            }
        }

        if(sovpad)
        {
            int rows = 1;
            int point = mas[0];
            mas[0] = point;
            for(int i = 1; i < size; i++)
            {
                if(point == mas[i])
                    continue;
                else
                {
                    point = mas[i];
                    mas[rows] = point;
                    rows++;
                }
            }
            ui->spinBox_count->setValue(rows);
            for (int i = 0; i < rows; i++)
            {
                QString numberText = QString::number(mas[i]);
                ui->tableWidget->setItem(i, 0, new QTableWidgetItem(numberText));
            }
        }
    }
    else
    {
        QMessageBox::information(this, "Ошибка", "Для удаления дубликатов массив должен быть отсортирован");
    }
    delete [] mas;
    mas = NULL;
}

//Обеление таблицы при изменении поискового числа
void MainWindow::on_lineEdit_searchValue_textChanged(const QString &arg1)
{
    if(green)
    {
        size = ui->tableWidget->rowCount();
        double *mas = new double[size]; // массив таблицы
        bool error;

        searchchange = true;
        readMassive(mas, &size, &error); //считываем массив

        for(int i=0; i<size;i++)
        {
            if(masgreen[i]==true)
            {
                QTableWidgetItem *item = ui->tableWidget->item(i, 0); //получаем указатель на ячейку
                item->setBackground(Qt::white);
                masgreen[i]=false;
            }
        }

        ui->textEdit_searchRows->setText("");
        ui->label_searchCount->setText("");
        green = false;
        searchchange = false;
        delete [] mas;
        mas = NULL;
    }
}
