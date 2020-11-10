/*输出迷宫最短路径及其长度。
对比上面的解法，在成功的找到一条可以走下去的路径之后就会退出；
那我们可以将路径保存到另一个栈path[]中，
并定义变量minlen来保存最短路径长度。
当 while循环结束的时候输出path[]中最短的路径。
*/
#include<stdio.h>
#include <windows.h>
#define M 10		//10行
#define N 10		//10列

//控制颜色
void setcolor(int color)
{
    HANDLE
    hc=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hc,0|color);
}

struct
{
    int i;				//当前行
    int j;				//当前列
    int dir;				//下一步方向
} st[1000], path[1000];			//定义栈

int top = -1;			//初始化栈顶指针
int count = 1;			//初始化计数器
int minlen = 1000;	    //初始化最短路径长度


int maze[M + 2][N + 2] = 		//要求：机器人只能移动到没有障碍物的位置，并且必须留在迷宫内。
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

void printfroute()//此时的矩阵元素已经改变
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
    int i, j, dir, flag, k;
    top++;			//起点位置入栈 指针,x,y,dir
    st[top].i = x1;		//行号
    st[top].j = y1;		//列号
    st[top].dir = -1;	//下一块的方向
    maze[x1][y1] = -1;	//起点置为-1，避免之后再走一次；当作输出的标志

    while(top > -1)		//栈不空时，循环继续
    {
        i = st[top].i;  //取栈顶数据元素
        j = st[top].j;
        dir = st[top].dir;  //dir取值不同实现寻找最短路径

        if(i == x2 && j == y2)		//说明已经找到了出口。若小于当前最短路径长度，则将路径入栈；否则出栈
        {
            if(top + 1 < minlen)    //top从-1开始，路径长度应该加1
            {
                for(k = 0; k <= top; k++)
                    path[k] = st[k];		//当前栈中元素依次压入临时栈中（入栈）
                minlen = top + 1;			//栈顶指针对应
            }
            maze[st[top].i][st[top].j] = 0;	//让矩阵重新变为其他路径可走（出栈）
            top--;
            i = st[top].i;
            j = st[top].j;
            dir = st[top].dir;
        }

        flag = 0;   //开始寻找路径
        while(flag == 0 && dir < 4)			//寻找下一个可走的方向
        {
            dir++;
            switch(dir)
            {
            case 0:
                i = st[top].i - 1;
                j = st[top].j;
                break;		//向上走
            case 1:
                i = st[top].i;
                j = st[top].j + 1;
                break;		//向右走
            case 3:
                i = st[top].i + 1;
                j = st[top].j;
                break;		//向下走
            case 2:
                i = st[top].i;
                j = st[top].j - 1;
                break;		//向左走
            }
            if(maze[i][j] == 0)
                flag = 1;//寻找路径成功
        }
        if(flag == 1)				//找到了下一个可走的方向
        {
            st[top].dir = dir;		//将现在的位置入栈 栈顶指针,x,y,dir改变
            top++;
            st[top].i = i;
            st[top].j = j;
            st[top].dir = -1;		//不修改之后会无法判断全部方向
            maze[i][j] = -1;		//将走过的路径设为-1，避免之后再走一次;当作输出的标志
        }

        else		//没有路径就退栈（回溯）
        {
            maze[st[top].i][st[top].j] = 0;		//让该位置变为其他路径可走
            top--;								//栈顶指针下移
        }
    }


    if(minlen == 1000 && st[top].i == 0 && st[top].j == 0)  //如果第二个栈里面没有数据，则说明没有路径可走
        printf("没有路径可走");

    else
    {
        printf("最短路径的长度为:  %d\n", minlen);
        printf("最短路径为：\n");
        for(k = 0; k < minlen; k++)
        {
            int m, n;
            m = path[k].i;
            n = path[k].j;
            maze[m][n]=-1;
        }
        printfroute();//改变位置可以打印每一步
    }
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
