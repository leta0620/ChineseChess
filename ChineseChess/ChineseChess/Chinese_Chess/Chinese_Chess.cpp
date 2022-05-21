#include "Chinese_Chess.h"
#include "QFileDialog"
#include "Pos.h"

//�C������
void Chinese_Chess::CallGameOver()
{
    gameRun.GameOver();
    gameRun.boardGM.AllSet();
    gameRun.viewer.paintout();
    timer.stop();
}

//�C���}�l
void Chinese_Chess::CallGameStart()
{
    gameRun.ResetGame();
    gameRound = true;

    if (gameRun.GetGamePlayer())
        ui.label_Turn->setText(QString::fromLocal8Bit("����^�X"));
    else
        ui.label_Turn->setText(QString::fromLocal8Bit("�¤�^�X"));

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

    //�]�w�I��(�ѽL)
    QPixmap bkgnd(":/image/Chess_Board.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    QWidget* tempWidget = ui.stackedWidget->widget(1);
    tempWidget->setPalette(palette);

    //�]�w�I��(�D�e��)
    bkgnd.load(":/image/Elephant.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, bkgnd);
    tempWidget = ui.stackedWidget->widget(0);
    tempWidget->setPalette(palette);

    //�w�˹L�o��
    ui.page_1->installEventFilter(this);

    //�s�����s�P�ƥ�
    connect(ui.pushButton_Start, SIGNAL(clicked()), this, SLOT(on_pushButton_Start_onclicked()));
    connect(ui.pushButton_Load, SIGNAL(clicked()), this, SLOT(on_pushButton_Load_onclicked()));
    connect(ui.pushButton_Back, SIGNAL(clicked()), this, SLOT(on_pushButton_Back_onclicked()));
    connect(ui.pushButton_Exit, SIGNAL(clicked()), this, SLOT(on_pushButton_Exit_onclicked()));
    connect(ui.pushButton_Surrender, SIGNAL(clicked()), this, SLOT(on_pushButton_Surrender_onclicked()));

    // �]�w�C���һ��ܼ�
    this->gameRound = true;

    gm.setFixedSize(QSize(400, 200));
    connect(&gm, SIGNAL(sendSel(bool)), this, SLOT(receiveSel(bool)));

    connect(&timer, SIGNAL(timeout()), this, SLOT(timeGo()));
}

//���s��������
void Chinese_Chess::on_pushButton_Start_onclicked()
{
    this->CallGameStart();

    ui.stackedWidget->setCurrentIndex(1);
}

//���s��������
void Chinese_Chess::on_pushButton_Back_onclicked()
{
    // �j����o���C��
    this->CallGameOver();
    ui.stackedWidget->setCurrentIndex(0);
}

//���s���}
void Chinese_Chess::on_pushButton_Exit_onclicked()
{
    this->close();
}

//���s�뭰
void Chinese_Chess::on_pushButton_Surrender_onclicked()
{
    Win(!gameRun.GetGamePlayer());
}

// Ū�ɶi��C��
void Chinese_Chess::on_pushButton_Load_onclicked()
{
    // �d��log�ɸ��|
    this->FindLogPath();

    // ���|������
    if (!this->logPath.empty())
    {
        this->CallGameStart();

        std::ifstream logFile(this->logPath);
        std::string logInput;

        char player = '0';    // ����true�A�¬�false
        std::string chess;
        Pos from, to;

        // �N�L�������log�ɪ��̷s���p
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

            // �p�G�w���@��ӧQ�A�n���X�ӧQ�������i�~��C��
            int win = gameRun.Win();
            if (win == 1 || win == 2)
            {
                // ���C������ĵ�ܮءA�Y��ӧQ�A�������a��ܪ�^�ܥD�e�� or ���s�}�l�@��
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

            // �]�w�~��C���ݭn���ѼơA�ø����C���e��
            this->gameRun.SetFileName(logPath);
            gameRound = true;

            if (player == '2')
                ui.label_Turn->setText(QString::fromLocal8Bit("����^�X"));
            else if (player == '1')
                ui.label_Turn->setText(QString::fromLocal8Bit("�¤�^�X"));

            // �]�w�ثe�i�����쪱�a
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
    // �p�n���s�@���A�O�o�g
    this->CallGameStart();
    if (sel)
        this->on_pushButton_Start_onclicked();
    else
        this->on_pushButton_Back_onclicked();
    gm.hide();
}

//�C���s
void Chinese_Chess::timeGo()
{
    roundSec--;
    gameSec++;
    if(roundSec<0)
        Win(!gameRun.GetGamePlayer());
    else
        this->timeUpdate();
}

//�ƥ�L�o��
bool Chinese_Chess::eventFilter(QObject* obj, QEvent* eve)
{
    //�ƹ��I��
    if (eve->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(eve);
        QString temp = QString::number(mouseEvent->x()) + " " + QString::number(mouseEvent->y()) + " ";
        int x = (mouseEvent->x() - 10) / 100;
        int y = (mouseEvent->y() - 8) / 80;

        Pos clickPos(x, y);
        for (int check = 0; check < gameRun.GetLegalPos().size(); check++)
        {
            // �����Q���ʪ��Ѥl
            if ((gameRun.GetNowMoveChess() == clickPos) && (gameRound == false))
            {
                // ���s�B�z�X�k��m
                gameRun.SetColorLegalPos(gameRun.GetGamePlayer());

                // ���sø�s�L��
                gameRun.viewer.paintout();

                // ���C���i�{
                this->gameRound = !this->gameRound;
                
                break;
            }

            // �p�G�I����X�k��m�A�i��C���j��
            if (gameRun.GetLegalPos()[check] == clickPos)
            {
                GameProcess(clickPos);
                break;
            }
        }
        if (gameRun.GetGamePlayer())
            ui.label_Turn->setText(QString::fromLocal8Bit("����^�X"));
        else
            ui.label_Turn->setText(QString::fromLocal8Bit("�¤�^�X"));
        return true;
    }
    //ø�Ϩƥ�
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

//ø�efunction
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

//��s�p�����
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

//��ܳӭt���G
void Chinese_Chess::Win(bool whoWin)
{
    gm.SendResult(whoWin);
    gm.show();
    this->CallGameOver();
}

//�C���i�{
void Chinese_Chess::GameProcess(Pos pos)
{
    if (!gameRun.GetGameStart())
    {
        this->CallGameStart();
    }

    if (this->gameRound)
    {
        // �ثe�B�J���I�������ʪ��Ѥl
        if (gameRun.clickChess(pos))
        {
            return;
        }
                
        // ø�s�L��
        gameRun.viewer.paintout();

        // ���C���i�{
        this->gameRound = !this->gameRound;
    }
    else if (!this->gameRound)
    {
        // �ثe�B�J�����ʴѤl
        gameRun.moveChess(pos);        

        // ø�s�L��
        gameRun.viewer.paintout();

        // ���C���i�{
        this->gameRound = !this->gameRound;

        // �P�_�ӭt
        int win = gameRun.Win();
        if (win == 1 || win == 2)
        {
            // ���C������ĵ�ܮءA�Y��ӧQ�A�������a��ܪ�^�ܥD�e�� or ���s�}�l�@��
            if (win == 1)
                this->Win(true);
            else if (win == 2)
                this->Win(false);
            return;
        }

        // �P�_�N�x
        int willWin = gameRun.WillWin();
        if (willWin == 1)
        {
            // ������N�xĵ�ܮ�
            QMessageBox::warning(this, QString::fromLocal8Bit("�N�x!"), QString::fromLocal8Bit("����N�x!"));
        }
        else if (willWin == 2)
        {
            // ���¤�N�xĵ�ܮ�
            QMessageBox::warning(this, QString::fromLocal8Bit("�N�x!"), QString::fromLocal8Bit("�¤�N�x!"));
        }
        else if (willWin == 3)
        {
            if (this->gameRun.GetGamePlayer() == true)
            {
                // ������N�xĵ�ܮ�
                QMessageBox::warning(this, QString::fromLocal8Bit("�N�x!"), QString::fromLocal8Bit("����N�x!"));              
            }
            else if (this->gameRun.GetGamePlayer() == false)
            {
                // ���¤�N�xĵ�ܮ�
                QMessageBox::warning(this, QString::fromLocal8Bit("�N�x!"), QString::fromLocal8Bit("�¤�N�x!"));
            }
        }

        roundSec = 30;
        this->timeUpdate();
    }
}

// �}�Ҹ�Ƨ��A���Log�ɸ��|
void Chinese_Chess::FindLogPath()
{
    QString filePath = QFileDialog::getOpenFileName(this, "a...", "*.txt");
    if (filePath.isEmpty())
    {
        return;
    }
    else
    {
        // �N���|�ഫ��string
        QByteArray tempData = filePath.toLocal8Bit();
        logPath = std::string(tempData);
    }
}