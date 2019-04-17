//
//  Header.h
//  xunhuan
//
//  Created by GOD on 2018/5/9.
//  Copyright © 2018年 GOD. All rights reserved.
//

#ifndef Header_h
#define Header_h

typedef struct qnode
{
    DataType data;
    struct qnode *next;
}LQNode;

typedef struct
{
    LQNode *rear;
    int count;
}LQueue;

void QueueInitiate(LQueue *Q)
{
    Q->rear=(LQNode *)malloc(sizeof(LQNode));
    Q->rear->next=Q->rear;
    Q->count=0;
}
void QueueAppend(LQueue *Q,DataType x)
{
    LQNode *p;
    p=(LQNode *)malloc(sizeof(LQNode));
    p->data=x;
    p->next=Q->rear->next;
    Q->rear->next=p;
    Q->rear=p;
    Q->count++;
}

void QueueDelete(LQueue *Q,DataType *d)
{
    LQNode *p;
    if(Q->rear->next==Q->rear)
    {
        printf("不能删除");
        return;
    }
    p=Q->rear->next->next;
    *d=p->data;
    Q->rear->next->next=p->next;
    Q->count--;
//    free(p);
    if(Q->rear==p)
    {
//        Q->rear->next=Q->rear->next->next;
//        Q->rear=Q->rear->next;
//        free(p);
        LQNode *t= Q->rear->next->next;
        Q->rear->next->next=Q->rear->next;
        Q->rear=Q->rear->next;
        Q->count--;
        free(t);
    }
}
int QueueGet(LQueue *Q,DataType *d)
{
    if(Q->count==0)
    {
        printf("为空");
        return 0;
    }
    else
    {
        *d=Q->rear->next->next->data;
        return 1;
    }
}

int QueueNotEmpty(LQueue *Q)
{
    if(Q->count!=0)
        return 1;
    else
        return 0;
}

void Destroy(LQueue *Q)
{
    LQNode *p,*p1;
    p=Q->rear->next;
    Q->rear->next=NULL;
    while(p!=NULL)
    {
        p1=p;
        p=p->next;
        free(p1);
    }
}


#endif /* Header_h */
