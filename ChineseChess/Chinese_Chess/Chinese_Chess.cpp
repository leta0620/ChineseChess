#include "Chinese_Chess.h"

Chinese_Chess::Chinese_Chess(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    //³]©w­I´º(´Ñ½L)
    QPixmap bkgnd(":/image/Chess_Board.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    QWidget* tempWidget = ui.stackedWidget->widget(1);
    tempWidget->setPalette(palette);

    ui.page_1->installEventFilter(this);

    
    bkgnd.load(":/image/Desert.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    //QPalette palettee;
    palette.setBrush(QPalette::Background, bkgnd);
    tempWidget = ui.stackedWidget->widget(0);
    tempWidget->setPalette(palette);
    

    connect(ui.pushButton_Start, SIGNAL(clicked()), this, SLOT(on_pushButton_Start_onclicked()));
    connect(ui.pushButton_Back, SIGNAL(clicked()), this, SLOT(on_pushButton_Back_onclicked()));
    connect(ui.pushButton_Exit, SIGNAL(clicked()), this, SLOT(on_pushButton_Exit_onclicked()));
}

//«ö¶s¤Á´«­¶­±
void Chinese_Chess::on_pushButton_Start_onclicked()
{
    ui.stackedWidget->setCurrentIndex(1);
}

//«ö¶s¤Á´«­¶­±
void Chinese_Chess::on_pushButton_Back_onclicked()
{
    ui.stackedWidget->setCurrentIndex(0);
}

//«ö¶sÂ÷¶}
void Chinese_Chess::on_pushButton_Exit_onclicked()
{
    this->close();
}

bool Chinese_Chess::eventFilter(QObject* obj, QEvent* eve)
{
    if (eve->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(eve);
        QString temp = QString::number(mouseEvent->x()) + " " + QString::number(mouseEvent->y());
        ui.textBrowser->setText(temp);
        return true;
    }
    else
    {
        return false;
    }
}