#include "Chinese_Chess.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chinese_Chess w;
    w.show();
    return a.exec();
}
