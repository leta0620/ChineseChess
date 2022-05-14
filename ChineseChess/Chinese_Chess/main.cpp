#include "Chinese_Chess.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chinese_Chess w;
    w.show();
    //固定視窗大小
    //w.setFixedSize(QSize(1200, 800));
    return a.exec();
}
