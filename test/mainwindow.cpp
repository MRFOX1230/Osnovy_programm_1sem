#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "cmath"
#include <typeinfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




// В общем, тут собраны все (вроде) программы на экзамен по проге, можете их использовать как хотите, ваше дело, хоть списать 1 в 1, я делал это для себя,
// но скинуть вам это буквально пара кнопок, поэтому вот


// ИНСТРУКЦИЯ: Все коды закоменчены, если хотите раскоментить - выделяете и нажимаете ctrl + / (который слева от правого shift), интерфейс был сделан
// адаптивным под все проги, чтобы не делать кучу интерфейсов, а также мне было лень делать эти ваши проверки на число/не число, это делается легко,
// это всё есть в прошлых программах, поэтому не вижу смысла, на это всё, можете смотреть





// Обновление массива внутри кода
void MainWindow::updateArray()
{
    for (int i = 0; i < array.size(); i++)
    {
        double number = ui->elementArray->item(i, 0)->text().toDouble(); // Записываем в переменную number значение строки из таблицы массив
        array[i] = number;
    }
}

// Обновление количесва строк от введённого числа
void MainWindow::on_spinBoxNumberOfElements_valueChanged(int arg1)
{
    ui->elementArray->setRowCount(arg1); //Количество элементов массива
    array.resize(arg1);
}

// Рандомайзер массива
void MainWindow::on_pushButtonRandom_clicked()
{
    for (int i = 0; i < array.size(); i++)
    {
        int randomNumber = rand()%10000;
        array[i] = randomNumber;
        ui->elementArray->setItem(i, 0, new QTableWidgetItem(QString::number(randomNumber))); // Записываем в массив и таблицу одинаковое рандомное число randomNumber
    }
}

// Факториал
int MainWindow::fact(int number)
{
    if (number == 1)
    {
        return 1; // Если число уже равно 1, то значит мы дошли до конца (начала) факториала, значит идти больше не зачем в рекурсию
    }
    return number * fact(number - 1); // Рекурсия, вызываем функцию от числа на 1 меньше (5! = 5 * 4!; 4! = 4 * 3! и т.д.)
}



