#include "playfield.h"


void PlayField::ClearPlayField()
{
    m_cells.clear();

    m_width = 0;
    m_height = 0;
    m_mine = 0;
}

void PlayField::Customize(int w,int h,int m)
{
    ClearPlayField();

    m_width = w;
    m_height = h;
    m_mine = m;

    NewPlayField();
}

PlayField::PlayField()
    :m_settings("Mycompany","SweepMine")
    ,m_height(m_settings.value("m_height",3).toInt())
    ,m_width(m_settings.value("m_width",4).toInt())
    ,m_mine(m_settings.value("m_mine",2).toInt())
    ,m_cells(0)
{
    NewPlayField();
}

void PlayField::NewPlayField()
{
        int n;
        int i,j;
        int x,y;

        //赋初始值
        for(i=0; i<m_width; i++)
        {
            m_cells.push_back(CellColumn(m_height));
            for(j=0; j<m_height; j++)
                m_cells[i][j] = 0;
        }

        for(i=0; i<m_height; i++)
        {
                for(j=0; j<m_width; j++)
                        printf("%2d ",m_cells[j][i]);
//			cout << m_cells[i][j] << " ";
                cout << endl;
        }

        srand((int)time(0));

        for(n=0; n<m_mine; n++)
        {
                x=rand() % m_width;
                y=rand() % m_height;
                printf("x:%d y:%d\n",x,y);
                if(m_cells[x][y]==-1)
                {
                        n--;
                        continue;
                }
                else
                {
                        for(i=x-1; i<=x+1; i++)
                                for(j=y-1; j<=y+1; j++)
                                {
                                        if(i==x && j==y)
                                                m_cells[x][y]=-1;
                                        else
                                        {
                                                if(!(i==-1||i==m_width || j==-1||j==m_height))
                                                        if(m_cells[i][j]!=-1)
                                                                m_cells[i][j]++;
                                        }
                                }
                }
                for(i=0; i<m_height; i++)
                {
                        for(j=0; j<m_width; j++)
                                printf("%2d ",m_cells[j][i]);
        //			cout << m_cells[i][j] << " ";
                        cout << endl;
                }
        }
}

PlayField::~PlayField()
{
    m_settings.setValue("m_height",m_height);
    m_settings.setValue("m_width",m_width);
    m_settings.setValue("m_mine",m_mine);
}

void PlayField::Print() const //const after func mean:
{
        int i,j;

        for(i=0; i<m_height; i++)
        {
                for(j=0; j<m_width; j++)
                        printf("%2d ",m_cells[j][i]);
//			cout << m_cells[i][j] << " ";
                cout << endl;
        }
}

void PlayField::RestartPlayField()
{
    int n;
    int i,j;
    int x,y;

    //重新赋初始值
    for(i=0; i<m_width; i++)
    {
        for(j=0; j<m_height; j++)
            m_cells[i][j]=0;
    }

    for(i=0; i<m_height; i++)
    {
            for(j=0; j<m_width; j++)
                    printf("%2d ",m_cells[j][i]);
    //			cout << m_cells[i][j] << " ";
            cout << endl;
    }

    srand((int)time(0));

    for(n=0; n<m_mine; n++)
    {
            x=rand() % m_width;
            y=rand() % m_height;
            printf("x:%d y:%d\n",x,y);
            if(m_cells[x][y]==-1)
            {
                    n--;
                    continue;
            }
            else
            {
                    for(i=x-1; i<=x+1; i++)
                            for(j=y-1; j<=y+1; j++)
                            {
                                    if(i==x && j==y)
                                            m_cells[x][y]=-1;
                                    else
                                    {
                                            if(!(i==-1||i==m_width || j==-1||j==m_height))
                                                    if(m_cells[i][j]!=-1)
                                                            m_cells[i][j]++;
                                    }
                            }
            }
            for(i=0; i<m_height; i++)
            {
                    for(j=0; j<m_width; j++)
                            printf("%2d ",m_cells[j][i]);
    //			cout << m_cells[i][j] << " ";
                    cout << endl;
            }
    }
}

int PlayField::GetHeight() const
{
    return m_height;
}

int PlayField::GetWidth() const
{
    return m_width;
}

int PlayField::GetMine() const
{
    return m_mine;
}

int PlayField::GetCells(int i,int j) const
{
    return m_cells[i][j];
}
