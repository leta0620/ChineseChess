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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chinese_ChessClass
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_0;
    QPushButton *pushButton_Start;
    QPushButton *pushButton_Load;
    QPushButton *pushButton_Exit;
    QLabel *label;
    QLabel *label_2;
    QWidget *page_1;
    QPushButton *pushButton_Back;
    QPushButton *pushButton_Surrender;
    QLabel *label_Turn;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_GameTime;
    QLabel *label_RoundTime;

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
        pushButton_Load->setGeometry(QRect(500, 460, 201, 51));
        pushButton_Load->setFont(font);
        pushButton_Exit = new QPushButton(page_0);
        pushButton_Exit->setObjectName(QString::fromUtf8("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(500, 650, 201, 51));
        pushButton_Exit->setFont(font);
        label = new QLabel(page_0);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 50, 381, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\250\231\346\245\267\351\253\224"));
        font1.setPointSize(60);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(page_0);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(500, 140, 211, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Comic Sans MS"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setWeight(50);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_0);
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        page_1->setAutoFillBackground(true);
        pushButton_Back = new QPushButton(page_1);
        pushButton_Back->setObjectName(QString::fromUtf8("pushButton_Back"));
        pushButton_Back->setGeometry(QRect(1000, 720, 131, 51));
        QFont font3;
        font3.setPointSize(16);
        pushButton_Back->setFont(font3);
        pushButton_Surrender = new QPushButton(page_1);
        pushButton_Surrender->setObjectName(QString::fromUtf8("pushButton_Surrender"));
        pushButton_Surrender->setGeometry(QRect(1000, 640, 131, 51));
        QFont font4;
        font4.setPointSize(15);
        pushButton_Surrender->setFont(font4);
        label_Turn = new QLabel(page_1);
        label_Turn->setObjectName(QString::fromUtf8("label_Turn"));
        label_Turn->setGeometry(QRect(960, 120, 211, 51));
        QFont font5;
        font5.setPointSize(24);
        label_Turn->setFont(font5);
        label_Turn->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(page_1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(990, 300, 161, 21));
        label_4->setFont(font4);
        label_4->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(page_1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(990, 200, 161, 21));
        label_3->setFont(font4);
        label_3->setAlignment(Qt::AlignCenter);
        label_GameTime = new QLabel(page_1);
        label_GameTime->setObjectName(QString::fromUtf8("label_GameTime"));
        label_GameTime->setGeometry(QRect(990, 235, 151, 51));
        QFont font6;
        font6.setPointSize(22);
        label_GameTime->setFont(font6);
        label_GameTime->setAlignment(Qt::AlignCenter);
        label_RoundTime = new QLabel(page_1);
        label_RoundTime->setObjectName(QString::fromUtf8("label_RoundTime"));
        label_RoundTime->setGeometry(QRect(990, 340, 151, 51));
        label_RoundTime->setFont(font6);
        label_RoundTime->setAlignment(Qt::AlignCenter);
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
        pushButton_Exit->setText(QCoreApplication::translate("Chinese_ChessClass", "\347\265\220\346\235\237", nullptr));
        label->setText(QCoreApplication::translate("Chinese_ChessClass", "\350\261\241\346\243\213", nullptr));
        label_2->setText(QCoreApplication::translate("Chinese_ChessClass", "Elephant Chess", nullptr));
        pushButton_Back->setText(QCoreApplication::translate("Chinese_ChessClass", "\345\204\262\345\255\230\344\270\246\350\277\224\345\233\236", nullptr));
        pushButton_Surrender->setText(QCoreApplication::translate("Chinese_ChessClass", "\346\212\225\351\231\215", nullptr));
        label_Turn->setText(QCoreApplication::translate("Chinese_ChessClass", "\347\264\205\346\226\271\345\233\236\345\220\210", nullptr));
        label_4->setText(QCoreApplication::translate("Chinese_ChessClass", "<html><head/><body><p>\345\211\251\351\244\230\346\231\202\351\226\223 : </p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Chinese_ChessClass", "<html><head/><body><p>\347\270\275\351\201\212\346\210\262\346\231\202\351\226\223 :</p></body></html>", nullptr));
        label_GameTime->setText(QCoreApplication::translate("Chinese_ChessClass", "Test", nullptr));
        label_RoundTime->setText(QCoreApplication::translate("Chinese_ChessClass", "Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chinese_ChessClass: public Ui_Chinese_ChessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHINESE_CHESS_H
