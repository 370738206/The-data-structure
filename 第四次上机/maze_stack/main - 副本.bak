#include<stdio.h>
#include <windows.h>
#define M 10			    //10行
#define N 10			    //10列

struct
{
    int i;				//当前行
    int j;				//当前列
    int dir;			//下一步方向(0123-右下左上)
} st[1000];			    //定义栈

int top = -1;			//初始化栈顶指针

static int maze[M + 2][N + 2] = 		//要求：机器人只能移动到没有障碍物的位置，并且必须留在迷宫内。
{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1},
    {1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

//控制颜色
void setcolor(int color)
{
    HANDLE
    hc=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hc,0|color);
}

void printfroute()
{
    for(int i=0; i<12; i++)
    {
        for(int j=0; j<12; j++)
        {
            if(maze[i][j]==1)
            {
                setcolor(7);
                printf(" 1 ");
            }
            if(maze[i][j]==0)
            {
                setcolor(7);
                printf("   ");
            }
            if(maze[i][j]==-1)
            {
                setcolor(3);
                printf(" X ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

//0是路,1是墙
void findroute(int x1, int y1, int x2, int y2)
{
    int i, j, dir, find;
    top++;			//初始化方块进栈
    st[top].i = x1;		//行号
    st[top].j = y1;		//列号
    st[top].dir = -1;	//下一块的方位
    maze[x1][y1] = -1;	//起点置为-1,避免之后再走一次;当作输出的标志

    while(top > -1)		//栈不空时，循环继续
    {
        i = st[top].i;
        j = st[top].j;  //起点开始
        dir = st[top].dir;

        if(i == x2 && j == y2)		//说明已经找到了出口，直接输出路径
        {
            printf("迷宫路径如下:\n");
            printfroute();
            return;
        }

        find = 0;
        while(find == 0 && dir < 4)			//判断下一步方向
        {
            dir++;  //初值为-1
            switch(dir)
            {
            case 0:
                i = st[top].i;
                j = st[top].j + 1;
                break;		//向右走
            case 1:
                i = st[top].i + 1;
                j = st[top].j;
                break;		//向下走
            case 2:
                i = st[top].i;
                j = st[top].j - 1;
                break;		//向左走
            case 3:
                i = st[top].i - 1;
                j = st[top].j;
                break;		//向上走
            }
            if(maze[i][j] == 0)		//如果找到了通路，就不用再进行上面的循环了
                find = 1;
        }

        if(find == 1)				//找到方向
        {
            st[top].dir = dir;		//修改之前栈顶元素中di的值
            top++;					//下一步坐标进栈,栈顶指针上移
            st[top].i = i;
            st[top].j = j;
            st[top].dir = -1;		//不修改之后会无法判断全部方向
            maze[i][j] = -1;			//将走过的路径设为-1，避免之后再走一次;当作输出的标志
        }

        else		//没有路径就退栈,即回溯
        {
            maze[st[top].i][st[top].j] = 0;		//让该位置变为其他路径可走的方块
            top--;								//栈顶指针下移
        }
    }
    printf("没有可走路径");
}


int main()
{
    int x1, y1, x2, y2;
    printf("请输入起点坐标:\n");
    scanf("%d%d", &x1, &y1);
    printf("请输入终点坐标:\n");
    scanf("%d%d", &x2, &y2);
    findroute(x1, y1, x2, y2);
    return 0;
}
