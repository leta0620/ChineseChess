#pragma once

#include <QtWidgets/QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QMessageBox>
#include <QTimer>
#include "Board.h"
#include "GameManager.h"
#include "ui_Chinese_Chess.h"
#include "GameOver.h"

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
    void on_pushButton_Surrender_onclicked();
    void receiveSel(bool);
    void timeGo();
private:
    Ui::Chinese_ChessClass ui;
    bool eventFilter(QObject* obj, QEvent* eve);
    void prints();
    void GameProcess(Pos);    
    void CallGameOver();
    void CallGameStart();
    void Win(bool);
    void timeUpdate();
    GameOver gm;

    // �C���i��һ��ܼ�
    bool gameRound;  // �C���i��B�J�AgameRound = true���I���Q���ʪ��X�l�AgameRound = false����ڲ��ʺX�l�C
    GameManager gameRun;    // �C������ʧ@
    QTimer timer;
    int roundSec;
    int gameSec;
};
