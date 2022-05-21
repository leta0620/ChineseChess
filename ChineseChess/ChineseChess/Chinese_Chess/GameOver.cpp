#include "GameOver.h"

GameOver::GameOver(QDialog* parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    
    connect(ui.pushButton_Yes, SIGNAL(clicked()), this, SLOT(on_pushButton_Yes_onclicked()));
    connect(ui.pushButton_No, SIGNAL(clicked()), this, SLOT(on_pushButton_No_onclicked()));
}

void GameOver::on_pushButton_Yes_onclicked()
{
    emit sendSel(true);
}

void GameOver::on_pushButton_No_onclicked()
{
    emit sendSel(false);
}

void GameOver::SendResult(bool res)
{
    if (res)
        ui.label_0->setText(QString::fromLocal8Bit("紅方獲勝!"));
    else
        ui.label_0->setText(QString::fromLocal8Bit("黑方獲勝!"));
}