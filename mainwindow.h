#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "sweepminescene.h"

namespace Ui {
    class MainWindow;
}

//主窗口
class MainWindow : public QMainWindow
{
    Q_OBJECT//宏标志表示继承自QObject类，且可使用“信号&槽”的机制

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_NewGame_triggered();
    void on_Option_triggered();
    void on_about_triggered();
    void on_Quit_triggered();

private:
    SweepMineScene m_scene;
    Ui::MainWindow *ui;
};

//Qpianter缺点
//1.被绘制的图形没有被抽象成类
//2.难以实现图形间的叠加和包含的关系
//3.获取用户事件是以窗口为单位，而非图形---需要根据坐标计算
//4.需显式调用Qpianter::draw 来绘制图形

#endif // MAINWINDOW_H
