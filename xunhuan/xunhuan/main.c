//
//  main.c
//  xunhuan
//
//  Created by GOD on 2018/5/9.
//  Copyright © 2018年 GOD. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MaxStackSize 100
typedef int DataType;
#include "LinStack.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int i,x;
    LQueue Q;
    QueueInitiate(&Q);
    for(i=0;i<10;i++)
    {
        QueueAppend(&Q,i+1);
    }
//    QueueGet(&Q,&x);
//    printf("%d\n",x);
    while(QueueNotEmpty(&Q))
    {
        QueueDelete(&Q,&x);
        printf("%d ",x);
    }
    printf("%s",QueueNotEmpty(&Q)==0?"空":"不空");
    Destroy(&Q);
    printf("%s",QueueNotEmpty(&Q)==0?"空":"不空");
    
}
