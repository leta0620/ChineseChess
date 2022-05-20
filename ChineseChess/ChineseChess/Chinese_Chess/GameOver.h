#pragma once
#include "ui_GameOver.h"
#include <QtWidgets/QWidget>

class GameOver : public QDialog
{
    Q_OBJECT

public:
    GameOver(QDialog* parent = Q_NULLPTR);
    void SendResult(bool);
private slots:
    void on_pushButton_Yes_onclicked();
    void on_pushButton_No_onclicked();
private:
    Ui::Dialog ui;
signals:
    void sendSel(bool);
};