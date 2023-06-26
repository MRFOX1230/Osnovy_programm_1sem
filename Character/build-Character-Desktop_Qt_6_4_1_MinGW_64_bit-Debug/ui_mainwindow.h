/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_name;
    QLabel *label_name;
    QLineEdit *lineEdit_str;
    QLineEdit *lineEdit_dex;
    QLineEdit *lineEdit_int;
    QLineEdit *lineEdit_luck;
    QLineEdit *lineEdit_score_lite;
    QLabel *label_score_lite;
    QLabel *label_class;
    QLabel *label_class_value;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_creat;
    QLabel *image;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_hp;
    QLabel *label_hp_value;
    QLabel *label_mp;
    QLabel *label_mp_value;
    QLabel *label_atk;
    QLabel *label_atk_value;
    QLabel *label_def;
    QLabel *label_def_value;
    QLabel *label_hello;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_sex;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_sex_m;
    QRadioButton *radioButton_sex_f;
    QWidget *layoutWidget2;
    QFormLayout *formLayout_2;
    QLabel *label_str;
    QLabel *label_stroch;
    QWidget *layoutWidget3;
    QFormLayout *formLayout_3;
    QLabel *label_dex;
    QLabel *label_dexoch;
    QWidget *layoutWidget4;
    QFormLayout *formLayout_4;
    QLabel *label_int;
    QLabel *label_intoch;
    QWidget *layoutWidget5;
    QFormLayout *formLayout_5;
    QLabel *label_luck;
    QLabel *label_luckoch;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1074, 553);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit_name = new QLineEdit(centralwidget);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(91, 61, 291, 42));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable Small Semibol")});
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        lineEdit_name->setFont(font);
        lineEdit_name->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));
        label_name = new QLabel(centralwidget);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(10, 60, 71, 33));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Variable Text Semibold")});
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        label_name->setFont(font1);
        label_name->setStyleSheet(QString::fromUtf8("font: 81 16pt \"Rockwell Extra Bold\";\n"
"font: 63 16pt \"Segoe UI Variable Text Semibold\";\n"
"font: 8pt \"Snap ITC\";\n"
"font: 16pt \"MS Shell Dlg 2\";\n"
"font: 16pt \"Pristina\";\n"
"font: 75 16pt \"Script MT Bold\";\n"
"font: 75 16pt \"MS Shell Dlg 2\";\n"
"font: 63 16pt \"Segoe UI Variable Text Semibold\";"));
        lineEdit_str = new QLineEdit(centralwidget);
        lineEdit_str->setObjectName("lineEdit_str");
        lineEdit_str->setGeometry(QRect(240, 140, 141, 39));
        lineEdit_str->setFont(font);
        lineEdit_str->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));
        lineEdit_dex = new QLineEdit(centralwidget);
        lineEdit_dex->setObjectName("lineEdit_dex");
        lineEdit_dex->setGeometry(QRect(240, 185, 141, 39));
        lineEdit_dex->setFont(font);
        lineEdit_dex->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));
        lineEdit_int = new QLineEdit(centralwidget);
        lineEdit_int->setObjectName("lineEdit_int");
        lineEdit_int->setGeometry(QRect(240, 230, 141, 39));
        lineEdit_int->setFont(font);
        lineEdit_int->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));
        lineEdit_luck = new QLineEdit(centralwidget);
        lineEdit_luck->setObjectName("lineEdit_luck");
        lineEdit_luck->setGeometry(QRect(240, 275, 141, 39));
        lineEdit_luck->setFont(font);
        lineEdit_luck->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));
        lineEdit_score_lite = new QLineEdit(centralwidget);
        lineEdit_score_lite->setObjectName("lineEdit_score_lite");
        lineEdit_score_lite->setGeometry(QRect(240, 320, 71, 39));
        lineEdit_score_lite->setFont(font);
        lineEdit_score_lite->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));
        label_score_lite = new QLabel(centralwidget);
        label_score_lite->setObjectName("label_score_lite");
        label_score_lite->setGeometry(QRect(10, 320, 221, 33));
        label_score_lite->setFont(font);
        label_score_lite->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));
        label_class = new QLabel(centralwidget);
        label_class->setObjectName("label_class");
        label_class->setGeometry(QRect(441, 241, 81, 36));
        label_class->setFont(font);
        label_class->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));
        label_class_value = new QLabel(centralwidget);
        label_class_value->setObjectName("label_class_value");
        label_class_value->setGeometry(QRect(529, 241, 241, 36));
        label_class_value->setFont(font);
        label_class_value->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));
        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName("pushButton_clear");
        pushButton_clear->setGeometry(QRect(241, 421, 132, 45));
        pushButton_clear->setFont(font);
        pushButton_clear->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));
        pushButton_creat = new QPushButton(centralwidget);
        pushButton_creat->setObjectName("pushButton_creat");
        pushButton_creat->setGeometry(QRect(121, 421, 114, 45));
        pushButton_creat->setFont(font);
        pushButton_creat->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));
        image = new QLabel(centralwidget);
        image->setObjectName("image");
        image->setGeometry(QRect(790, 150, 240, 320));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(441, 301, 191, 164));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_hp = new QLabel(layoutWidget);
        label_hp->setObjectName("label_hp");
        label_hp->setFont(font);
        label_hp->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_hp);

        label_hp_value = new QLabel(layoutWidget);
        label_hp_value->setObjectName("label_hp_value");
        label_hp_value->setFont(font);
        label_hp_value->setStyleSheet(QString::fromUtf8("border-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(255, 255, 255, 255), stop:0.373979 rgba(255, 255, 255, 255), stop:0.373991 rgba(33, 30, 255, 255), stop:0.624018 rgba(33, 30, 255, 255), stop:0.624043 rgba(255, 0, 0, 255), stop:1 rgba(255, 0, 0, 255));\n"
"font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_hp_value);

        label_mp = new QLabel(layoutWidget);
        label_mp->setObjectName("label_mp");
        label_mp->setFont(font);
        label_mp->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_mp);

        label_mp_value = new QLabel(layoutWidget);
        label_mp_value->setObjectName("label_mp_value");
        label_mp_value->setFont(font);
        label_mp_value->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_mp_value);

        label_atk = new QLabel(layoutWidget);
        label_atk->setObjectName("label_atk");
        label_atk->setFont(font);
        label_atk->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_atk);

        label_atk_value = new QLabel(layoutWidget);
        label_atk_value->setObjectName("label_atk_value");
        label_atk_value->setFont(font);
        label_atk_value->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_atk_value);

        label_def = new QLabel(layoutWidget);
        label_def->setObjectName("label_def");
        label_def->setFont(font);
        label_def->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_def);

        label_def_value = new QLabel(layoutWidget);
        label_def_value->setObjectName("label_def_value");
        label_def_value->setFont(font);
        label_def_value->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout->setWidget(3, QFormLayout::FieldRole, label_def_value);

        label_hello = new QLabel(centralwidget);
        label_hello->setObjectName("label_hello");
        label_hello->setGeometry(QRect(440, 61, 591, 36));
        label_hello->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 370, 372, 44));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_sex = new QLabel(layoutWidget1);
        label_sex->setObjectName("label_sex");
        label_sex->setFont(font);
        label_sex->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        horizontalLayout_2->addWidget(label_sex);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        radioButton_sex_m = new QRadioButton(layoutWidget1);
        radioButton_sex_m->setObjectName("radioButton_sex_m");
        radioButton_sex_m->setFont(font);
        radioButton_sex_m->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        horizontalLayout->addWidget(radioButton_sex_m);

        radioButton_sex_f = new QRadioButton(layoutWidget1);
        radioButton_sex_f->setObjectName("radioButton_sex_f");
        radioButton_sex_f->setFont(font);
        radioButton_sex_f->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        horizontalLayout->addWidget(radioButton_sex_f);


        horizontalLayout_2->addLayout(horizontalLayout);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 140, 171, 38));
        formLayout_2 = new QFormLayout(layoutWidget2);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_str = new QLabel(layoutWidget2);
        label_str->setObjectName("label_str");
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_str->setPalette(palette);
        label_str->setFont(font);
        label_str->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_str);

        label_stroch = new QLabel(layoutWidget2);
        label_stroch->setObjectName("label_stroch");
        label_stroch->setFont(font);
        label_stroch->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_stroch);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(10, 185, 201, 38));
        formLayout_3 = new QFormLayout(layoutWidget3);
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_dex = new QLabel(layoutWidget3);
        label_dex->setObjectName("label_dex");
        label_dex->setFont(font);
        label_dex->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_dex);

        label_dexoch = new QLabel(layoutWidget3);
        label_dexoch->setObjectName("label_dexoch");
        label_dexoch->setFont(font);
        label_dexoch->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, label_dexoch);

        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(10, 230, 201, 38));
        formLayout_4 = new QFormLayout(layoutWidget4);
        formLayout_4->setObjectName("formLayout_4");
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_int = new QLabel(layoutWidget4);
        label_int->setObjectName("label_int");
        label_int->setFont(font);
        label_int->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_int);

        label_intoch = new QLabel(layoutWidget4);
        label_intoch->setObjectName("label_intoch");
        label_intoch->setFont(font);
        label_intoch->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, label_intoch);

        layoutWidget5 = new QWidget(centralwidget);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(10, 275, 171, 38));
        formLayout_5 = new QFormLayout(layoutWidget5);
        formLayout_5->setObjectName("formLayout_5");
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        label_luck = new QLabel(layoutWidget5);
        label_luck->setObjectName("label_luck");
        label_luck->setFont(font);
        label_luck->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_luck);

        label_luckoch = new QLabel(layoutWidget5);
        label_luckoch->setObjectName("label_luckoch");
        label_luckoch->setFont(font);
        label_luckoch->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, label_luckoch);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1074, 26));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(whatsthis)
        MainWindow->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_name->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217:", nullptr));
        lineEdit_score_lite->setText(QString());
        label_score_lite->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\272\320\276\320\262 \320\276\321\201\321\202\320\260\320\273\320\276\321\201\321\214:", nullptr));
        label_class->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\320\260\321\201\321\201:", nullptr));
        label_class_value->setText(QString());
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        pushButton_creat->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        image->setText(QString());
        label_hp->setText(QCoreApplication::translate("MainWindow", "\320\227\320\264\320\276\321\200\320\276\320\262\321\214\320\265:", nullptr));
        label_hp_value->setText(QString());
        label_mp->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\275\320\260:", nullptr));
        label_mp_value->setText(QString());
        label_atk->setText(QCoreApplication::translate("MainWindow", "\320\220\321\202\320\260\320\272\320\260:", nullptr));
        label_atk_value->setText(QString());
        label_def->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\211\320\270\321\202\320\260:", nullptr));
        label_def_value->setText(QString());
        label_hello->setText(QString());
        label_sex->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273:", nullptr));
        radioButton_sex_m->setText(QCoreApplication::translate("MainWindow", "\320\234\321\203\320\266\321\201\320\272\320\276\320\271", nullptr));
        radioButton_sex_f->setText(QCoreApplication::translate("MainWindow", "\320\226\320\265\320\275\321\201\320\272\320\270\320\271", nullptr));
        label_str->setText(QCoreApplication::translate("MainWindow", "\320\241\320\270\320\273\320\260:", nullptr));
        label_stroch->setText(QString());
        label_dex->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\262\320\272\320\276\321\201\321\202\321\214:", nullptr));
        label_dexoch->setText(QString());
        label_int->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\320\273\320\273\320\265\320\272\321\202:", nullptr));
        label_intoch->setText(QString());
        label_luck->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\321\207\320\260:", nullptr));
        label_luckoch->setText(QString());
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
