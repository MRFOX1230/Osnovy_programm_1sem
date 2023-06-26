#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_score_lite->setReadOnly(true);
    ui->pushButton_clear->click();
    QPalette palette = this->palette();
    //palette.setColor(QPalette::Window, Qt::gray);
    window()->setStyleSheet("background-image: url(D:/Studies/Programms/Character/Character/Images/fone.jpg);");
    this->setPalette(palette); //устанавливаем измененную палитру
    ui->lineEdit_score_lite->setStyleSheet("color: blue");

    ui->label_stroch->setStyleSheet("color: blue");
    ui->label_dexoch->setStyleSheet("color: blue");
    ui->label_intoch->setStyleSheet("color: blue");
    ui->label_luckoch->setStyleSheet("color: blue");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clear_clicked()
{
    ui->lineEdit_name->clear();
    ui->lineEdit_str->clear();
    ui->lineEdit_dex->clear();
    ui->lineEdit_int->clear();
    ui->lineEdit_luck->clear();

    ui->label_hp_value->clear();
    ui->label_mp_value->clear();
    ui->label_atk_value->clear();
    ui->label_def_value->clear();
    ui->label_class_value->clear();

    ui->radioButton_sex_m->setChecked(true);
    ui->lineEdit_score_lite->setText("20");

    ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/0.jpg);");
    ui->label_hello->setText("");

    ui->label_str->setStyleSheet("color: black");
    ui->label_dex->setStyleSheet("color: black");
    ui->label_int->setStyleSheet("color: black");
    ui->label_luck->setStyleSheet("color: black");

    ui->label_stroch->setText("1-10");
    ui->label_dexoch->setText("1-8");
    ui->label_intoch->setText("1-8");
    ui->label_luckoch->setText("1-10");


}


