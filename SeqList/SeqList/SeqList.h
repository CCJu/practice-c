//
//  SeqList.h
//  SeqList
//
//  Created by GOD on 2018/4/18.
//  Copyright © 2018年 GOD. All rights reserved.
//

#ifndef SeqList_h
#define SeqList_h

#include <stdio.h>
typedef struct {
    DataType d[MaxSize];
    int size;
}Seq;
void insert(Seq *p,int location,DataType a){
    if(p->size==10){
        printf("不能插入，线性表已满");
    }else{
        int size=p->size;
        if(size-1<location)
            p->d[size]=a;
        else{
            int t=p->d[location],i;
            p->d[location]=a;
            for(i=size-1;i>location;i--)
                p->d[i+1]=p->d[i];
            p->d[location+1]=t;
        }
        p->size++;
    }
}
void del(Seq *p,int location){
    int size=p->size;
    if(location>size-1||location<0)
        printf("越界");
    else{
        int i=location+1;
        if(location!=size-1)
            for(;i<size-1;i++)
                p->d[i-1]=p->d[i];
        p->size--;
    }
}
void show(Seq p){
    int size=p.size,i=0;
    for(;i<size;i++){
        printf("%d",p.d[i]);
    }
}
void Move(Seq *p){
    int i=0,j=p->size-1;
    for(;i<j;i++,j--){
        int t=p->d[i];
        p->d[i]=p->d[j];
        p->d[j]=t;
    }
}
void update(Seq *p,int location,DataType a){
    int size=p->size;
    if(location>size-1||location<0)
        printf("越界");
    else{
        p->d[location]=a;
    }
    
}


#endif /* SeqList_h */
