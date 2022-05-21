#include "Chinese_Chess.h"
#include "QFileDialog"
#include "Pos.h"

//遊戲結束
void Chinese_Chess::CallGameOver()
{
    gameRun.GameOver();
    gameRun.boardGM.AllSet();
    gameRun.viewer.paintout();
    timer.stop();
}

//遊戲開始
void Chinese_Chess::CallGameStart()
{
    gameRun.ResetGame();
    gameRound = true;

    if (gameRun.GetGamePlayer())
        ui.label_Turn->setText(QString::fromLocal8Bit("紅方回合"));
    else
        ui.label_Turn->setText(QString::fromLocal8Bit("黑方回合"));

    roundSec = 30;
    gameSec = 0;
    this->timeUpdate();
    timer.start(1000);
}

Chinese_Chess::Chinese_Chess(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    gameRun.viewer.SetUi(&ui);

    //設定背景(棋盤)
    QPixmap bkgnd(":/image/Chess_Board.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    QWidget* tempWidget = ui.stackedWidget->widget(1);
    tempWidget->setPalette(palette);

    //設定背景(主畫面)
    bkgnd.load(":/image/Elephant.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, bkgnd);
    tempWidget = ui.stackedWidget->widget(0);
    tempWidget->setPalette(palette);

    //安裝過濾器
    ui.page_1->installEventFilter(this);

    //連接按鈕與事件
    connect(ui.pushButton_Start, SIGNAL(clicked()), this, SLOT(on_pushButton_Start_onclicked()));
    connect(ui.pushButton_Load, SIGNAL(clicked()), this, SLOT(on_pushButton_Load_onclicked()));
    connect(ui.pushButton_Back, SIGNAL(clicked()), this, SLOT(on_pushButton_Back_onclicked()));
    connect(ui.pushButton_Exit, SIGNAL(clicked()), this, SLOT(on_pushButton_Exit_onclicked()));
    connect(ui.pushButton_Surrender, SIGNAL(clicked()), this, SLOT(on_pushButton_Surrender_onclicked()));

    // 設定遊戲所需變數
    this->gameRound = true;

    gm.setFixedSize(QSize(400, 200));
    connect(&gm, SIGNAL(sendSel(bool)), this, SLOT(receiveSel(bool)));

    connect(&timer, SIGNAL(timeout()), this, SLOT(timeGo()));
}

//按鈕切換頁面
void Chinese_Chess::on_pushButton_Start_onclicked()
{
    this->CallGameStart();

    ui.stackedWidget->setCurrentIndex(1);
}

//按鈕切換頁面
void Chinese_Chess::on_pushButton_Back_onclicked()
{
    // 強制結束這場遊戲
    this->CallGameOver();
    ui.stackedWidget->setCurrentIndex(0);
}

//按鈕離開
void Chinese_Chess::on_pushButton_Exit_onclicked()
{
    this->close();
}

//按鈕投降
void Chinese_Chess::on_pushButton_Surrender_onclicked()
{
    Win(!gameRun.GetGamePlayer());
}

// 讀檔進行遊戲
void Chinese_Chess::on_pushButton_Load_onclicked()
{
    // 查找log檔路徑
    this->FindLogPath();

    // 路徑不為空
    if (!this->logPath.empty())
    {
        this->CallGameStart();

        std::ifstream logFile(this->logPath);
        std::string logInput;

        char player = '0';    // 紅為true，黑為false
        std::string chess;
        Pos from, to;

        // 將盤面執行到log檔的最新狀況
        try
        {
            int i = 0;
            while (!logFile.eof())
            {
                logFile.ignore(8);
                if (logFile.eof())
                {
                    logFile.close();
                    break;
                }
                logFile >> player;
                if (player != '1' && player != '2')
                {
                    throw "player error";
                }
                logFile.ignore(10);
                logFile >> chess;

                char posTmp;
                logFile >> posTmp >> posTmp;
                from.x = posTmp - '0';
                logFile.ignore(2);
                logFile >> posTmp;
                from.y = posTmp - '0';

                if (!(from.x >= 0 && from.x <= 9) || !(from.y >= 0 && from.y <= 10))
                {
                    throw "position error";
                }

                logFile.ignore(6);
                logFile >> posTmp;
                to.x = posTmp - '0';
                logFile.ignore(2);
                logFile >> posTmp;
                to.y = posTmp - '0';
                logFile.ignore(1);

                if (!(to.x >= 0 && to.x <= 9) || !(to.y >= 0 && to.y <= 10))
                {
                    throw "position error";
                }

                gameRun.boardGM.MovePos(from, to);
                i++;
            }

            // 如果已有一方勝利，要跳出勝利視窗不可繼續遊戲
            int win = gameRun.Win();
            if (win == 1 || win == 2)
            {
                // 跳遊戲結束警示框，某方勝利，並讓玩家選擇返回至主畫面 or 重新開始一局
                if (win == 1)
                {
                    ui.stackedWidget->setCurrentIndex(1);
                    this->Win(true);
                }
                else if (win == 2)
                {
                    ui.stackedWidget->setCurrentIndex(1);
                    this->Win(false);
                }
                return;
            }

            // 設定繼續遊戲需要的參數，並跳轉到遊戲畫面
            this->gameRun.SetFileName(logPath);
            gameRound = true;

            if (player == '2')
                ui.label_Turn->setText(QString::fromLocal8Bit("紅方回合"));
            else if (player == '1')
                ui.label_Turn->setText(QString::fromLocal8Bit("黑方回合"));

            // 設定目前進行到哪位玩家
            if (player == '1')
            {
                this->gameRun.SetGamePlayer(false);
                this->gameRun.SetColorLegalPos(false);
            }
            else if (player == '2')
            {
                this->gameRun.SetGamePlayer(true);
                this->gameRun.SetColorLegalPos(true);
            }

            ui.stackedWidget->setCurrentIndex(1);
        }
        catch (const std::string& errorMessage)
        {
            if (logFile.is_open())
            {
                logFile.close();
            }
            this->CallGameOver();
            return;
        }
    }
}

void Chinese_Chess::receiveSel(bool sel)
{
    // 如要重新一局，記得寫
    this->CallGameStart();
    if (sel)
        this->on_pushButton_Start_onclicked();
    else
        this->on_pushButton_Back_onclicked();
    gm.hide();
}

//每秒更新
void Chinese_Chess::timeGo()
{
    roundSec--;
    gameSec++;
    if(roundSec<0)
        Win(!gameRun.GetGamePlayer());
    else
        this->timeUpdate();
}

//事件過濾器
bool Chinese_Chess::eventFilter(QObject* obj, QEvent* eve)
{
    //滑鼠點擊
    if (eve->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(eve);
        QString temp = QString::number(mouseEvent->x()) + " " + QString::number(mouseEvent->y()) + " ";
        int x = (mouseEvent->x() - 10) / 100;
        int y = (mouseEvent->y() - 8) / 80;

        Pos clickPos(x, y);
        for (int check = 0; check < gameRun.GetLegalPos().size(); check++)
        {
            // 取消想移動的棋子
            if ((gameRun.GetNowMoveChess() == clickPos) && (gameRound == false))
            {
                // 重新處理合法位置
                gameRun.SetColorLegalPos(gameRun.GetGamePlayer());

                // 重新繪製盤面
                gameRun.viewer.paintout();

                // 更改遊戲進程
                this->gameRound = !this->gameRound;
                
                break;
            }

            // 如果點擊到合法位置，進行遊戲迴圈
            if (gameRun.GetLegalPos()[check] == clickPos)
            {
                GameProcess(clickPos);
                break;
            }
        }
        if (gameRun.GetGamePlayer())
            ui.label_Turn->setText(QString::fromLocal8Bit("紅方回合"));
        else
            ui.label_Turn->setText(QString::fromLocal8Bit("黑方回合"));
        return true;
    }
    //繪圖事件
    else if(eve->type()== QEvent::Paint)
    {
        prints();
        return true;
    }
    else
    {
        return QWidget::eventFilter(obj, eve);
    }    
}

//繪畫function
void Chinese_Chess::prints()
{
    QPainter painter(ui.page_1);
    std::vector<Pos> legalPos;
    if (!gameRound)
        legalPos = gameRun.GetLegalPos();
    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            if (gameRun.boardGM.board[row][column] != NULL)
            {
                bool color=gameRun.boardGM.board[row][column]->GetColor();
                int chesstype = gameRun.boardGM.board[row][column]->GetName();
                QString toPrintImg = ":/chess/Chessimg/";
                if (color)
                {
                    toPrintImg += "red";
                }
                else
                {
                    toPrintImg += "black";
                }
                toPrintImg += QString::number(chesstype) + ".png";
                painter.drawImage(QRect(10 + column * 100, 8 + row * 80, 80, 64), QImage(toPrintImg)); 
            }
            if (!gameRound)
            {
                Pos tmp(column, row);
                for (int a = 0; a < legalPos.size();a++)
                {
                    if (legalPos[a] == tmp)
                    {
                        if(gameRun.boardGM.board[tmp.y][tmp.x] != NULL)
                            painter.drawImage(QRect(10 + column * 100, 8 + row * 80, 80, 64), QImage(":/image/Chessimg/toMoveRed.png"));
                        else
                            painter.drawImage(QRect(10 + column * 100, 8 + row * 80, 80, 64), QImage(":/image/Chessimg/toMove.png"));
                    }
                }
            }
        }
    }
}

