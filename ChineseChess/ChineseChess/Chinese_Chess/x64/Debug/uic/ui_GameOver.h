/********************************************************************************
** Form generated from reading UI file 'GameOver.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label_1;
    QLabel *label_0;
    QPushButton *pushButton_No;
    QPushButton *pushButton_Yes;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 200);
        label_1 = new QLabel(Dialog);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(110, 80, 181, 21));
        QFont font;
        font.setPointSize(15);
        label_1->setFont(font);
        label_1->setAlignment(Qt::AlignCenter);
        label_0 = new QLabel(Dialog);
        label_0->setObjectName(QString::fromUtf8("label_0"));
        label_0->setGeometry(QRect(85, 20, 231, 51));
        QFont font1;
        font1.setPointSize(38);
        label_0->setFont(font1);
        label_0->setAlignment(Qt::AlignCenter);
        pushButton_No = new QPushButton(Dialog);
        pushButton_No->setObjectName(QString::fromUtf8("pushButton_No"));
        pushButton_No->setGeometry(QRect(200, 120, 171, 61));
        QFont font2;
        font2.setPointSize(30);
        pushButton_No->setFont(font2);
        pushButton_Yes = new QPushButton(Dialog);
        pushButton_Yes->setObjectName(QString::fromUtf8("pushButton_Yes"));
        pushButton_Yes->setGeometry(QRect(20, 120, 171, 61));
        pushButton_Yes->setFont(font2);

        retranslateUi(Dialog);
        QObject::connect(pushButton_Yes, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(pushButton_No, SIGNAL(clicked()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "\347\265\220\346\236\234", nullptr));
        label_1->setText(QCoreApplication::translate("Dialog", "\346\230\257\345\220\246\350\246\201\345\206\215\344\276\206\344\270\200\345\261\200?", nullptr));
        label_0->setText(QCoreApplication::translate("Dialog", "\347\264\205\346\226\271\347\215\262\345\213\235!", nullptr));
        pushButton_No->setText(QCoreApplication::translate("Dialog", "\345\220\246", nullptr));
        pushButton_Yes->setText(QCoreApplication::translate("Dialog", "\346\230\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
