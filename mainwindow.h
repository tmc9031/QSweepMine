#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "sweepminescene.h"

namespace Ui {
    class MainWindow;
}

//������
class MainWindow : public QMainWindow
{
    Q_OBJECT//���־��ʾ�̳���QObject�࣬�ҿ�ʹ�á��ź�&�ۡ��Ļ���

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

//Qpianterȱ��
//1.�����Ƶ�ͼ��û�б��������
//2.����ʵ��ͼ�μ�ĵ��ӺͰ����Ĺ�ϵ
//3.��ȡ�û��¼����Դ���Ϊ��λ������ͼ��---��Ҫ�����������
//4.����ʽ����Qpianter::draw ������ͼ��

#endif // MAINWINDOW_H
