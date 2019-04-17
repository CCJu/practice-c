//
//  main.c
//  test1
//
//  Created by GOD on 2018/4/11.
//  Copyright © 2018年 GOD. All rights reserved.
//

#include <stdio.h>
#define MaxSize 10
typedef int DataType;
typedef struct Stack{
    DataType array[MaxSize];
    int top;
}SeqStack;
void ClearStack(SeqStack *s){
    s->top=0;
}
int StackSize(SeqStack s){
    return s.top;
}
int main(){
    SeqStack s;
    int i=0;
    for(;i<10;i++)
        s.array[i]=i;
    s.top=10;
    //ClearStack(&s);
    printf("%d",StackSize(s));
    return 0;
}
