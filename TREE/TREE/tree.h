//
//  tree.h
//  TREE
//
//  Created by GOD on 2018/5/12.
//  Copyright © 2018年 GOD. All rights reserved.
//

#ifndef tree_h
#define tree_h
static int nodeNum=0;
typedef struct node{
    struct node *left;
    struct node *right;
    DataType data;
}BinaryTree;

typedef struct List{
    BinaryTree *array[100];
    int top;
    int num;
}DataList;

void creatTree(BinaryTree **bt){
    char cc=getchar();
    if(cc!='#'){
        nodeNum++;
        *bt=(BinaryTree *)malloc(sizeof(BinaryTree));
        (*bt)->data=cc;
        (*bt)->left=NULL;
        (*bt)->right=NULL;
        creatTree(&(*bt)->left);
        creatTree(&(*bt)->right);
    }
}

void showByFront(BinaryTree *bt){
    if(bt!=NULL){
        printf("%c",bt->data);
        showByFront(bt->left);
        showByFront(bt->right);
    }
}

void showByMiddle(BinaryTree *bt){
    if(bt!=NULL){
        showByMiddle(bt->left);
        printf("%c",bt->data);
        showByMiddle(bt->right);
    }
}

void showByBehind(BinaryTree *bt){
    if(bt!=NULL){
        showByBehind(bt->left);
        showByBehind(bt->right);
        printf("%c",bt->data);

    }
}

void numberOfLeaves(BinaryTree *bt,int *i){
    if(bt==NULL) return;
    if(bt->left==NULL&&bt->right==NULL)
        (*i)++;
    numberOfLeaves(bt->left,i);
    numberOfLeaves(bt->right,i);
}

void add(DataList **dl,BinaryTree *bt){
    if((*dl)->top<100)
        (*dl)->array[(*dl)->top]=bt;
    (*dl)->top++;
}

BinaryTree * getNum(DataList *dl){
    return dl->array[dl->num];
}

void print(BinaryTree *bt,DataList *dl){
    int nn=0;
    add(&dl, bt);
    nn++;
    BinaryTree *t;
    while(nn!=nodeNum){
        t=getNum(dl);
        dl->num++;
        add(&dl, t->left);
        if(t->left!=NULL) nn++;
        add(&dl, t->right);
        if(t->right!=NULL) nn++;
    }
    int layer=1;
    for(;;layer++)
        if(pow(2, layer)>=dl->top)break;
    int i=1,j=0;
    for(;i<=layer;i++){
        //输出空格
        int blankNum=0;
        int blankLimit=(pow(3, layer-i)-1)/2;
        for(;blankNum<blankLimit;blankNum++)
            printf(" ");
        //输出数据
        int dataNum=0;
        int dataLimit=j+pow(2, i-1)>dl->top?dl->top:j+pow(2, i-1);
        for(;j<dataLimit;j++){
            if(dl->array[j]==NULL)
                printf("^");
            else
                printf("%c",dl->array[j]->data);
            dataNum++;
            if(dataNum!=2){
                //输出每个数据的间隔
                int nb=0;
                for(;nb<4*blankLimit+1;nb++)
                    printf(" ");
            }else{
                int nb=0;
                for(;nb<8*blankLimit+3;nb++)
                    printf(" ");
            }
        }
        printf("\n");

    }
}

void isCompleteBinaryTree(BinaryTree *bt,DataList *dl){
    add(&dl, bt);
    BinaryTree *t;
    while(1){
        if((t=getNum(dl))==NULL) break;
        add(&dl, t->left);
        add(&dl, t->right);
        dl->num++;
    }
    int i=dl->num;
    for(;i<dl->top;i++){
        if(dl->array[i]!=NULL){printf("不是"); return ;}
    }
    printf("是");
    
}
void prin(BinaryTree *bt){
    if(bt!=NULL){
        printf("(");
        printf("%c",bt->data);
        prin(bt->left);
        if(bt->right!=NULL)printf(",");
        prin(bt->right);
        printf(")");
    }
}
#endif /* tree_h */
