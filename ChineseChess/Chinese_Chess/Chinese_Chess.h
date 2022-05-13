#pragma once

#include <QtWidgets/QWidget>
#include <QEvent>
#include <QMouseEvent>
#include "ui_Chinese_Chess.h"

class Chinese_Chess : public QWidget
{
    Q_OBJECT

public:
    Chinese_Chess(QWidget *parent = Q_NULLPTR);
private slots :
    void on_pushButton_Start_onclicked();
    void on_pushButton_Back_onclicked();
    //void on_pushButton_Load_onclicked();
    //void on_pushButton_Other_onclicked();
    void on_pushButton_Exit_onclicked();
private:
    Ui::Chinese_ChessClass ui;
    bool eventFilter(QObject* obj, QEvent* eve);
};