void MainWindow::on_pushButton_creat_clicked()
{
    QString name;//имя
    int dlina_stroki;//длина строки
    bool flag;//успешность генерации

    name = ui->lineEdit_name->text();
    QString name1 = name;
    dlina_stroki = name.length();//определили длину имени
    if((dlina_stroki<3) || (dlina_stroki>20))
    {
        flag = false;
        QMessageBox::information(this, "Ошибка", "Имя должно быть длиной от 3 до 20 символов.", QMessageBox::Ok);
        ui->label_hello->setText("");
    }
    else
    {
        flag = true;

        //Сила
        if(flag)
        {
            str = ui->lineEdit_str->text().toInt(&flag);

            if(flag)
            {
                if(((str<1) || (str>10)) and ui->radioButton_sex_m->isChecked())
                {
                    flag = false;
                    QMessageBox::information(this, "Ошибка", "\"Сила\" должна быть от 1 до 10 для мужского пола.", QMessageBox::Ok);
                }
                if(((str<1) || (str>8)) and ui->radioButton_sex_f->isChecked())
                {
                    flag = false;
                    QMessageBox::information(this, "Ошибка", "\"Сила\" должна быть от 1 до 8 для женского пола.", QMessageBox::Ok);
                }
            }
        else
        {
               QMessageBox::information(this, "Ошибка", "Неправильное значение параметра \"Сила\".", QMessageBox::Ok);
        }
        }


        //Ловкость
        if(flag)
        {
            dex = ui->lineEdit_dex->text().toInt(&flag);

            if(flag)
            {
                if(((dex<1) || (dex>8)) and ui->radioButton_sex_m->isChecked())
                {
                    flag = false;
                    QMessageBox::information(this, "Ошибка", "\"Ловкость\" должна быть от 1 до 8 для мужского пола.", QMessageBox::Ok);
                }
                if(((dex<1) || (dex>10)) and ui->radioButton_sex_f->isChecked())
                {
                    flag = false;
                    QMessageBox::information(this, "Ошибка", "\"Ловкость\" должна быть от 1 до 10.", QMessageBox::Ok);
                }

            }
        else
        {
               QMessageBox::information(this, "Ошибка", "Неправильное значение параметра \"Ловкость\".", QMessageBox::Ok);
        }
        }



        //Интеллект
        if(flag)
        {
            intel = ui->lineEdit_int->text().toInt(&flag);

            if(flag)
            {
                if(((intel<1) or (intel>8)) and ui->radioButton_sex_m->isChecked())
                {
                    flag = false;
                    QMessageBox::information(this, "Ошибка", "\"Интеллект\" должен быть от 1 до 8 для мужского пола.", QMessageBox::Ok);
                }
                if(((intel<1) || (intel>10)) and ui->radioButton_sex_f->isChecked())
                {
                    flag = false;
                    QMessageBox::information(this, "Ошибка", "\"Интеллект\" должен быть от 1 до 10 для женсого пола.", QMessageBox::Ok);
                }
            }
        else
        {
               QMessageBox::information(this, "Ошибка", "Неправильное значение параметра \"Интеллект\".", QMessageBox::Ok);
        }
        }


        //Удача
        if(flag)
        {
            luck = ui->lineEdit_luck->text().toInt(&flag);

            if(flag)
            {
                if(((luck<1) || (luck>10)) and ui->radioButton_sex_m->isChecked())
                {
                    flag = false;
                    QMessageBox::information(this, "Ошибка", "\"Удача\" должна быть от 1 до 10 для мужского пола.", QMessageBox::Ok);
                }
                if(((luck<1) || (luck>8)) and ui->radioButton_sex_f->isChecked())
                {
                    flag = false;
                    QMessageBox::information(this, "Ошибка", "\"Удача\" должна быть от 1 до 8 для женского пола.", QMessageBox::Ok);
                }
            }
        else
        {
               QMessageBox::information(this, "Ошибка", "Неправильное значение параметра \"Удача\".", QMessageBox::Ok);
        }
        }


        //проверка на количество очков
        if(flag)
        {
            int points1 = 20 - str - dex - intel - luck;//сколько осталось неиспользованных очков
            if(points1 != 0)
            {
                flag=false;
                if(points1>0)
                {
                    QMessageBox::information(this, "Ошибка", "Надо потратить все очки", QMessageBox::Ok);
                }
                else
                {
                    QMessageBox::information(this, "Ошибка", "Нельзя тратить больше 20 очков", QMessageBox::Ok);
                }
            }

        }

        //расчет параметров и вывод результата
        if(flag)
        {
            int hp, mp, atk, def;
            hp = 8*str + 2*dex;
            mp = 8*intel + dex + luck;
            atk = 6*str + 2*dex + 2*luck;
            def = 7*dex + 3*luck;

            int n = 50;

            ui->label_hp_value->setNum(hp);
            ui->label_mp_value->setNum(mp);
            ui->label_atk_value->setNum(atk);
            ui->label_def_value->setNum(def);
            //класс самостоятельно с учетом пола

            if(atk >= n and hp >= n and mp < n and def < n and ui->radioButton_sex_m->isChecked())
            {
                ui->label_class_value->setText("Воитель");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/1.1.jpg);");
            }
            else if(atk >= n and hp >= n and mp < n and def < n and ui->radioButton_sex_f->isChecked())
            {
                ui->label_class_value->setText("Валькирия");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/1.2.jpg);");
            }

            else if(mp >= n and atk >= n and def < n and hp >= n and ui->radioButton_sex_m->isChecked())
            {
                ui->label_class_value->setText("Ведьмак");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/2.1.jpg);");
            }
            else if(mp >= n and atk >= n and def < n and hp >= n and ui->radioButton_sex_f->isChecked())
            {
                ui->label_class_value->setText("Ведьма");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/2.2.jpg);");
            }

            else if(mp >= n and def >= n and hp < n and atk < n and ui->radioButton_sex_m->isChecked())
            {
                ui->label_class_value->setText("Монах");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/3.1.jpg);");
            }
            else if(mp >= n and def >= n and hp < n and atk < n and ui->radioButton_sex_f->isChecked())
            {
                ui->label_class_value->setText("Монахиня");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/3.2.jpg);");
            }

            else if(def >= n and atk >= n and hp >= n and mp < n and ui->radioButton_sex_m->isChecked())
            {
                ui->label_class_value->setText("Лучник");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/4.1.jpg);");
            }
            else if(def >= n and atk >= n and hp >= n and mp < n and ui->radioButton_sex_f->isChecked())
            {
                ui->label_class_value->setText("Лучница");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/4.2.jpg);");
            }

            else if((mp >= n and hp >= n and def < n and atk < n) and ui->radioButton_sex_m->isChecked())
            {
                ui->label_class_value->setText("Целитель");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/5.1.jpg);");
            }
            else if((mp >= n and hp >= n and def < n and atk < n) and ui->radioButton_sex_f->isChecked())
            {
                ui->label_class_value->setText("Целительница");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/5.2.png);");

            }

            else if(hp >= n and def >= n and atk < n and mp < n and ui->radioButton_sex_m->isChecked())
            {
                ui->label_class_value->setText("Ассасин");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/6.1.jpg);");
            }
            else if(hp >= n and def >= n and atk < n and mp < n and ui->radioButton_sex_f->isChecked())
            {
                ui->label_class_value->setText("Ассасинша");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/6.2.jpg);");
            }

            else if(mp >= n and atk < n and def < n and hp < n and ui->radioButton_sex_m->isChecked())
            {
                ui->label_class_value->setText("Друид");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/7.1.jpg);");
            }
            else if(mp >= n and atk < n and def < n and hp < n and ui->radioButton_sex_f->isChecked())
            {
                ui->label_class_value->setText("Друидша");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/7.2.jpg);");
            }

            else if(mp < n and atk >= n and def < n and hp < n and ui->radioButton_sex_m->isChecked())
            {
                ui->label_class_value->setText("Варвар");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/8.1.jpg);");
            }
            else if(mp < n and atk >= n and def < n and hp < n and ui->radioButton_sex_f->isChecked())
            {
                ui->label_class_value->setText("Варварша");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/8.2.jpg);");
            }

            else if(mp < n and atk >= n and def >= n and hp < n and ui->radioButton_sex_m->isChecked())
            {
                ui->label_class_value->setText("Рыцарь смерти");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/9.1.jpg);");
            }
            else if(mp < n and atk >= n and def >= n and hp < n and ui->radioButton_sex_f->isChecked())
            {
                ui->label_class_value->setText("Рыцарша смерти");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/9.2.png);");
            }

            else if(ui->radioButton_sex_m->isChecked())
            {
                ui->label_class_value->setText("Авантюрист");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/10.1.jpg);");
            }
            else if(ui->radioButton_sex_f->isChecked())
            {
                ui->label_class_value->setText("Авантюристка");
                ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/10.2.jpg);");
            }


            if(ui->radioButton_sex_m->isChecked())
            {
                ui->label_hello->setText("А вот и ваш персонаж, Мистер " + name1 + "!");
            }
            else if(ui->radioButton_sex_f->isChecked())
            {
                ui->label_hello->setText("А вот и ваш персонаж, Миссис " + name1 + "!");
            }
        }

        //при неверных данных очищаем результаты
        else
        {
            ui->label_hp_value->clear();
            ui->label_mp_value->clear();
            ui->label_atk_value->clear();
            ui->label_def_value->clear();
            ui->label_class_value->clear();

            ui->image->setStyleSheet("border-image: url(D:/Studies/Programms/Character/Character/Images/0.jpg);");
            ui->label_hello->setText("");
        }
    }
}


