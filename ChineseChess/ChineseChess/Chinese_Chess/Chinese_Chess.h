#pragma once

#include <QtWidgets/QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include "Board.h"
#include "GameManager.h"
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
    void on_pushButton_Print_onclicked();

private:
    Ui::Chinese_ChessClass ui;
    bool eventFilter(QObject* obj, QEvent* eve);
    void prints();
    void GameProcess(Pos);

    // 遊戲進行所需變數
    bool gameRound;  // 遊戲進行步驟，gameRound = true為點擊想移動的旗子，gameRound = false為實際移動旗子。
    GameManager gameRun;    // 遊戲執行動作
};
