#include "sweepmineapp.h"

#include "game.h"

SweepMineApp::SweepMineApp(int argc, char *argv[]) :
    QApplication(argc,argv)
{
    Game::GetIstance();//->GetPlayField().Print();
}

SweepMineApp::~SweepMineApp()
{
    Game::DestroyInstance();
}