void MainWindow::on_lineEdit_str_textChanged(const QString &arg1)
{
    str = arg1.toInt();
    int points = 20 - str - dex - intel - luck;
    ui->lineEdit_score_lite->setText(QString::number(points));
    if(str>=1 and str<=3)
    {
        ui->label_str->setStyleSheet("color: red");
    }
    else if(str>=4 and str<=6)
    {
        ui->label_str->setStyleSheet("color: yellow");
    }
    else if(str>=7 and str<=10 and ui->radioButton_sex_m->isChecked())
    {
        ui->label_str->setStyleSheet("color: green");
    }
    else if(str>=7 and str<=8 and ui->radioButton_sex_f->isChecked())
    {
        ui->label_str->setStyleSheet("color: green");
    }
    else if (str>=11 and ui->radioButton_sex_m->isChecked())
    {
        ui->label_str->setStyleSheet("color: black");
    }
    else if (str>=9 and ui->radioButton_sex_f->isChecked())
    {
        ui->label_str->setStyleSheet("color: black");
    }
    else
    {
        str = 0; //записываем 0, чтобы не было мусора
        ui->label_str->setStyleSheet("color: black");
        int points = 20 - str - dex - intel - luck;
        ui->lineEdit_score_lite->setText(QString::number(points));
    }
}
void MainWindow::on_lineEdit_dex_textChanged(const QString &arg2)
{
    dex = arg2.toInt();
    int points = 20 - str - dex - intel - luck;
    ui->lineEdit_score_lite->setText(QString::number(points));
    if(dex>=1 and dex<=3)
    {
        ui->label_dex->setStyleSheet("color: red");
    }
    else if(dex>=4 and dex<=6)
    {
        ui->label_dex->setStyleSheet("color: yellow");
    }
    else if(dex>=7 and dex<=10 and ui->radioButton_sex_f->isChecked())
    {
        ui->label_dex->setStyleSheet("color: green");
    }
    else if(dex>=7 and dex<=8 and ui->radioButton_sex_m->isChecked())
    {
        ui->label_dex->setStyleSheet("color: green");
    }
    else if (dex>=11 and ui->radioButton_sex_f->isChecked())
    {
        ui->label_dex->setStyleSheet("color: black");
    }
    else if (dex>=9 and ui->radioButton_sex_m->isChecked())
    {
        ui->label_dex->setStyleSheet("color: black");
    }
    else
    {
        dex = 0; //записываем 0, чтобы не было мусора
        ui->label_dex->setStyleSheet("color: black");
        int points = 20 - str - dex - intel - luck;
        ui->lineEdit_score_lite->setText(QString::number(points));
    }
}
void MainWindow::on_lineEdit_int_textChanged(const QString &arg3)
{
    intel = arg3.toInt();
    int points = 20 - str - dex - intel - luck;
    ui->lineEdit_score_lite->setText(QString::number(points));
    if(intel>=1 and intel<=3)
    {
        ui->label_int->setStyleSheet("color: red");
    }
    else if(intel>=4 and intel<=6)
    {
        ui->label_int->setStyleSheet("color: yellow");
    }
    else if(intel>=7 and intel<=10 and ui->radioButton_sex_f->isChecked())
    {
        ui->label_int->setStyleSheet("color: green");
    }
    else if(intel>=7 and intel<=8 and ui->radioButton_sex_m->isChecked())
    {
        ui->label_int->setStyleSheet("color: green");
    }
    else if (intel>=11 and ui->radioButton_sex_f->isChecked())
    {
        ui->label_int->setStyleSheet("color: black");
    }
    else if (intel>=9 and ui->radioButton_sex_m->isChecked())
    {
        ui->label_int->setStyleSheet("color: black");
    }
    else
    {
        intel = 0; //записываем 0, чтобы не было мусора
        ui->label_int->setStyleSheet("color: black");
        int points = 20 - str - dex - intel - luck;
        ui->lineEdit_score_lite->setText(QString::number(points));
    }
}
void MainWindow::on_lineEdit_luck_textChanged(const QString &arg4)
{
    luck = arg4.toInt();
    int points = 20 - str - dex - intel - luck;
    ui->lineEdit_score_lite->setText(QString::number(points));
    if(luck>=1 and luck<=3)
    {
        ui->label_luck->setStyleSheet("color: red");
    }
    else if(luck>=4 and luck<=6)
    {
        ui->label_luck->setStyleSheet("color: yellow");
    }
    else if(luck>=7 and luck<=10 and ui->radioButton_sex_m->isChecked())
    {
        ui->label_luck->setStyleSheet("color: green");
    }
    else if(luck>=7 and luck<=8 and ui->radioButton_sex_f->isChecked())
    {
        ui->label_luck->setStyleSheet("color: green");
    }
    else if (luck>=11 and ui->radioButton_sex_m->isChecked())
    {
        ui->label_luck->setStyleSheet("color: black");
    }
    else if (luck>=9 and ui->radioButton_sex_f->isChecked())
    {
        ui->label_luck->setStyleSheet("color: black");
    }
    else
    {
        luck = 0; //записываем 0, чтобы не было мусора
        ui->label_luck->setStyleSheet("color: black");
        int points = 20 - str - dex - intel - luck;
        ui->lineEdit_score_lite->setText(QString::number(points));
    }
}


