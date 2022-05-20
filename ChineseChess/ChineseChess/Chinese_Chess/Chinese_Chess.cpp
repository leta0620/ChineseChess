#include "Chinese_Chess.h"
#include "Pos.h"

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
    bkgnd.load(":/image/Desert.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, bkgnd);
    tempWidget = ui.stackedWidget->widget(0);
    tempWidget->setPalette(palette);

    //安裝過濾器
    ui.page_1->installEventFilter(this);

    //連接按鈕與事件
    connect(ui.pushButton_Start, SIGNAL(clicked()), this, SLOT(on_pushButton_Start_onclicked()));
    connect(ui.pushButton_Back, SIGNAL(clicked()), this, SLOT(on_pushButton_Back_onclicked()));
    connect(ui.pushButton_Exit, SIGNAL(clicked()), this, SLOT(on_pushButton_Exit_onclicked()));
    connect(ui.pushButton_Print, SIGNAL(clicked()), this, SLOT(on_pushButton_Print_onclicked()));

    // 設定遊戲所需變數
    this->gameRound = true;
}

//按鈕切換頁面
void Chinese_Chess::on_pushButton_Start_onclicked()
{
    gameRun.ResetGame();

    ui.stackedWidget->setCurrentIndex(1);
}

//按鈕切換頁面
void Chinese_Chess::on_pushButton_Back_onclicked()
{
    // 強制結束這場遊戲，close Log檔
    gameRun.GameOver();
    ui.stackedWidget->setCurrentIndex(0);
}

//按鈕離開
void Chinese_Chess::on_pushButton_Exit_onclicked()
{
    this->close();
}

//按鈕印出
void Chinese_Chess::on_pushButton_Print_onclicked()
{
    //Board test;
    //ui.page_1->update();
    gameRun.viewer.paintout();
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
        temp += QString::number(x) + " " + QString::number(y);
        ui.textBrowser->setText(temp);

        Pos clickPos(x, y);
        for (int check = 0; check < gameRun.GetLegalPos().size(); check++)
        {
            if (gameRun.GetLegalPos()[check] == clickPos)
            {
                GameProcess(clickPos);
                break;
            }
        }

        return true;
    }
    //繪圖事件
    else if(eve->type()== QEvent::Paint)
    {
        prints();
        ui.textBrowser->setText(ui.textBrowser->toPlainText() + "a");
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
        }
    }
}

//遊戲進程
void Chinese_Chess::GameProcess(Pos pos)
{
    if (!gameRun.GetGameStart())
    {
        gameRun.ResetGame();
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
        if (win == 1)
        {
            // 跳遊戲結束警示框，紅方勝利，並讓玩家選擇返回至主畫面 or 重新開始一局
            ui.textBrowser->setText("Red win");

            gameRun.GameOver();
            return;
        }
        else if (win == 2)
        {
            // 跳遊戲結束警示框，黑方勝利，並讓玩家選擇返回至主畫面 or 重新開始一局
            ui.textBrowser->setText("Black win");

            gameRun.GameOver();
            return;
        }

        // 判斷將軍
        int willWin = gameRun.WillWin();
        if (willWin == 1)
        {
            // 跳紅方將軍警示框
            ui.textBrowser->setText("Red will win");

        }
        else if (willWin == 2)
        {
            // 跳黑方將軍警示框
            ui.textBrowser->setText("Black will win");

        }
    }
}