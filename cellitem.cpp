#include "cellitem.h"

#include "game.h"

#include "sweepminescene.h"

CellItem::CellItem()
    :QGraphicsPixmapItem()
    ,m_flag(0)
    ,m_init(GAME_READY)

{
    setPixmap(QPixmap(":/cellitem/init.bmp"));
}

void CellItem::mousePressEvent ( QGraphicsSceneMouseEvent *event )
{
    static int game_start;
    if(++game_start == GAME_GO)
        Game::GetIstance()->SetState(GAME_GO);

//    int x=0;
//    int y=0;

    if(m_init == 1)
        return;

    switch(event->button())
    {
        case Qt::LeftButton:
            if(m_flag == 0)
            {
                ((SweepMineScene*)scene())->Sweep(m_x,m_y);
            }
            break;

        case Qt::RightButton:
            if(m_flag == 0)
            {
                setPixmap(QPixmap(":/cellitem/flag.bmp"));
                m_flag=1;
            }
            else
            {
                setPixmap(QPixmap(":/cellitem/init.bmp"));
                m_flag=0;
            }
            break;

        defualt:break;
    }
}

void CellItem::setx(int temp_x)
{
    m_x=temp_x;
    return;
}

void CellItem::sety(int temp_y)
{
    m_y=temp_y;
    return;
}

int CellItem::GetX()
{
    return m_x;
}

int CellItem::GetY()
{
    return m_y;
}