void MainWindow::on_radioButton_sex_m_clicked(bool)
{
    ui->label_stroch->setText("1-10");
    ui->label_dexoch->setText("1-8");
    ui->label_intoch->setText("1-8");
    ui->label_luckoch->setText("1-10");

    //Заглушка
    if(str>=1 and str<=3)
    {
        ui->label_str->setStyleSheet("color: red");
    }
    else if(str>=4 and str<=6)
    {
        ui->label_str->setStyleSheet("color: yellow");
    }
    else if(str>=7 and str<=10)
    {
        ui->label_str->setStyleSheet("color: green");
    }
    else
    {
        ui->label_str->setStyleSheet("color: black");
    }

    if(dex>=1 and dex<=3)
    {
        ui->label_dex->setStyleSheet("color: red");
    }
    else if(dex>=4 and dex<=6)
    {
        ui->label_dex->setStyleSheet("color: yellow");
    }
    else if(dex>=7 and dex<=8)
    {
        ui->label_dex->setStyleSheet("color: green");
    }
    else
    {
        ui->label_dex->setStyleSheet("color: black");
    }

    if(intel>=1 and intel<=3)
    {
        ui->label_int->setStyleSheet("color: red");
    }
    else if(intel>=4 and intel<=6)
    {
        ui->label_int->setStyleSheet("color: yellow");
    }
    else if(intel>=7 and intel<=8)
    {
        ui->label_int->setStyleSheet("color: green");
    }
    else
    {
        ui->label_int->setStyleSheet("color: black");
    }

    if(luck>=1 and luck<=3)
    {
        ui->label_luck->setStyleSheet("color: red");
    }
    else if(luck>=4 and luck<=6)
    {
        ui->label_luck->setStyleSheet("color: yellow");
    }
    else if(luck>=7 and luck<=10)
    {
        ui->label_luck->setStyleSheet("color: green");
    }
    else
    {
        ui->label_luck->setStyleSheet("color: black");
    }
}


