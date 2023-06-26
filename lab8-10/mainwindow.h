#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void readMassive(double *mas, int *size, bool *error); //функция для считывания массива

    void writeMassive(double *mas, int size); //функция для вывода массива в таблицу

    void whiteMassive(int *size);

    void errorf(bool error, int size, bool bignumber);



private slots:
    void on_spinBox_count_valueChanged(int arg1);

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

    void on_pushButton_min_clicked();

    void on_pushButton_comb_clicked();


    void on_pushButton_max_clicked();

    void on_pushButton_avg_clicked();

    void on_pushButton_gnom_clicked();

    void on_pushButton_bubble_clicked();

    void on_pushButton_quick_clicked();

    void on_pushButton_monkey_clicked();

    void on_search_clicked();

    void on_pushButton_random_clicked();

    void on_pushButton_deleteDublicate_clicked();

    void on_lineEdit_searchValue_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    const int mascount = 1000000;//максимальный размер массива

    bool sortturn = false; //флаг отсортированности массива

    bool bignumber = false;//предельное подставляемое число

    double min=std::numeric_limits<double>::quiet_NaN(); //то же самое, что и NAN
    double max=std::numeric_limits<double>::quiet_NaN();
    double avg=std::numeric_limits<double>::quiet_NaN();

    bool colorgreen = false; //проверка зеленой ячейки в таблице

    bool random=false; //истинность того, является ли данное число полученным в генераторе случайных чисел

    bool randomturn = false; //включен ли заполнитель чисел
    bool sort = false; //флаг истинности при сортировке случайных чисел (сделанных через заполнитель)

    int size = 0; //кол-во ячеек в таблице

    bool color = false; //проверка, есть ли в таблице перекрашенная зеленая ячейка

    bool searchchange = false; //изменено ли число в поисковике
    bool searchturn = false; //включен ли поиск чисел
    bool searchbutton = false; //флаг нажатия кнопки поиска (для исключения случая очистки max, min и ср. значений, в остальных случаях используется buttonturn)

    bool buttonturn = false; //включение функции по кнопке
    bool cellempty = false; //есть хотя бы одна не проинициализированная ячейка

    bool masgreen[1000000]; //истинность ячеек на зеленый цвет
    bool green = false;// есть в таблице впринципе зеленый цвет

    bool dubl = false; //истинность включения удаления дубликатов




};
#endif // MAINWINDOW_H
