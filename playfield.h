#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <QSettings>

#define LEN 10

using namespace std;

typedef vector<int> CellColumn;
typedef vector<CellColumn> CellMatrix;

//游戏雷区信息
class PlayField
{
public:
    PlayField();
    ~PlayField();
    void Print() const;
    int GetHeight() const;
    int GetWidth() const;
    int GetMine() const;
    int GetCells(int i,int j) const;
    void Customize(int w,int h,int m);
    void ClearPlayField();
    void NewPlayField();
    void RestartPlayField();

private:
        QSettings m_settings;
        int m_height;
        int m_width;
        int m_mine;
        CellMatrix m_cells;
};

#endif // PLAYFIELD_H
