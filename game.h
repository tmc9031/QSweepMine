#ifndef GAME_H
#define GAME_H

#include "playfield.h"

enum GameState
{
    GAME_READY, //0
    GAME_GO,    //1
    GAME_WIN,   //2
    GAME_OVER   //3
};

//ÓÎÏ·×´Ì¬
class Game
{
public:
        Game();
        static void DestroyInstance();
        static Game *GetIstance();
        PlayField& GetPlayField();
        int GetState();
        int SetState(int new_state);
        void Customize(int w,int h,int m);

private:
        int m_state;
        PlayField pf;
        static Game *m_instance;
};


#endif // GAME_H
