/********************************************************************************
** Form generated from reading UI file 'Chinese_Chess.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHINESE_CHESS_H
#define UI_CHINESE_CHESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chinese_ChessClass
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_0;
    QPushButton *pushButton_Start;
    QPushButton *pushButton_Load;
    QPushButton *pushButton_Other;
    QPushButton *pushButton_Exit;
    QLabel *label;
    QLabel *label_2;
    QWidget *page_1;
    QPushButton *pushButton_Back;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_Surrender;
    QLabel *label_3;

    void setupUi(QWidget *Chinese_ChessClass)
    {
        if (Chinese_ChessClass->objectName().isEmpty())
            Chinese_ChessClass->setObjectName(QString::fromUtf8("Chinese_ChessClass"));
        Chinese_ChessClass->resize(1200, 800);
        stackedWidget = new QStackedWidget(Chinese_ChessClass);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1200, 800));
        stackedWidget->setAutoFillBackground(true);
        page_0 = new QWidget();
        page_0->setObjectName(QString::fromUtf8("page_0"));
        page_0->setAutoFillBackground(true);
        pushButton_Start = new QPushButton(page_0);
        pushButton_Start->setObjectName(QString::fromUtf8("pushButton_Start"));
        pushButton_Start->setGeometry(QRect(500, 270, 201, 51));
        QFont font;
        font.setPointSize(19);
        pushButton_Start->setFont(font);
        pushButton_Load = new QPushButton(page_0);
        pushButton_Load->setObjectName(QString::fromUtf8("pushButton_Load"));
        pushButton_Load->setGeometry(QRect(500, 430, 201, 51));
        pushButton_Load->setFont(font);
        pushButton_Other = new QPushButton(page_0);
        pushButton_Other->setObjectName(QString::fromUtf8("pushButton_Other"));
        pushButton_Other->setGeometry(QRect(500, 570, 201, 51));
        pushButton_Other->setFont(font);
        pushButton_Exit = new QPushButton(page_0);
        pushButton_Exit->setObjectName(QString::fromUtf8("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(500, 710, 201, 51));
        pushButton_Exit->setFont(font);
        label = new QLabel(page_0);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 70, 381, 61));
        QFont font1;
        font1.setPointSize(35);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(page_0);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(520, 140, 151, 16));
        label_2->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_0);
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        page_1->setAutoFillBackground(true);
        pushButton_Back = new QPushButton(page_1);
        pushButton_Back->setObjectName(QString::fromUtf8("pushButton_Back"));
        pushButton_Back->setGeometry(QRect(1050, 720, 111, 51));
        QFont font2;
        font2.setPointSize(16);
        pushButton_Back->setFont(font2);
        textBrowser = new QTextBrowser(page_1);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(930, 140, 256, 41));
        QFont font3;
        font3.setPointSize(15);
        textBrowser->setFont(font3);
        pushButton_Surrender = new QPushButton(page_1);
        pushButton_Surrender->setObjectName(QString::fromUtf8("pushButton_Surrender"));
        pushButton_Surrender->setGeometry(QRect(1050, 640, 111, 51));
        pushButton_Surrender->setFont(font3);
        label_3 = new QLabel(page_1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(950, 30, 211, 51));
        QFont font4;
        font4.setPointSize(24);
        label_3->setFont(font4);
        label_3->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_1);

        retranslateUi(Chinese_ChessClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Chinese_ChessClass);
    } // setupUi

    void retranslateUi(QWidget *Chinese_ChessClass)
    {
        Chinese_ChessClass->setWindowTitle(QCoreApplication::translate("Chinese_ChessClass", "Chinese_Chess", nullptr));
        pushButton_Start->setText(QCoreApplication::translate("Chinese_ChessClass", "\351\226\213\345\247\213\351\201\212\346\210\262", nullptr));
        pushButton_Load->setText(QCoreApplication::translate("Chinese_ChessClass", "\347\271\274\347\272\214\351\201\212\346\210\262", nullptr));
        pushButton_Other->setText(QCoreApplication::translate("Chinese_ChessClass", "\345\205\266\345\256\203", nullptr));
        pushButton_Exit->setText(QCoreApplication::translate("Chinese_ChessClass", "\347\265\220\346\235\237", nullptr));
        label->setText(QCoreApplication::translate("Chinese_ChessClass", "\350\261\241\346\243\213", nullptr));
        label_2->setText(QCoreApplication::translate("Chinese_ChessClass", "Elephant Chess", nullptr));
        pushButton_Back->setText(QCoreApplication::translate("Chinese_ChessClass", "\345\204\262\345\255\230\344\270\246\350\277\224\345\233\236", nullptr));
        pushButton_Surrender->setText(QCoreApplication::translate("Chinese_ChessClass", "\346\212\225\351\231\215", nullptr));
        label_3->setText(QCoreApplication::translate("Chinese_ChessClass", "\347\264\205\346\226\271\345\233\236\345\220\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chinese_ChessClass: public Ui_Chinese_ChessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHINESE_CHESS_H
