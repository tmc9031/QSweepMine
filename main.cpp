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
    //非模态对话框的show函数

    return a.exec();
    //model dialog模态对话框的exec函数消息泵
}
