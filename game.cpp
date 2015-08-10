#include "game.h"


Game *Game::m_instance=NULL;

Game::Game()
:m_state(GAME_READY)
{}

void Game::DestroyInstance()
{
    if(m_instance){
        delete m_instance;
        m_instance=NULL;
    }
}

Game *Game::GetIstance()
{
        if(!m_instance)
                m_instance = new Game();
        return m_instance;
}

PlayField& Game::GetPlayField()
{
        return pf;
}

int Game::GetState()
{
    return m_state;
}

int Game::SetState(int new_state)
{
    m_state=new_state;
    return m_state;
}

void Game::Customize(int w,int h,int m)
{
    m_state=GAME_READY;

    Game::GetIstance()->GetPlayField().Customize(w,h,m);
}
