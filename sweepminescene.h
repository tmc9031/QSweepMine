#ifndef SWEEPMINESCENE_H
#define SWEEPMINESCENE_H

#include <QGraphicsScene>
#include <QPixmap>
#include "cellitem.h"

using namespace std;

typedef vector<CellItem*> ItemColumn;//指针* 避免自定义复制构造函数
typedef vector<ItemColumn> ItemMatrix;

//雷区画布
class SweepMineScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit SweepMineScene(QObject *parent = 0);
    ~SweepMineScene();
    void Sweep(int x,int y);
    void CustomizeSweepMineScene();
    void ClearSweepMineScene();
    void NewSweepMineScene();
    void RestartSweepMineScene();

signals:

public slots:

protected:
    int w;
    int h;
    int m_num;  //扫雷计数器
    ItemMatrix m_item;
};

#endif // SWEEPMINESCENE_H
