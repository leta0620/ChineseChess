/********************************************************************************
** Form generated from reading UI file 'GetLogPath.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETLOGPATH_H
#define UI_GETLOGPATH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QPushButton *selectFile_okButton;
    QPushButton *selectFile_cancelButton;
    QPushButton *selectFile_pushButton;
    QLabel *selectFile_label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(260, 180, 351, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        selectFile_okButton = new QPushButton(layoutWidget);
        selectFile_okButton->setObjectName(QString::fromUtf8("selectFile_okButton"));

        hboxLayout->addWidget(selectFile_okButton);

        selectFile_cancelButton = new QPushButton(layoutWidget);
        selectFile_cancelButton->setObjectName(QString::fromUtf8("selectFile_cancelButton"));

        hboxLayout->addWidget(selectFile_cancelButton);

        selectFile_pushButton = new QPushButton(Dialog);
        selectFile_pushButton->setObjectName(QString::fromUtf8("selectFile_pushButton"));
        selectFile_pushButton->setGeometry(QRect(70, 20, 191, 51));
        QFont font;
        font.setPointSize(20);
        selectFile_pushButton->setFont(font);
        selectFile_label = new QLabel(Dialog);
        selectFile_label->setObjectName(QString::fromUtf8("selectFile_label"));
        selectFile_label->setGeometry(QRect(30, 100, 821, 61));
        QFont font1;
        font1.setPointSize(16);
        selectFile_label->setFont(font1);

        retranslateUi(Dialog);
        QObject::connect(selectFile_okButton, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(selectFile_cancelButton, SIGNAL(clicked()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        selectFile_okButton->setText(QCoreApplication::translate("Dialog", "OK", nullptr));
        selectFile_cancelButton->setText(QCoreApplication::translate("Dialog", "Cancel", nullptr));
        selectFile_pushButton->setText(QCoreApplication::translate("Dialog", "\351\201\270\346\223\207Log\346\252\224\346\241\210", nullptr));
        selectFile_label->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETLOGPATH_H
