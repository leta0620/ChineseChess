#include "Chinese_Chess.h"
#include "Pos.h"

void Chinese_Chess::CallGameOver()
{
    gameRound = true;
    gameRun.GameOver();
    gameRun.boardGM.AllSet();
    gameRun.viewer.paintout();
}

void Chinese_Chess::CallGameStart()
{
    gameRun.ResetGame();
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
    bkgnd.load(":/image/Desert.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, bkgnd);
    tempWidget = ui.stackedWidget->widget(0);
    tempWidget->setPalette(palette);

    //�w�˹L�o��
    ui.page_1->installEventFilter(this);

    //�s�����s�P�ƥ�
    connect(ui.pushButton_Start, SIGNAL(clicked()), this, SLOT(on_pushButton_Start_onclicked()));
    connect(ui.pushButton_Back, SIGNAL(clicked()), this, SLOT(on_pushButton_Back_onclicked()));
    connect(ui.pushButton_Exit, SIGNAL(clicked()), this, SLOT(on_pushButton_Exit_onclicked()));
    connect(ui.pushButton_Surrender, SIGNAL(clicked()), this, SLOT(on_pushButton_Surrender_onclicked()));

    // �]�w�C���һ��ܼ�
    this->gameRound = true;

    //GameOver gm = new GameOver;

    connect(&gm, SIGNAL(sendSel(bool)), this, SLOT(receiveSel(bool)));
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
    // �j����o���C���Aclose Log��
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
    gm.SendResult(gameRun.GetGamePlayer());
    gm.show();
    this->CallGameOver();
    /*
    if (gameRun.GetGamePlayer())
        ui.textBrowser->setText(QString::fromLocal8Bit("�¤����"));
    else
        ui.textBrowser->setText(QString::fromLocal8Bit("�������"));
    */
}

void Chinese_Chess::receiveSel(bool sel)
{
    // �p�n���s�@���A�O�o�g
    this->CallGameStart();
    if (sel)
        ui.textBrowser->setText(QString::fromLocal8Bit("�¤����!"));
    else
        ui.textBrowser->setText(QString::fromLocal8Bit("�������!"));
    gm.hide();

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
        if (gameRun.GetGamePlayer())
            ui.label_3->setText(QString::fromLocal8Bit("����^�X"));
        else
            ui.label_3->setText(QString::fromLocal8Bit("�¤�^�X"));
        return true;
    }
    //ø�Ϩƥ�
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
                    if(legalPos[a]==tmp)
                        painter.drawImage(QRect(10 + column * 100, 8 + row * 80, 80, 64), QImage(":/image/Chessimg/toMove.png"));
                }
            }
        }
    }
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
        if (win == 1)
        {
            // ���C������ĵ�ܮءA����ӧQ�A�������a��ܪ�^�ܥD�e�� or ���s�}�l�@��
            ui.textBrowser->setText("Red win");

            this->CallGameOver();
            return;
        }
        else if (win == 2)
        {
            // ���C������ĵ�ܮءA�¤�ӧQ�A�������a��ܪ�^�ܥD�e�� or ���s�}�l�@��
            ui.textBrowser->setText("Black win");

            this->CallGameOver();
            return;
        }

        // �P�_�N�x
        int willWin = gameRun.WillWin();
        if (willWin == 1)
        {
            // ������N�xĵ�ܮ�
            ui.textBrowser->setText("Red will win");

        }
        else if (willWin == 2)
        {
            // ���¤�N�xĵ�ܮ�
            ui.textBrowser->setText("Black will win");

        }
    }
}