//更新計時顯示
void Chinese_Chess::timeUpdate()
{
    int min = gameSec / 60;
    QString toDisplyGameTime;
    if (min < 10)
    {
        toDisplyGameTime = "0" + QString::number(min);
    }
    else
    {
        toDisplyGameTime = QString::number(min);
    }
    toDisplyGameTime += " : ";
    if (gameSec % 60 < 10)
    {
        toDisplyGameTime += "0" + QString::number(gameSec % 60);
    }
    else
    {
        toDisplyGameTime += QString::number(gameSec % 60);
    }

    ui.label_GameTime->setText(toDisplyGameTime);
    ui.label_RoundTime->setText(QString::number(roundSec));
}

//顯示勝負結果
void Chinese_Chess::Win(bool whoWin)
{
    gm.SendResult(whoWin);
    gm.show();
    this->CallGameOver();
}

//遊戲進程
void Chinese_Chess::GameProcess(Pos pos)
{
    if (!gameRun.GetGameStart())
    {
        this->CallGameStart();
    }

    if (this->gameRound)
    {
        // 目前步驟為點擊欲移動的棋子
        if (gameRun.clickChess(pos))
        {
            return;
        }
                
        // 繪製盤面
        gameRun.viewer.paintout();

        // 更改遊戲進程
        this->gameRound = !this->gameRound;
    }
    else if (!this->gameRound)
    {
        // 目前步驟為移動棋子
        gameRun.moveChess(pos);        

        // 繪製盤面
        gameRun.viewer.paintout();

        // 更改遊戲進程
        this->gameRound = !this->gameRound;

        // 判斷勝負
        int win = gameRun.Win();
        if (win == 1 || win == 2)
        {
            // 跳遊戲結束警示框，某方勝利，並讓玩家選擇返回至主畫面 or 重新開始一局
            if (win == 1)
                this->Win(true);
            else if (win == 2)
                this->Win(false);
            return;
        }

        // 判斷將軍
        int willWin = gameRun.WillWin();
        if (willWin == 1)
        {
            // 跳紅方將軍警示框
            QMessageBox::warning(this, QString::fromLocal8Bit("將軍!"), QString::fromLocal8Bit("紅方將軍!"));
        }
        else if (willWin == 2)
        {
            // 跳黑方將軍警示框
            QMessageBox::warning(this, QString::fromLocal8Bit("將軍!"), QString::fromLocal8Bit("黑方將軍!"));
        }
        else if (willWin == 3)
        {
            if (this->gameRun.GetGamePlayer() == true)
            {
                // 跳紅方將軍警示框
                QMessageBox::warning(this, QString::fromLocal8Bit("將軍!"), QString::fromLocal8Bit("紅方將軍!"));              
            }
            else if (this->gameRun.GetGamePlayer() == false)
            {
                // 跳黑方將軍警示框
                QMessageBox::warning(this, QString::fromLocal8Bit("將軍!"), QString::fromLocal8Bit("黑方將軍!"));
            }
        }

        roundSec = 30;
        this->timeUpdate();
    }
}

// 開啟資料夾，選擇Log檔路徑
void Chinese_Chess::FindLogPath()
{
    QString filePath = QFileDialog::getOpenFileName(this, "a...", "*.txt");
    if (filePath.isEmpty())
    {
        return;
    }
    else
    {
        // 將路徑轉換成string
        QByteArray tempData = filePath.toLocal8Bit();
        logPath = std::string(tempData);
    }
}