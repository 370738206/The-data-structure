/*
验证用二叉树(P183)
ABD**EG***CF*H***
ABCE**F**DG**H***
*/

#include <stdio.h>
#include <stdlib.h>


//二叉链表类型定义 字符型数据+左右孩子
typedef struct btnode
{
    char data;
    struct btnode *lchild,*rchild;
} bitree,*Bitree;


//链队列类型定义 +指针域 用于入队出队
typedef struct LinkQueueNode
{
    bitree *data;
    struct LinkQueueNode *next;
} LKQueNode;


//定义队列 +队头队尾指针域 判断队列非空
typedef struct LKQueue
{
    LKQueNode *front,*rear;
} LKQue;


//初始化队列
void InitQueue(LKQue *LQ)
{
    LKQueNode *p;
    p = (LKQueNode*)malloc(sizeof(LKQueNode));
    LQ->front = p;              //不带头节点的链式队列
    LQ->rear = p;
    LQ->front->next = NULL;
}


//判断队列是否为空
int EmptyQueue(LKQue *LQ)
{
    if(LQ->front == LQ->rear)
        return 1;
    else
        return 0;
}


//入队列，将x入队
void EnQueue(LKQue *LQ,Bitree x)
{
    LKQueNode *p;
    p = (LKQueNode*)malloc(sizeof(LKQueNode));
    p->data = x;
    p->next = NULL;
    LQ->rear->next = p;
    LQ->rear = p;
}


//出队列
int OutQueue(LKQue *LQ, Bitree p)
{
    LKQueNode *s;
    if ( EmptyQueue(LQ))//判断非空
    {
        exit(0);
        return 0;
    }
    else
    {
        s = LQ->front->next;
        LQ->front->next = s->next;
        if(s->next == NULL)//队列已空
            LQ->rear = LQ->front;
        free(s);
        printf("%c",p->data); //输出是char
        return 1;
    }

}


//取队列首元素，返回值将队首元素带回
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


//建二叉树
Bitree Initiate()
{
    char ch;
    Bitree t;
    ch = getchar();
    if(ch == '*')
        t = NULL;//无效字符,树指向空
    else
    {
        t = (Bitree)malloc(sizeof(bitree));
        t->data = ch;
        t->lchild = Initiate();//递归
        t->rchild = Initiate();
    }
    return t;
}


//树的深度
int height(Bitree t)
{
    int ld,rd;
    if(t == NULL)
        return 0;
    else
    {
        ld = height(t->lchild);//递归
        rd = height(t->rchild);
        return  (ld>rd?ld:rd) + 1;//不加1的话返回0会使程序状态得不到准确判断
    }
}


//层次遍历
/*
二叉树的层序遍历算法如下：
（1）初始化设置一个队列；
（2）把根结点指针入队列；
（3）当队列非空时，循环执行步骤（3.a）到步骤（3.c）；
    （3.a）出队列取得一个结点指针，访问该结点；
    （3.b）若该结点的左子树非空，则将该结点的左子树指针入队列；
    （3.c）若该结点的右子树非空，则将该结点的右子树指针入队列；
（4）结束。
*/
void LevelOrder(Bitree bt)
{
    LKQue Q;
    Bitree p;
    InitQueue(&Q);//初始化一个队列
    if(bt != NULL)//二叉树非空
    {
        EnQueue(&Q,bt);//入队列
        while(!EmptyQueue(&Q))
        {
            p = GetHead(&Q);//取队头元素，出队列并输出
            OutQueue(&Q, p);
            if(p->lchild != NULL)
                EnQueue(&Q,p->lchild);//树非空则循环
            if(p->rchild != NULL)
                EnQueue(&Q,p->rchild);
        }
    }
}


int main()
{
    Bitree T;
    printf("按先序序列输入结点序列，'*'代表空:");
    T=Initiate();

    printf("\n二叉树的深度为:%d\n",height(T) - 1);

    printf("\n层次遍历序列为:");
    LevelOrder(T);
    printf("\n\n");
}
