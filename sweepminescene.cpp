#include "sweepminescene.h"

#include "game.h"

#include <QMessageBox>

void SweepMineScene::ClearSweepMineScene()
{
    int x;
    int y;

    for(x=0; x<w; x++)
    {
            for(y=0; y<h; y++)
            {
                removeItem(m_item[x][y]);
                //不remove的话，将来还会用QGraphicsItem * item指针找图片，导致野指针
                delete m_item[x][y];
                m_item[x][y]=NULL;
            }
    }

    m_item.clear();

    w = 0;
    h = 0;

    m_num = 0;
}

void SweepMineScene::CustomizeSweepMineScene()
{
    ClearSweepMineScene();

    NewSweepMineScene();
}

SweepMineScene::SweepMineScene(QObject *parent) :
    QGraphicsScene(parent),
    m_item(0)
{
    NewSweepMineScene();
}

void SweepMineScene::NewSweepMineScene()
{
    w = Game::GetIstance()->GetPlayField().GetWidth();
    h = Game::GetIstance()->GetPlayField().GetHeight();

    m_num = 0;

    int x;
    int y;

    //=QPixmap(":/cellitem/init.bmp").height();
    //Q:如何动态获得图片size？
    //QPixmap pic;

    for(x=0; x<w; x++)
    {
            m_item.push_back(ItemColumn(h));
            for(y=0; y<h; y++)
            {
                    m_item[x][y]= new CellItem();
                    //Q:在哪里delete呢？ A:~SweepMineScene()
                    //sz=pic.height();
                    static qreal sz_h=m_item[x][y]->boundingRect () .height();
                    static qreal sz_w=m_item[x][y]->boundingRect () .width();
                    m_item[x][y]->setPos(x*sz_w,y*sz_h);
                    m_item[x][y]->setx(x);
                    m_item[x][y]->sety(y);
                    addItem(m_item[x][y]);
                    //虽然scene包含item，但是在绘图上的关系还需addItem来建立
            }
    }
}

void SweepMineScene::RestartSweepMineScene()
{
    ClearSweepMineScene();

    NewSweepMineScene();

//    int i;
//    int j;

//    m_num = 0;

//    for(i=0; i<w; i++)
//        for(j=0; j<h; j++)
//        {
//              m_item[i][j]->setPixmap(QPixmap(":/cellitem/init.bmp"));
//              m_item[i][j]->m_init=0;
//              m_item[i][j]->m_flag=0;
//        }
}

SweepMineScene::~SweepMineScene()
{
    int x;
    int y;

    for(x=0; x<w; x++)
    {
            for(y=0; y<h; y++)
            {
                removeItem(m_item[x][y]);
                //不remove的话，将来还会用QGraphicsItem * item指针找图片，导致野指针
                delete m_item[x][y];
                m_item[x][y]=NULL;
            }
    }
}

void SweepMineScene::Sweep(int x,int y)
{
    int i;
    int j;

    if(m_item[x][y]->m_init == 0)
    {
        int num = Game::GetIstance()->GetPlayField().GetCells(x,y);
        switch(num)
        {
            case -1:
                    for(i=0; i<w; i++)
                        for(j=0; j<h; j++)
                            if(Game::GetIstance()->GetPlayField().GetCells(i,j) == -1)
                            {
                                if(m_item[i][j]->m_flag == 0)
                                {
                                      m_item[i][j]->setPixmap(QPixmap(":/cellitem/mine.png"));
                                      m_item[i][j]->m_init=1;
                                }
                                else
                                {
                                      m_item[i][j]->setPixmap(QPixmap(":/cellitem/mine_flag.png"));
                                      m_item[i][j]->m_init=1;
                                }
                            }
                            else
                            {
                                if(m_item[i][j]->m_flag == 1)
                                {
                                  m_item[i][j]->setPixmap(QPixmap(":/cellitem/flag_err.bmp"));
                                  m_item[i][j]->m_init=1;
                                }
                            }
                    for(i=0; i<w; i++)
                        for(j=0; j<h; j++)
                            m_item[i][j]->m_init=1;

                    Game::GetIstance()->SetState(GAME_OVER);
                    QMessageBox::information(NULL,"GameState","GAME_OVER!!!",QMessageBox::Ok);
                    break;
            case 0:
                    m_item[x][y]->setPixmap(QPixmap(":/cellitem/0.bmp"));
                    m_item[x][y]->m_init=1;
                    m_num++;

                    for(i=x-1; i<=x+1; i++)
                        for(j=y-1; j<=y+1; j++)
                            if(!(i==-1||i==w || j==-1||j==h))
                                if(m_item[i][j]->m_init == 0)
                                    if(m_item[i][j]->m_flag == 0)
                                        Sweep(i,j);
                    break;
            case 1:m_item[x][y]->setPixmap(QPixmap(":/cellitem/1.bmp"));m_item[x][y]->m_init=1;m_num++; break;
            case 2:m_item[x][y]->setPixmap(QPixmap(":/cellitem/2.bmp"));m_item[x][y]->m_init=1;m_num++; break;
            case 3:m_item[x][y]->setPixmap(QPixmap(":/cellitem/3.bmp"));m_item[x][y]->m_init=1;m_num++; break;
            case 4:m_item[x][y]->setPixmap(QPixmap(":/cellitem/4.bmp"));m_item[x][y]->m_init=1;m_num++; break;
            case 5:m_item[x][y]->setPixmap(QPixmap(":/cellitem/5.bmp"));m_item[x][y]->m_init=1;m_num++; break;
            case 6:m_item[x][y]->setPixmap(QPixmap(":/cellitem/6.bmp"));m_item[x][y]->m_init=1;m_num++; break;
            case 7:m_item[x][y]->setPixmap(QPixmap(":/cellitem/7.bmp"));m_item[x][y]->m_init=1;m_num++; break;
            case 8:m_item[x][y]->setPixmap(QPixmap(":/cellitem/8.bmp"));m_item[x][y]->m_init=1;m_num++; break;
            default:break;
        }
    }

    if(m_num == w*h-Game::GetIstance()->GetPlayField().GetMine())
    {
        m_num = 0;

        for(i=0; i<w; i++)
            for(j=0; j<h; j++)
                m_item[i][j]->m_init=1;

        Game::GetIstance()->SetState(GAME_WIN);
        QMessageBox::information(NULL,"GameState","YOU_WIN!!!",QMessageBox::Ok);
    }
    return;
}