// Программы билетов:
void MainWindow::on_pushButtonSearch_clicked()
{
    updateArray();

    int rows = array.size();
    int count = 1; // Счётчик
    int maximumNumberCount = 0; // Максимальное число чего-либо (зависит от программы)

    QVector<double> answersArray(2); // Создаём массив для ответов
    QVector<double> newArray = array; // Создаём копию основного массива

    std::sort(newArray.begin(), newArray.end()); // Сортируем копию основного массива



    // Нахождение самого часто встречающегося значения в массиве:

//    for (int i = 0; i < rows-1; i++)
//    {
//        if (fabs(newArray[i] - newArray[i+1]) < EPS) // Сравнение 2 чисел с плавающей точкой (ЭТО РАВЕНСТВО, как a == b), EPS - константа,
                                                                                                    // которую я обозначил в заголовочном файле
//        {
//            count += 1; // Считаем количество повторяющихся элементов (count в Питоне)
//        }

//        else
//        {
//            if (maximumNumberCount < count)
//            {
//                maximumNumberCount = count; // Если цепочка закончилась - записываем максимальное между её длиной и максимально найденной цепочкой до
//                answersArray[0] = newArray[i]; // В том же случае записываем и сам элемент
//            }
//            count = 1; // Обнуления счётчика
//        }
//    }
//    if (maximumNumberCount < count)
//    {
//        maximumNumberCount = count;
//        answersArray[0] = newArray[newArray.size()-1]; // Записываем последний элемент отсортированного массива, если последняя цепочка - искомая (наибольшая)
//    }

//    ui->labelAnswer->setNum(answersArray[0]);



    // Количество положительных элементов, меньше 100 в массиве произвольного размера

//    count = 0;
//    for (int i = 0; i < rows; i++)
//    {
//        if (newArray[i] > 0 and newArray[i] < 100)
//        {
//            count += 1;
//        }

//        if (newArray[i] >= 100)
//        {
//            break;
//        }
//    }

//    ui->labelAnswer->setNum(count);



    // Факториал через рекурсию:

//    int number = ui->lineEditNumberSearch->text().toInt();
//    ui->labelAnswer->setNum(fact(number)); // Функцию смотреть выше на 46 строке



    // Сумма элементов массива с чётными индексами:

//    qint64 count64 = 0;
//    double countDouble = 0;
//    for (int i = 0; i < rows; i+=2) // Просто считаем количество всех элементов, идя только по чётным индексами (через 1)
//    {
//        count64 += array[i]; // Так как сумма 1 миллиона элементов может быть больше, чем вмещается в int, используем int64
//        countDouble += array[i]; // Так как сумма возможно будет не целым значением, посчитаем и её
//    }

//    if (countDouble <= 0) // Если в double не помещается число, то программа сама забивает его мусором, меньше 0, поэтому такая проверка
//        ui->labelAnswer->setText(QString::number(count64)); // int64 Нельзя записывать через setNum, но можно преобразовать в текст, поэтому так
//    else
//        ui->labelAnswer->setNum(countDouble); // Если в double помещается сумма, то мы выписываем его, даже если ответ целочисленный



    // Сумма нечётных элементов массива:

// В общем всё абсолютно также, как и в предыдущей, но вместо i+=2 просто i++ и добавить условие if (array[i] % 2 != 0) - это условие нечётности



    // Самое редко встречающееся значение в массиве:

//    maximumNumberCount = INT_MAX; // Присваиваем переменной максимальное значение ВНИМАНИЕ! мне лень создавать новую переменную, но это - МИНИМУМ minimumNumberCount
//    for (int i = 0; i < rows-1; i++)
//    {
//        if (fabs(newArray[i] - newArray[i+1]) < EPS) // См. комментарий в самой первой проге
//        {
//            count += 1; // Считаем количество повторяющихся элементов (count в Питоне)
//        }

//        else
//        {
//            if (maximumNumberCount > count)
//            {
//                maximumNumberCount = count; // Если цепочка закончилась - записываем максимальное между её длиной и максимально найденной цепочкой до
//                answersArray[0] = newArray[i]; // В том же случае записываем и сам элемент
//            }
//            count = 1; // Обнуление счётчика
//        }
//    }
//    if (maximumNumberCount > count)
//    {
//        maximumNumberCount = count;
//        answersArray[0] = newArray[newArray.size()-1]; // Записываем последний элемент отсортированного массива, если последняя цепочка - искомая (наибольшая)
//    }

//    ui->labelAnswer->setNum(answersArray[0]);



    // Десятичное число в двоичную систему:

//    int numberIn10th = ui->lineEditNumberSearch->text().toInt();
//    QString numberIn2th = "";

//    int numberIn10thAbs = abs(numberIn10th); // Ищем модуль, чтобы отрицательные числа не мешали

//    while (numberIn10thAbs > 0)
//    {
//        numberIn2th = QString::number(numberIn10thAbs % 2) + numberIn2th; // Остаток от деления прибавляем к двоичному числу (именно в таком порядке)
//        numberIn10thAbs /= 2; // Делим изначальное число целочисленно на 2
//    }

//    if (numberIn10th < 0)
//    {
//        ui->labelAnswer->setText("-" + numberIn2th); // На случай, если будут вводить и отрицательные числа (Карпов может)
//    }
//    else
//    {
//        ui->labelAnswer->setText(numberIn2th);
//    }




    // Десятичное число в шестнацатеричную систему:

//    QVector<char> alphabetOf16th = {'A','B', 'C', 'D', 'E', 'F'};

//    int numberIn10th = ui->lineEditNumberSearch->text().toInt();
//    QString numberIn16th = "";

//    int numberIn10thAbs = abs(numberIn10th); // Ищем модуль, чтобы отрицательные числа не мешали

//    while (numberIn10thAbs > 0)
//    {
//        if (numberIn10thAbs % 16 >= 10)
//        {
//            numberIn16th = alphabetOf16th[numberIn10thAbs % 16 - 10] + numberIn16th; // Так как система счисления больше 10, нам нужны буквы,
// // их мы добавляем через созданный ранее алфавит и просто записываем букву с индексом равным остатку от деления -10 (-10, т.к я не стал записывать все 10 цифр в алфавит)
//        }
//        else
//        {
//            numberIn16th = QString::number(numberIn10thAbs % 16) + numberIn16th; // Остаток от деления прибавляем к шеснадцатеричному числу (именно в таком порядке)
//        }
//        numberIn10thAbs /= 16; // Делим изначальное число целочисленно на 16
//    }

//    if (numberIn10th < 0)
//    {
//        ui->labelAnswer->setText('-' + numberIn16th); // На случай, если будут вводить и отрицательные числа (Карпов может)
//    }
//    else
//    {
//        ui->labelAnswer->setText(numberIn16th);
//    }



    // Какая-то дичь на определение типа:

//    bool isNumberInt;
//    bool isNumberDouble;

//    ui->lineEditNumberSearch->text().toInt(&isNumberInt); // Проверяем, является ли число int
//    ui->lineEditNumberSearch->text().toDouble(&isNumberDouble); // Или оно double

//    if (ui->lineEditNumberSearch->text().isEmpty()) // Проверяем на пустую строку
//    {
//        ui->labelAnswer->setText("Пустая строка");
//        setStyleSheet("background-color: blue;"); // Делаем экран этим стилем
//    }

//    else if (isNumberInt)
//    {
//        ui->labelAnswer->setText("Целое число");
//        setStyleSheet("background-color: red;");
//    }
//    else if (isNumberDouble)
//    {
//        ui->labelAnswer->setText("Вещественное число");
//        setStyleSheet("background-color: green;");
//    }

//    else // Если ничего не подошло, значит это не число
//    {
//        ui->labelAnswer->setText("Не число");
//        setStyleSheet("background-color: yellow;");
//    }




    // Произведение положительных

// Один в один, как с суммой, но тут произведение + условие на положительность (>0) и все числа, то есть вместо i+=2, i++




    // Количество отрицательных элементов

//    count = 0;
//    for (int i = 0; i < rows; ++i)
//    {
//        if (array[i] < 0)
//        {
//           count += 1; // Ничего сложного, там будет + 1 условие на больше, чем что-то, этого не видно, поэтому я забил, но это просто +1 условие добавить
//        }
//    }
//    ui->labelAnswer->setNum(count);
}
