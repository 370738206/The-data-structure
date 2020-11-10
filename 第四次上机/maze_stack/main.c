#include<stdio.h>
#include <windows.h>
#define M 10			    //10��
#define N 10			    //10��

struct
{
    int i;				//��ǰ��
    int j;				//��ǰ��
    int dir;			//��һ������(0123-��������)
} st[1000];			    //����ջ

int top = -1;			//��ʼ��ջ��ָ��

static int maze[M + 2][N + 2] = 		//Ҫ�󣺻�����ֻ���ƶ���û���ϰ����λ�ã����ұ��������Թ��ڡ�
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

//������ɫ
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

//0��·,1��ǽ
void findroute(int x1, int y1, int x2, int y2)
{
    int i, j, dir, find;
    top++;			//��ʼ�������ջ
    st[top].i = x1;		//�к�
    st[top].j = y1;		//�к�
    st[top].dir = -1;	//��һ��ķ�λ
    maze[x1][y1] = -1;	//�����Ϊ-1,����֮������һ��;��������ı�־

    while(top > -1)		//ջ����ʱ��ѭ������
    {
        i = st[top].i;
        j = st[top].j;  //��㿪ʼ
        dir = st[top].dir;

        if(i == x2 && j == y2)		//˵���Ѿ��ҵ��˳��ڣ�ֱ�����·��
        {
            printf("�Թ�·������:\n");
            printfroute();
            return;
        }

        find = 0;
        while(find == 0 && dir < 4)			//�ж���һ������
        {
            dir++;  //��ֵΪ-1
            switch(dir)
            {
            case 0:
                i = st[top].i;
                j = st[top].j + 1;
                break;		//������
            case 1:
                i = st[top].i + 1;
                j = st[top].j;
                break;		//������
            case 2:
                i = st[top].i;
                j = st[top].j - 1;
                break;		//������
            case 3:
                i = st[top].i - 1;
                j = st[top].j;
                break;		//������
            }
            if(maze[i][j] == 0)		//����ҵ���ͨ·���Ͳ����ٽ��������ѭ����
                find = 1;
        }

        if(find == 1)				//�ҵ�����
        {
            st[top].dir = dir;		//�޸�֮ǰջ��Ԫ����di��ֵ
            top++;					//��һ�������ջ,ջ��ָ������
            st[top].i = i;
            st[top].j = j;
            st[top].dir = -1;		//���޸�֮����޷��ж�ȫ������
            maze[i][j] = -1;			//���߹���·����Ϊ-1������֮������һ��;��������ı�־
        }

        else		//û��·������ջ,������
        {
            maze[st[top].i][st[top].j] = 0;		//�ø�λ�ñ�Ϊ����·�����ߵķ���
            top--;								//ջ��ָ������
        }
    }
    printf("û�п���·��");
}


int main()
{
    int x1, y1, x2, y2;
    printf("�������������:\n");
    scanf("%d%d", &x1, &y1);
    printf("�������յ�����:\n");
    scanf("%d%d", &x2, &y2);
    findroute(x1, y1, x2, y2);
    return 0;
}
