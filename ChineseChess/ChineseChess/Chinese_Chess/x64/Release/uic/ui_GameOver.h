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
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 177);
        label_1 = new QLabel(Dialog);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(100, 80, 181, 21));
        QFont font;
        font.setPointSize(15);
        label_1->setFont(font);
        label_1->setAlignment(Qt::AlignCenter);
        label_0 = new QLabel(Dialog);
        label_0->setObjectName(QString::fromUtf8("label_0"));
        label_0->setGeometry(QRect(80, 20, 231, 51));
        QFont font1;
        font1.setPointSize(38);
        label_0->setFont(font1);
        label_0->setAlignment(Qt::AlignCenter);
        cancelButton = new QPushButton(Dialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(200, 112, 171, 61));
        QFont font2;
        font2.setPointSize(30);
        cancelButton->setFont(font2);
        okButton = new QPushButton(Dialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(20, 112, 171, 61));
        okButton->setFont(font2);

        retranslateUi(Dialog);
        QObject::connect(okButton, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_1->setText(QCoreApplication::translate("Dialog", "\346\230\257\345\220\246\350\246\201\345\206\215\344\276\206\343\204\247\345\261\200?", nullptr));
        label_0->setText(QCoreApplication::translate("Dialog", "\347\264\205\346\226\271\347\215\262\345\213\235!", nullptr));
        cancelButton->setText(QCoreApplication::translate("Dialog", "\345\220\246", nullptr));
        okButton->setText(QCoreApplication::translate("Dialog", "\346\230\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
