#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#if(0)
static int maze[10][10]=
{
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
};
#endif

#if(1)
static int maze[10][10]=
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
#endif


//控制颜色
void setcolor(int color)
{
    HANDLE
    hc=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hc,0|color);
}

//输出线路（结果）
void printroute()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(maze[i][j]==1)
            {
                setcolor(7);
                printf(" O ");
            }
            if(maze[i][j]==0)
            {
                setcolor(7);
                printf("   ");
            }
            if(maze[i][j]==2)
            {
                setcolor(3);
                printf(" X ");
            }
        }
        printf("\n");
    }
}

//寻找线路：右下左上(右下上左)
void findroute(int i,int j)
{
    if(i==10&&j==8)//找到终点
    {
        printroute();
    }
    else if(maze[1][0]==1&&maze[0][1]==1)//入口无法进入
    {
        printf("No Way1!\n");
    }
    else
    {
        if(maze[i][j+1]!=1&&maze[i][j+1]!=2)//右
        {
            maze[i][j]=2;//将2作为线路的标志
            j++;
            findroute(i,j);//递归
            j--;//回溯
            maze[i][j]=0;
        }
        else if(maze[i+1][j]!=1&&maze[i+1][j]!=2)//下
        {
            maze[i][j]=2;
            i++;
            findroute(i,j);
            i--;
            maze[i][j]=0;
        }
        else if(maze[i][j-1]!=1&&maze[i][j-1]!=2)//左
        {
            maze[i][j]=2;
            j--;
            findroute(i,j);
            j++;
            maze[i][j]=0;
        }
        else if(maze[i-1][j]!=1&&maze[i-1][j]!=2)//上
        {
            maze[i][j]=2;
            i--;
            findroute(i,j);
            i++;
            maze[i][j]=0;
        }
        else
            printf("No Way2!\n");
    }
}

int main()
{
    findroute(0,1);
}
