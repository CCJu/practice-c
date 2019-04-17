//
//  main.c
//  hello
//
//  Created by GOD on 2018/3/21.
//  Copyright © 2018年 GOD. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char DataType;
typedef struct Node{
    DataType c;
    struct Node *next;
}SLNode;
void init(SLNode **p){
    *p=(SLNode *)malloc(sizeof(SLNode));
    (*p)->c='z';
    (*p)->next=NULL;
}
void insert(SLNode **p,char c){
    if(c<'a') return;
    SLNode *cc=(SLNode *)malloc(sizeof(SLNode));
    cc->c=c;
    cc->next=*p;
    *p=cc;
    //free(cc);
    insert(p, c-1);
}
void show(SLNode *p){
    while(p->next!=NULL){
        printf("%c\n",p->c);
        p=p->next;
    }
    printf("%c\n",p->c);
}
void delete(SLNode **p,int i){
    int n=0;
    if(i==1){
        *p=(*p)->next;
    }else{
        while((*p)->next!=NULL) {
            n++;
            if(n==i-1)break;
            *p=(*p)->next;
        }
        (*p)->next=(*p)->next->next;
    }
}
void destory(SLNode **p){
    SLNode *pp;
    while ((*p)->next!=NULL) {
        pp=*p;
        (*p)=(*p)->next;
        free(pp);
    }
    *p=NULL;
}
void Move(SLNode **p){
    SLNode *p0=(*p)->next,*t;
    (*p)->next=NULL;
    while (p0->next!=NULL) {
        t=p0->next;
        p0->next=(*p);
        (*p)=p0;
        p0=t;
    }
    p0->next=(*p);
    (*p)=p0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //SLNode *p = NULL;
    //init(&p);
    //insert(&p, 'y');
    //delete(&p, 1);
    //destory(&p);
    //Move(&p);
    //show(p);
    //if(p==NULL)
      //  printf("删除完毕");
    char *c[2][2];
    return 0;
}
