#ifndef SWEEPMINEAPP_H
#define SWEEPMINEAPP_H

#include <QApplication>

//扫雷游戏主程序控制
class SweepMineApp : public QApplication
{
    Q_OBJECT
public:
    explicit SweepMineApp(int argc, char *argv[]);
    ~SweepMineApp();

signals:

public slots:

};

#endif // SWEEPMINEAPP_H
