#ifndef CELLITEM_H
#define CELLITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

enum CellItemState
{
    ITEM_INIT,  //0
    ITEM_DONE   //1
};

//»­²¼ÔªËØ
class CellItem : public QGraphicsPixmapItem
{
public:
    CellItem();
    void setx(int temp_x);
    void sety(int temp_y);
    int GetX();
    int GetY();

protected:
     virtual void mousePressEvent ( QGraphicsSceneMouseEvent * event );

protected:
    int m_x;
    int m_y;

public:
    int m_flag;
    int m_init;
};

#endif // CELLITEM_H
