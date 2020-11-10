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


//������ɫ
void setcolor(int color)
{
    HANDLE
    hc=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hc,0|color);
}

//�����·�������
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

//Ѱ����·����������(��������)
void findroute(int i,int j)
{
    if(i==10&&j==8)//�ҵ��յ�
    {
        printroute();
    }
    else if(maze[1][0]==1&&maze[0][1]==1)//����޷�����
    {
        printf("No Way1!\n");
    }
    else
    {
        if(maze[i][j+1]!=1&&maze[i][j+1]!=2)//��
        {
            maze[i][j]=2;//��2��Ϊ��·�ı�־
            j++;
            findroute(i,j);//�ݹ�
            j--;//����
            maze[i][j]=0;
        }
        else if(maze[i+1][j]!=1&&maze[i+1][j]!=2)//��
        {
            maze[i][j]=2;
            i++;
            findroute(i,j);
            i--;
            maze[i][j]=0;
        }
        else if(maze[i][j-1]!=1&&maze[i][j-1]!=2)//��
        {
            maze[i][j]=2;
            j--;
            findroute(i,j);
            j++;
            maze[i][j]=0;
        }
        else if(maze[i-1][j]!=1&&maze[i-1][j]!=2)//��
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