void MainWindow::on_radioButton_sex_f_clicked(bool)
{
    ui->label_stroch->setText("1-8");
    ui->label_dexoch->setText("1-10");
    ui->label_intoch->setText("1-10");
    ui->label_luckoch->setText("1-8");

    //Заглушка
    if(str>=1 and str<=3)
    {
        ui->label_str->setStyleSheet("color: red");
    }
    else if(str>=4 and str<=6)
    {
        ui->label_str->setStyleSheet("color: yellow");
    }
    else if(str>=7 and str<=8)
    {
        ui->label_str->setStyleSheet("color: green");
    }
    else
    {
        ui->label_str->setStyleSheet("color: black");
    }

    if(dex>=1 and dex<=3)
    {
        ui->label_dex->setStyleSheet("color: red");
    }
    else if(dex>=4 and dex<=6)
    {
        ui->label_dex->setStyleSheet("color: yellow");
    }
    else if(dex>=7 and dex<=10)
    {
        ui->label_dex->setStyleSheet("color: green");
    }
    else
    {
        ui->label_dex->setStyleSheet("color: black");
    }

    if(intel>=1 and intel<=3)
    {
        ui->label_int->setStyleSheet("color: red");
    }
    else if(intel>=4 and intel<=6)
    {
        ui->label_int->setStyleSheet("color: yellow");
    }
    else if(intel>=7 and intel<=10)
    {
        ui->label_int->setStyleSheet("color: green");
    }
    else
    {
        ui->label_int->setStyleSheet("color: black");
    }

    if(luck>=1 and luck<=3)
    {
        ui->label_luck->setStyleSheet("color: red");
    }
    else if(luck>=4 and luck<=6)
    {
        ui->label_luck->setStyleSheet("color: yellow");
    }
    else if(luck>=7 and luck<=8)
    {
        ui->label_luck->setStyleSheet("color: green");
    }
    else
    {
        ui->label_luck->setStyleSheet("color: black");
    }
}
