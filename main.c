/*
��֤�ö�����(P183)
ABD**EG***CF*H***
ABCE**F**DG**H***
*/

#include <stdio.h>
#include <stdlib.h>


//�����������Ͷ��� �ַ�������+���Һ���
typedef struct btnode
{
    char data;
    struct btnode *lchild,*rchild;
} bitree,*Bitree;


//���������Ͷ��� +ָ���� ������ӳ���
typedef struct LinkQueueNode
{
    bitree *data;
    struct LinkQueueNode *next;
} LKQueNode;


//������� +��ͷ��βָ���� �ж϶��зǿ�
typedef struct LKQueue
{
    LKQueNode *front,*rear;
} LKQue;


//��ʼ������
void InitQueue(LKQue *LQ)
{
    LKQueNode *p;
    p = (LKQueNode*)malloc(sizeof(LKQueNode));
    LQ->front = p;              //����ͷ�ڵ����ʽ����
    LQ->rear = p;
    LQ->front->next = NULL;
}


//�ж϶����Ƿ�Ϊ��
int EmptyQueue(LKQue *LQ)
{
    if(LQ->front == LQ->rear)
        return 1;
    else
        return 0;
}


//����У���x���
void EnQueue(LKQue *LQ,Bitree x)
{
    LKQueNode *p;
    p = (LKQueNode*)malloc(sizeof(LKQueNode));
    p->data = x;
    p->next = NULL;
    LQ->rear->next = p;
    LQ->rear = p;
}


//������
int OutQueue(LKQue *LQ, Bitree p)
{
    LKQueNode *s;
    if ( EmptyQueue(LQ))//�жϷǿ�
    {
        exit(0);
        return 0;
    }
    else
    {
        s = LQ->front->next;
        LQ->front->next = s->next;
        if(s->next == NULL)//�����ѿ�
            LQ->rear = LQ->front;
        free(s);
        printf("%c",p->data); //�����char
        return 1;
    }

}


//ȡ������Ԫ�أ�����ֵ������Ԫ�ش���
Bitree GetHead(LKQue *LQ)
{
    LKQueNode *p;
    bitree *q;
    if(EmptyQueue(LQ))
        return q;
    else
    {
        p = LQ->front->next;
        return p->data;
    }
}


//��������
Bitree Initiate()
{
    char ch;
    Bitree t;
    ch = getchar();
    if(ch == '*')
        t = NULL;//��Ч�ַ�,��ָ���
    else
    {
        t = (Bitree)malloc(sizeof(bitree));
        t->data = ch;
        t->lchild = Initiate();//�ݹ�
        t->rchild = Initiate();
    }
    return t;
}


//�������
int height(Bitree t)
{
    int ld,rd;
    if(t == NULL)
        return 0;
    else
    {
        ld = height(t->lchild);//�ݹ�
        rd = height(t->rchild);
        return  (ld>rd?ld:rd) + 1;//����1�Ļ�����0��ʹ����״̬�ò���׼ȷ�ж�
    }
}


//��α���
/*
�������Ĳ�������㷨���£�
��1����ʼ������һ�����У�
��2���Ѹ����ָ������У�
��3�������зǿ�ʱ��ѭ��ִ�в��裨3.a�������裨3.c����
    ��3.a��������ȡ��һ�����ָ�룬���ʸý�㣻
    ��3.b�����ý����������ǿգ��򽫸ý���������ָ������У�
    ��3.c�����ý����������ǿգ��򽫸ý���������ָ������У�
��4��������
*/
void LevelOrder(Bitree bt)
{
    LKQue Q;
    Bitree p;
    InitQueue(&Q);//��ʼ��һ������
    if(bt != NULL)//�������ǿ�
    {
        EnQueue(&Q,bt);//�����
        while(!EmptyQueue(&Q))
        {
            p = GetHead(&Q);//ȡ��ͷԪ�أ������в����
            OutQueue(&Q, p);
            if(p->lchild != NULL)
                EnQueue(&Q,p->lchild);//���ǿ���ѭ��
            if(p->rchild != NULL)
                EnQueue(&Q,p->rchild);
        }
    }
}


int main()
{
    Bitree T;
    printf("�������������������У�'*'�����:");
    T=Initiate();

    printf("\n�����������Ϊ:%d\n",height(T) - 1);

    printf("\n��α�������Ϊ:");
    LevelOrder(T);
    printf("\n\n");
}
