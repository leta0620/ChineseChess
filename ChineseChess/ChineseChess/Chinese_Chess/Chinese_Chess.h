#pragma once

#include <QtWidgets/QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
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
    void on_pushButton_Load_onclicked();
    //void on_pushButton_Other_onclicked();
    void on_pushButton_Exit_onclicked();
    void on_pushButton_Surrender_onclicked();
    void receiveSel(bool sel);
    // �������^�C��
    void CallGameOver();
    // �}�l�C��
    void CallGameStart();
    // �}�Ҹ�Ƨ��A���Log�ɸ��|
    void FindLogPath();

private:
    Ui::Chinese_ChessClass ui;
    bool eventFilter(QObject* obj, QEvent* eve);
    void prints();
    void GameProcess(Pos);
    GameOver gm;

    // �C���i��һ��ܼ�
    bool gameRound;  // �C���i��B�J�AgameRound = true���I���Q���ʪ��X�l�AgameRound = false����ڲ��ʺX�l�C
    GameManager gameRun;    // �C������ʧ@
    std::string logPath;    // Log�ɸ��|
};
