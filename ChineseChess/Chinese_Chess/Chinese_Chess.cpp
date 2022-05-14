#include "Chinese_Chess.h"

Chinese_Chess::Chinese_Chess(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

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
    connect(ui.pushButton_Print, SIGNAL(clicked()), this, SLOT(on_pushButton_Print_onclicked()));
}

//���s��������
void Chinese_Chess::on_pushButton_Start_onclicked()
{
    ui.stackedWidget->setCurrentIndex(1);
}

//���s��������
void Chinese_Chess::on_pushButton_Back_onclicked()
{
    ui.stackedWidget->setCurrentIndex(0);
}

//���s���}
void Chinese_Chess::on_pushButton_Exit_onclicked()
{
    this->close();
}

//���s�L�X
void Chinese_Chess::on_pushButton_Print_onclicked()
{
    //Board test;
    ui.page_1->update();
}

//�ƥ�L�o��
bool Chinese_Chess::eventFilter(QObject* obj, QEvent* eve)
{
    //�ƹ��I��
    if (eve->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(eve);
        QString temp = QString::number(mouseEvent->x()) + " " + QString::number(mouseEvent->y());
        ui.textBrowser->setText(temp);
        return true;
    }
    //ø�Ϩƥ�
    else if(eve->type()== QEvent::Paint)
    {
        prints();
        //ui.textBrowser->setText(ui.textBrowser->toPlainText() + "a");
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
    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            painter.drawImage(QRect(10 + column * 100, 8 + row * 80, 80, 64), QImage(":/chess/Chessimg/red0.png"));
        }
    }
}