//
//  main.c
//  TREE
//
//  Created by GOD on 2018/5/12.
//  Copyright © 2018年 GOD. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef  char DataType;
#include "tree.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    char *c="ABD##EF###C#G##";
    BinaryTree *bt;
    creatTree(&bt);
    showByFront(bt);
    printf("\n");
    showByMiddle(bt);
    printf("\n");
    showByBehind(bt);
    int i;
    numberOfLeaves(bt, &i);
    
    printf("\n%d\n",i);
    
    DataList dl,*d;
    dl.top=0;
    dl.num=0;
    int ii=0;
    for(;ii<100;ii++)
        dl.array[ii]=NULL;
    d=&dl;
    //isCompleteBinaryTree(bt, d);
    //printf("\n");
    print(bt, d);
    printf("\n");
    prin(bt);
    return 0;
}
