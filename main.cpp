#include <QtGui/QApplication>
#include "mainwindow.h"

#include "sweepmineapp.h"
#include "game.h"
#include "playfield.h"

int main(int argc, char *argv[])
{
    SweepMineApp a(argc, argv);
    MainWindow w;
    w.show();
    //��ģ̬�Ի����show����

    return a.exec();
    //model dialogģ̬�Ի����exec������Ϣ��
}
