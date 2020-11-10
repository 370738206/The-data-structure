/*����Թ����·�����䳤�ȡ�
�Ա�����Ľⷨ���ڳɹ����ҵ�һ����������ȥ��·��֮��ͻ��˳���
�����ǿ��Խ�·�����浽��һ��ջpath[]�У�
���������minlen���������·�����ȡ�
�� whileѭ��������ʱ�����path[]����̵�·����
*/
#include<stdio.h>
#include <windows.h>
#define M 10		//10��
#define N 10		//10��

//������ɫ
void setcolor(int color)
{
    HANDLE
    hc=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hc,0|color);
}

struct
{
    int i;				//��ǰ��
    int j;				//��ǰ��
    int dir;				//��һ������
} st[1000], path[1000];			//����ջ

int top = -1;			//��ʼ��ջ��ָ��
int count = 1;			//��ʼ��������
int minlen = 1000;	    //��ʼ�����·������


int maze[M + 2][N + 2] = 		//Ҫ�󣺻�����ֻ���ƶ���û���ϰ����λ�ã����ұ��������Թ��ڡ�
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

void printfroute()//��ʱ�ľ���Ԫ���Ѿ��ı�
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
    int i, j, dir, flag, k;
    top++;			//���λ����ջ ָ��,x,y,dir
    st[top].i = x1;		//�к�
    st[top].j = y1;		//�к�
    st[top].dir = -1;	//��һ��ķ���
    maze[x1][y1] = -1;	//�����Ϊ-1������֮������һ�Σ���������ı�־

    while(top > -1)		//ջ����ʱ��ѭ������
    {
        i = st[top].i;  //ȡջ������Ԫ��
        j = st[top].j;
        dir = st[top].dir;  //dirȡֵ��ͬʵ��Ѱ�����·��

        if(i == x2 && j == y2)		//˵���Ѿ��ҵ��˳��ڡ���С�ڵ�ǰ���·�����ȣ���·����ջ�������ջ
        {
            if(top + 1 < minlen)    //top��-1��ʼ��·������Ӧ�ü�1
            {
                for(k = 0; k <= top; k++)
                    path[k] = st[k];		//��ǰջ��Ԫ������ѹ����ʱջ�У���ջ��
                minlen = top + 1;			//ջ��ָ���Ӧ
            }
            maze[st[top].i][st[top].j] = 0;	//�þ������±�Ϊ����·�����ߣ���ջ��
            top--;
            i = st[top].i;
            j = st[top].j;
            dir = st[top].dir;
        }

        flag = 0;   //��ʼѰ��·��
        while(flag == 0 && dir < 4)			//Ѱ����һ�����ߵķ���
        {
            dir++;
            switch(dir)
            {
            case 0:
                i = st[top].i - 1;
                j = st[top].j;
                break;		//������
            case 1:
                i = st[top].i;
                j = st[top].j + 1;
                break;		//������
            case 3:
                i = st[top].i + 1;
                j = st[top].j;
                break;		//������
            case 2:
                i = st[top].i;
                j = st[top].j - 1;
                break;		//������
            }
            if(maze[i][j] == 0)
                flag = 1;//Ѱ��·���ɹ�
        }
        if(flag == 1)				//�ҵ�����һ�����ߵķ���
        {
            st[top].dir = dir;		//�����ڵ�λ����ջ ջ��ָ��,x,y,dir�ı�
            top++;
            st[top].i = i;
            st[top].j = j;
            st[top].dir = -1;		//���޸�֮����޷��ж�ȫ������
            maze[i][j] = -1;		//���߹���·����Ϊ-1������֮������һ��;��������ı�־
        }

        else		//û��·������ջ�����ݣ�
        {
            maze[st[top].i][st[top].j] = 0;		//�ø�λ�ñ�Ϊ����·������
            top--;								//ջ��ָ������
        }
    }


    if(minlen == 1000 && st[top].i == 0 && st[top].j == 0)  //����ڶ���ջ����û�����ݣ���˵��û��·������
        printf("û��·������");

    else
    {
        printf("���·���ĳ���Ϊ:  %d\n", minlen);
        printf("���·��Ϊ��\n");
        for(k = 0; k < minlen; k++)
        {
            int m, n;
            m = path[k].i;
            n = path[k].j;
            maze[m][n]=-1;
        }
        printfroute();//�ı�λ�ÿ��Դ�ӡÿһ��
    }
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
