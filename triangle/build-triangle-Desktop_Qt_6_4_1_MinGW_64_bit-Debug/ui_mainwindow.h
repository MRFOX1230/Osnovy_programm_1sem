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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_4;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_stor1;
    QLabel *label_stor2;
    QLabel *label_angle;
    QLineEdit *lineEdit_angle;
    QLineEdit *lineEdit_stor1;
    QLineEdit *lineEdit_stor2;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QLabel *label_result;
    QLabel *label_s;
    QLineEdit *lineEdit_s;
    QLabel *label_p;
    QLineEdit *lineEdit_p;
    QWidget *widget2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_clear;
    QMenuBar *menubar;
    QMenu *menuP_S_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(859, 569);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(494, 425, 16, 28));
        QFont font;
        font.setPointSize(16);
        label_4->setFont(font);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 150, 521, 161));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_stor1 = new QLabel(widget);
        label_stor1->setObjectName("label_stor1");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Variable Small Semibol")});
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        label_stor1->setFont(font1);
        label_stor1->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        gridLayout->addWidget(label_stor1, 0, 0, 1, 1);

        label_stor2 = new QLabel(widget);
        label_stor2->setObjectName("label_stor2");
        label_stor2->setFont(font1);
        label_stor2->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        gridLayout->addWidget(label_stor2, 1, 0, 1, 1);

        label_angle = new QLabel(widget);
        label_angle->setObjectName("label_angle");
        label_angle->setFont(font1);
        label_angle->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        gridLayout->addWidget(label_angle, 2, 0, 1, 2);

        lineEdit_angle = new QLineEdit(widget);
        lineEdit_angle->setObjectName("lineEdit_angle");
        lineEdit_angle->setFont(font1);
        lineEdit_angle->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        gridLayout->addWidget(lineEdit_angle, 2, 2, 1, 1);

        lineEdit_stor1 = new QLineEdit(widget);
        lineEdit_stor1->setObjectName("lineEdit_stor1");
        lineEdit_stor1->setFont(font1);
        lineEdit_stor1->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        gridLayout->addWidget(lineEdit_stor1, 0, 2, 1, 1);

        lineEdit_stor2 = new QLineEdit(widget);
        lineEdit_stor2->setObjectName("lineEdit_stor2");
        lineEdit_stor2->setFont(font1);
        lineEdit_stor2->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        gridLayout->addWidget(lineEdit_stor2, 1, 2, 1, 1);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(560, 120, 281, 191));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_result = new QLabel(widget1);
        label_result->setObjectName("label_result");
        label_result->setFont(font1);
        label_result->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        gridLayout_2->addWidget(label_result, 0, 0, 1, 1);

        label_s = new QLabel(widget1);
        label_s->setObjectName("label_s");
        label_s->setFont(font1);
        label_s->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        gridLayout_2->addWidget(label_s, 1, 0, 1, 1);

        lineEdit_s = new QLineEdit(widget1);
        lineEdit_s->setObjectName("lineEdit_s");
        lineEdit_s->setFont(font1);
        lineEdit_s->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        gridLayout_2->addWidget(lineEdit_s, 1, 1, 1, 1);

        label_p = new QLabel(widget1);
        label_p->setObjectName("label_p");
        label_p->setFont(font1);
        label_p->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        gridLayout_2->addWidget(label_p, 2, 0, 1, 1);

        lineEdit_p = new QLineEdit(widget1);
        lineEdit_p->setObjectName("lineEdit_p");
        lineEdit_p->setFont(font1);
        lineEdit_p->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        gridLayout_2->addWidget(lineEdit_p, 2, 1, 1, 1);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(230, 330, 298, 47));
        gridLayout_3 = new QGridLayout(widget2);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_ok = new QPushButton(widget2);
        pushButton_ok->setObjectName("pushButton_ok");
        pushButton_ok->setFont(font1);
        pushButton_ok->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        gridLayout_3->addWidget(pushButton_ok, 0, 0, 1, 1);

        pushButton_clear = new QPushButton(widget2);
        pushButton_clear->setObjectName("pushButton_clear");
        pushButton_clear->setFont(font1);
        pushButton_clear->setStyleSheet(QString::fromUtf8("font: 63 16pt \"Segoe UI Variable Small Semibol\";"));

        gridLayout_3->addWidget(pushButton_clear, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 859, 26));
        menuP_S_4 = new QMenu(menubar);
        menuP_S_4->setObjectName("menuP_S_4");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuP_S_4->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_4->setText(QString());
        label_stor1->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\276\321\200\320\276\320\275\320\260 1:", nullptr));
        label_stor2->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\276\321\200\320\276\320\275\320\260 2:", nullptr));
        label_angle->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\274/\321\203 \321\201\321\202\320\276\321\200\320\276\320\275\320\260\320\274\320\270 1 \320\270 2:", nullptr));
        label_result->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", nullptr));
        label_s->setText(QCoreApplication::translate("MainWindow", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214:", nullptr));
        label_p->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\274\320\265\321\202\321\200:", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        menuP_S_4->setTitle(QCoreApplication::translate("MainWindow", "S \320\270 P \321\202\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\260 (\320\222\320\260\321\200\320\270\320\260\320\275\321\202 4)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
