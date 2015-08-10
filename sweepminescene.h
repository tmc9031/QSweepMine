#ifndef SWEEPMINESCENE_H
#define SWEEPMINESCENE_H

#include <QGraphicsScene>
#include <QPixmap>
#include "cellitem.h"

using namespace std;

typedef vector<CellItem*> ItemColumn;//ָ��* �����Զ��帴�ƹ��캯��
typedef vector<ItemColumn> ItemMatrix;

//��������
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
    int m_num;  //ɨ�׼�����
    ItemMatrix m_item;
};

#endif // SWEEPMINESCENE_H
