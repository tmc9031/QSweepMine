#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "game.h"
#include "optiondialog.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setScene(&m_scene);
    //ָ�����봰�����ͼview�����ڻ���scene
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_NewGame_triggered()
{   
    Game::GetIstance()->SetState(GAME_READY);

    Game::GetIstance()->GetPlayField().RestartPlayField();

    m_scene.RestartSweepMineScene();
}

void MainWindow::on_Option_triggered()
{
    PlayField& pf = Game::GetIstance()->GetPlayField();

    OptionDialog dig(pf.GetWidth(),pf.GetHeight(),pf.GetMine(),this);

    //model window ��exec()��Ϣ��
    if(dig.exec() == QDialog::Rejected)
        return;

//    //unmodel window ��show()������ע��model windowҲ����ʹ�õģ�������Ϣ��Ӧ������owner������Ϣ��exec()����
//    dig.show();

    Game::GetIstance()->Customize(dig.m_width,dig.m_height,dig.m_mine);

    m_scene.CustomizeSweepMineScene();

}//own window with owner window , not parent and child relationship

void MainWindow::on_about_triggered()
{
    QMessageBox::information(NULL,"About Game","SweepMine_V1.0 Author:TMC",QMessageBox::Ok);
}

void MainWindow::on_Quit_triggered()
{
    close();
}
